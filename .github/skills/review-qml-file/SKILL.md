---
name: review-qml-file
description: "Review a QML file for broken bindings, JavaScript syntax errors, binding loops, and property type mismatches."
disable-model-invocation: true
argument-hint: "QML file path (optional; defaults to the current QML file)"
---
Review the specified QML file: $input

If no file path is supplied, use the QML file currently open or selected in the editor context. If no target can be identified, ask the user which QML file to review before proceeding.

Inspect the whole target file and only the directly related project declarations needed to verify its bindings and types, such as referenced QML components, `Q_PROPERTY` declarations, enums, and model roles. Follow the repository's Qt/QML version and conventions. Do not modify files.

Check for:

1. **Broken bindings** — unresolved identifiers or object references, invalid property names, unavailable properties/signals, incorrect binding expressions, and cases where imperative assignments may replace or disable a binding. Verify against declarations where possible; distinguish confirmed problems from items that need runtime verification.
2. **JavaScript syntax errors** — inspect JavaScript expressions and function bodies for syntax errors, including malformed statements, delimiters, and invalid control flow. Do not report stylistic concerns as syntax errors.
3. **Binding loops** — trace dependencies between properties and report direct or indirect cycles. Explain the dependency chain and identify whether the cycle is certain or only a possible runtime loop.
4. **Type mismatches** — compare each binding's result with the declared property or receiving property's actual type, including QML built-in types, enums, model roles, and C++ `Q_PROPERTY` types when available. Flag incompatible conversions (for example, a string assigned to an integer); do not flag valid implicit conversions without a concrete compatibility concern.

Return findings first in a table with columns: **#**, **Category**, **File and line**, **Finding**, **Evidence / dependency chain**, and **Confidence**. Use precise line numbers and quote only short relevant expressions. If there are no findings, say so explicitly. After the table, briefly list any checks that could not be confirmed statically and what runtime/build diagnostic would verify them. Do not guess at missing declarations or treat speculative issues as confirmed.
