# Project Guidelines

## Qt and C++

- Target Qt 5.15.2 and use C++17, the newest standard supported by this Qt baseline. Keep changes compatible with the project's configured Qt modules and supported compiler.
- For qmake projects, enable C++17 with `CONFIG += c++17` where needed. Follow the existing qmake project structure.
- Follow applicable MISRA C++ guidelines and project conventions. Prefer defined, deterministic behavior; use explicit conversions and types, avoid unsafe casts and hidden side effects, and document justified deviations. Do not claim formal MISRA compliance unless it is checked against an agreed rule set.
- Use smart pointers for dynamically managed C++ ownership where appropriate. Avoid raw owning pointers; use Qt parent-child ownership for `QObject` instances when that is the established lifecycle model, and do not combine competing ownership mechanisms.
- Preserve Qt idioms, including signals and slots, and take care with `QObject` lifetimes, thread affinity, and Qt implicit sharing.

## QML / Qt Quick

- Keep QML files declarative and view-focused; put reusable logic and stateful behavior in C++ or proper Qt model objects instead of embedding complex logic directly in UI files.
- Keep QML imports and versions compatible with Qt 5.15.2. Prefer `QtQuick 2.15` and standard Qt Quick components already used by the project; avoid introducing incompatible Qt 6-only APIs or extra dependencies.
- Use property bindings and validated state changes rather than imperative side effects in UI code. Keep object graphs shallow, avoid deep nesting when a simpler C++/model layer will be clearer, and prefer existing patterns in the project over ad hoc abstractions.
- Expose data to QML through `QObject`/`Q_PROPERTY` and model types rather than exposing raw internal C++ state or cross-thread access. Preserve ownership and signal semantics across the QML/C++ boundary.
- Maintain consistent naming and component structure across QML files, and keep user-visible strings localized with `qsTr()` or `qsTranslate()` when appropriate.
- When loading dynamic content, prefer lightweight `Loader` usage and avoid unnecessary object churn. Keep resource paths in the Qt resource system (`qrc:/...`) rather than relying on filesystem paths.

## Persistence

- Use SQLite for new persistent application data. In Qt, use the Qt SQL module with the SQLite (`QSQLITE`) driver and parameterized queries; do not build SQL by concatenating untrusted or variable input.
- Handle database open, query, and transaction errors explicitly, and keep schema changes and persistence behavior covered by tests where practical.

## Build and Tests

- Use the repository's qmake project files and existing `Tests` target. Inspect the project configuration and available Qt 5.15.2 toolchain before choosing build or test commands; do not assume a particular kit or platform.
- Add or update tests for behavior changes and run the narrowest relevant tests, followed by the available build or test target.
