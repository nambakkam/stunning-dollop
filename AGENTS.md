# AGENTS.md

## Project Overview

This repository contains a Qt application demonstrating C++ concepts, design patterns, QML, and data structures. The application uses qmake, Qt Quick, and a C++ backend exposed to QML. The root `stunning-dollop.pro` builds the application and the `Tests` subproject.

The documented baseline in `.github/copilot-instructions.md` is Qt 5.15.2 and C++17. Existing local build artifacts may have been produced with a different Qt kit; do not treat those artifacts as the supported baseline. Inspect the active kit and preserve the documented compatibility target.

## Project Structure

- `AllConceptsProject/`: application C++ sources, QML screens and components, and the QML resource collection.
- `Tests/`: Qt Test-based C++ unit tests.
- `AllConceptsProject/QtSuperMacros/`: shared Qt helper library included by the qmake projects.
- `.github/`: Copilot instructions, skills, prompts, and custom agent profiles.

Prefer the existing C++ model/controller patterns for stateful behavior and keep QML declarative and focused on presentation. QML files are packaged through the Qt resource system.

## Setup and Build

Use a Qt installation with the repository's configured modules and a matching compiler/build tool. In Qt Creator, open `stunning-dollop.pro`, select the appropriate Qt kit, configure, and build the root subdirs project.

For a command-line build, run qmake from an out-of-source build directory and use the make tool generated for the selected kit:

```powershell
New-Item -ItemType Directory -Force build | Out-Null
Set-Location build
qmake ..\stunning-dollop.pro
mingw32-make
```

Use the kit's corresponding build tool instead of `mingw32-make` when using a different compiler (for example, `nmake` for an MSVC kit). Keep generated build outputs out of source directories.

## Testing

Tests use Qt Test (`QtTest`) and live in `Tests/`. Add or update focused tests for behavior changes, following the existing `*test.cpp` naming and Qt Test conventions.

To build and run the test target from an out-of-source directory with a MinGW kit:

```powershell
New-Item -ItemType Directory -Force build-tests | Out-Null
Set-Location build-tests
qmake ..\Tests\Tests.pro
mingw32-make
.\Tests.exe
```

Use the equivalent make tool and executable form for the active kit/platform. Prefer the narrowest relevant test first, then build the root project when changes affect application integration or QML.

## Implementation Guidelines

- Follow `.github/copilot-instructions.md` and the established code patterns before introducing new abstractions or dependencies.
- Keep C++ compatible with C++17 and the documented Qt 5.15.2 baseline. Enable C++17 in qmake projects where needed.
- Keep QML imports compatible with Qt Quick 2.15; use `qsTr()` or `qsTranslate()` for user-facing text.
- Preserve Qt ownership, signal/slot, model, and thread-affinity semantics. Avoid raw owning pointers.
- Use explicit validation and error reporting; do not silently hide failures.
- Keep changes surgical and update directly related tests and documentation.

## Verification and Reporting

Run the relevant tests and builds after implementation. Report the exact commands run and their outcomes, and distinguish verified behavior from any checks that could not be run in the available Qt environment. Do not claim a test or interactive QML check passed unless it was actually performed.
