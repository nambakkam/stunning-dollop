---
name: mvc-architecture
description: "Build Qt Quick applications with a read-only model exposed to the view and a controller responsible for all model changes."
---
When implementing or refactoring a Qt application to separate its view and data, use this Model-View-Controller structure. Follow the repository's Qt version, build system, naming, and ownership conventions; for projects following this repository's guidance, target Qt 5.15.2 and C++17.

## Responsibilities

- **Model:** Store and present application data through `QAbstractListModel` for a list or `QAbstractTableModel` for tabular data. Implement `rowCount()`, `data()`, and appropriate role definitions (`roleNames()` for named QML roles). Keep model mutation in C++; do not make mutation methods callable from QML.
- **Controller:** A `QObject` that owns or safely references the model and exposes validated user operations as `Q_INVOKABLE` methods or public slots. The controller performs all inserts, updates, and removals by calling the model's C++ methods. Report invalid operations explicitly through a result, error property/signal, or the project's established error mechanism.
- **View:** QML used for presentation and input. Read from the exposed model and invoke controller operations for changes. Do not assign to model roles, call model mutation methods, or embed application data-management logic in delegates.

## Implementation guidance

1. Inspect the existing project structure, QML imports, Qt version, model/controller patterns, ownership, and build/test setup before editing. Reuse existing conventions and keep changes scoped to the requested feature.
2. Create the appropriate `QAbstractListModel` or `QAbstractTableModel` subclass. Keep its storage private. Implement role-based reads, and use `beginInsertRows()`/`endInsertRows()`, `beginRemoveRows()`/`endRemoveRows()`, and `dataChanged` correctly for each mutation. Validate indexes and inputs at the model/controller boundary.
3. Give the controller a clear API for user actions (for example, `addItem(...)`, `updateItem(...)`, and `removeItem(...)`). Make model mutation entry points ordinary C++ methods, not `Q_INVOKABLE` or public slots. Keep controller logic out of QML.
4. Expose both objects to QML using the project's established mechanism, such as context properties created before loading the QML. Use distinct names, for example `appModel` and `appController`. Ensure object lifetimes and thread affinity remain valid for the QML engine; do not expose raw internal storage or create competing ownership.
5. Build the view declaratively with the existing Qt Quick components. Use `ListView` for a list, `TableView` for tabular data, or `Repeater` for a small repeated presentation. Bind the view's `model` to the read-only model and connect user actions to controller methods. Keep delegates focused on display and forwarding input.
6. Preserve Qt 5.15.2 compatibility when that is the project baseline. Prefer existing imports and APIs; do not introduce Qt 6-only APIs or new dependencies. For qmake projects, update the relevant project file when adding C++ files and retain the established C++ standard configuration.
7. Add or update focused tests for model roles, row/column counts, and controller-driven mutations where the project supports tests. Run the narrowest applicable test/build target and report any unavailable toolchain or unverified behavior.

## Boundary check

Before finishing, verify that:

- QML can read model roles and react to model notifications.
- QML can request changes only through the controller's validated API.
- The model does not expose a QML-callable way to mutate rows or cell values.
- Model notifications match each structural or data change so views stay synchronized.
- No application state or mutation rules were moved into the view.
