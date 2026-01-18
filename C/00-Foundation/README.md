# 🌱 00 - Foundations: The Systems Genesis

This directory represents the "First Bricks" of my journey into Systems Programming. It documents my transition from a Linux user to a C developer, focusing on the fundamental mechanics of the **GCC Toolchain**.

## 🏗️ The Build Philosophy
Unlike standard "Hello World" exercises, these foundations focus on **Multi-File Compilation** and **Linking**. 

### 📂 Milestone 01: Multi-File Input & Linkage
- **Objective:** To understand how the C Linker combines separate source files into a single functional unit.
- **Concepts:** Standard I/O (`stdio.h`), External function calls, and user-input handling.

### 📂 Milestone 02: Modular Build Architecture
- **Objective:** Implementing modularity in systems design. 
- **The "Topboy" Build:** A three-module system (`main`, `tee`, `usman`) linked via a custom Makefile.
- **Concepts:** Header management, automated build scripts, and modular logic separation.

---

## 🛠️ Artifacts of Compilation (Object Files)
You will notice `.o` (object files) and compiled binaries within these directories. 

**Why they are included:**
In a production environment, binaries are usually ignored. However, in this **Engineering Laboratory**, these files serve as **Technical Proof of Compilation**. They represent successful machine-code generation on my **Framework 13 (Fedora)** environment.

## 🚀 Key Takeaways:
1. **The Linker:** Understanding how the compiler turns `.c` files into `.o` object files before the linker creates the final executable.
2. **Vim Mastery:** All foundations were written and debugged using the Vim text editor.
3. **Automation:** The introduction of the `Makefile` to eliminate manual compilation overhead.
