# Uebung1 - ABK C++ Kurs

## Overview
This is a C++ learning repository for the ABK C++ course ("ABK-C++-Kurs"). It contains basic C++ exercises demonstrating fundamental concepts like console output and file I/O.

## Project Structure
- `hallo.cc` - Simple "Hello World" program demonstrating basic output
- `summieren.cc` - Program that reads number pairs from `daten.txt` and calculates statistics
- `daten.txt` - Data file containing number pairs for processing
- `Makefile` - Build configuration for compiling the C++ programs

## Programs

### hallo
A simple program that prints "Hallo Welt!" to the console.

**Compile:** `make hallo`  
**Run:** `./hallo`

### summieren
Reads pairs of numbers from `daten.txt` and calculates:
- Total count of number pairs
- Sum of all numbers
- Average value

**Compile:** `make summieren`  
**Run:** `./summieren`

## Build Instructions

### Compile all programs:
```bash
make all
```

### Compile individual programs:
```bash
make hallo
make summieren
```

### Clean build artifacts:
```bash
make clean
```

## Recent Changes
- 2025-10-22: Initial setup for Replit environment
  - Installed C++ toolchain (Clang)
  - Created basic C++ programs
  - Added Makefile for easy compilation
  - Configured workflow for building and running programs

## Development Environment
- Language: C++17
- Compiler: Clang++ 14
- Build System: Make
