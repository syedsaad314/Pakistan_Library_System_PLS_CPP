# 🏛️ National Library Management System (Pakistan Library System (PLS))

A high-performance, modular C++ application designed for large-scale library administration. This project demonstrates **Professional Software Architecture**, **Clean Code Principles**, and a **Sophisticated Terminal User Interface (TUI)**.

## 🌟 Overview
This system is built for high-traffic environments where data integrity and user experience are paramount. It moves away from "basic scripting" and utilizes a **Separation of Concerns** model, dividing the application into distinct Blueprints (`include/`) and Engines (`src/`).

## 🚀 Key Features

- **Inventory Management:** Full CRUD (Create, Read, Update, Delete) capabilities for library assets.
- **Student Portal Logic:** Secure borrowing and returning protocols with real-time status tracking.
- **Financial Module:** Automated query system for student financial records and late fees.
- **Professional TUI:** Interactive, color-coded terminal interface using ANSI escape sequences.
- **Simulated Latency:** Threaded "loading" sequences to mimic real-time cloud database synchronization.
- **Robust Input Handling:** Bulletproof validation to prevent system crashes from invalid user data.

## 📂 Project Architecture

To maintain "Enterprise" standards, the project follows a strict directory structure:

```text
Pakistan_Library_System_PLS_CPP/
├── include/            # [Blueprints & Definitions]
│   ├── Book.h          # Data structure for Library Assets
│   ├── User.h          # Data structure for Student Profiles
│   ├── UI.h            # Interface & Visual function declarations
│   └── LibraryEngine.h # Core Business Logic declarations
├── src/                # [Implementation Engines]
│   ├── UI.cpp          # Visual rendering & Terminal styling
│   └── LibraryEngine.cpp # Logic processing & Asset management
├── data/               # [Persistent Storage]
├── main.cpp            # Entry Point & Application Router
└── README.md           # Documentation
