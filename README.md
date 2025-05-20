# Bank-management-system

This repository contains a simple yet functional console-based banking system built in C++. It simulates core banking features like account creation, secure login, balance inquiry, deposit, withdrawal, and transaction history management. This project demonstrates the use of file handling, object-oriented design, and exception handling in C++.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [How to Run](#how-to-run)
- [Modules](#modules)
- [Files](#files)
- [Roadmap](#roadmap)
- [Contributing](#contributing)

---

## Features

- **Account Management**:
  - Create a new account with a unique account number.
  - Login with password authentication.
  - Account details persisted in `.txt` files.

- **Banking Operations**:
  - Deposit and withdraw money.
  - View current balance.
  - View full account information.

- **Transaction History**:
  - Maintains a record of all deposits and withdrawals.

- **File Handling**:
  - All user data is saved locally using standard file I/O.
  - Account number is generated using an incremented bank code from `Bank.txt`.

- **Colorful Output**:
  - Cross-platform terminal color output using a custom `COLOR.h`.

- **Error Handling**:
  - Input validation and exception handling for robust user experience.

---

## Prerequisites

- **Compiler**: A C++17 compatible compiler such as:
  - GCC / G++ (Linux)
  - MSVC / MinGW (Windows)
- **Environment**: Any terminal or IDE like Visual Studio, Code::Blocks, or g++ on Linux.
- **Files Needed**:
  - `BANKACCOUNT.h`, `BANKACCOUNT.cpp`, `COLOR.h`, `main.cpp`

---

