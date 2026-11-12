# stunning-dollop

A Qt Quick learning project that demonstrates core C++ data structures, algorithms, and application patterns in a single interactive desktop app.

This repository combines a QML front end with a C++ backend to visualize common concepts such as vectors, hash tables, unit systems, MVC item management, and MVVM task tracking.

## Overview

The app is organized as a set of interactive screens and model/controller components. It is designed for exploration and teaching, making it easy to see how underlying C++ logic maps to a user-facing Qt experience.

### Included demonstrations

- Vector operations with push, pop, insert, delete, and search interactions
- Hash table visualizer for add, remove, view, and key lookup flows
- Unit system demonstrator covering CGS, MKS, FPS, and SI conventions
- MVC-style item list with a controller and model-backed data updates
- MVVM-style task list with validation, task completion, and removal logic
- Qt Quick UI screens built with reusable components and resource-based assets

## Project structure

```text
stunning-dollop/
├── AllConceptsProject/
│   ├── AllConceptsProject.pro
│   ├── main.cpp
│   ├── main.qml
│   ├── qml.qrc
│   ├── *.qml                     # UI screens and reusable components
│   ├── *.cpp                    # C++ data-structure and model logic
│   ├── *.h                      # headers for handlers and models
│   └── QtSuperMacros/           # shared Qt helper macros and utilities
├── Tests/
│   ├── Tests.pro
│   ├── *.cpp                    # Qt Test coverage
│   └── *.h
├── AGENTS.md
├── README.md
├── stunning-dollop.pro
└── .github/
```

## Features

### Data structures and algorithms

The application exposes several C++ implementations behind Qt properties, making it easier to observe how data structure behavior is represented in the UI.

- Vector-based collection operations and complexity labels
- Hash table creation, insertion, deletion, and display behavior
- Model and view separation for list-driven screens
- Task management logic with MVVM bindings

### Qt and QML architecture

The project follows a simple Qt Quick structure:

- `main.qml` hosts the application shell
- `MainScreen.qml` switches between feature screens using a `StackLayout`
- reusable QML controls live in `StyledButton.qml` and related files
- C++ types are exposed to QML through `QQmlApplicationEngine::rootContext()`

## Prerequisites

- Qt 5.15.2 or a compatible Qt 5.x toolchain
- C++17 support enabled in the qmake project setup
- A working qmake + make/nmake toolchain for your platform

## Build

From the repository root, create an out-of-source build folder and configure the project:

```powershell
New-Item -ItemType Directory -Force build | Out-Null
Set-Location build
qmake ..\stunning-dollop.pro
mingw32-make
```

Use the matching build tool for your active Qt kit instead of `mingw32-make` when needed (for example `nmake` for an MSVC toolchain).

## Run the app

After building the project, launch the generated application from the build output directory or run it from Qt Creator with the root `stunning-dollop.pro` project open.

## Run tests

The repository includes Qt Test-based coverage under `Tests/`:

```powershell
New-Item -ItemType Directory -Force build-tests | Out-Null
Set-Location build-tests
qmake ..\Tests\Tests.pro
mingw32-make
.\Tests.exe
```

Use the matching executable name and toolchain for your current Qt kit.

## Screens

The app is centered around a multi-screen learning dashboard:

- Vectors screen: demonstrates collection operations and complexity trade-offs
- Hash Table screen: allows insert, delete, and display operations for a custom hash table
- Units Demonstrator: switches between unit systems and presents length, mass, and time units
- MVC Item List: adds and removes list items using a controller-backed workflow
- MVVM Task List: manages tasks through a model-view-viewmodel pattern

## Notes

This project is primarily educational and intentionally focused on exploring Qt, QML, and C++ programming concepts. It is a practical playground for understanding how data structures and UI patterns fit together in a desktop app.
