# Build & Verification Guide

This page explains how to build, test, and verify the CPU logic simulator using the GNU Makefile setup.

---

## 🛠 Compilation Requirements

* **C Compiler**: GCC or Clang (C11 standard)
* **Build System**: GNU Make

---

## 🚀 Execution Commands

Execute build rules from your terminal root directory:

```bash
# 1. Build the target executable binary
make

# 2. Build and run unit test suites immediately
make run

# 3. Clean up build binaries
make clean
```

---

## ⚙️ How the Dynamic Makefile Works

The Makefile uses wildcard matching to automatically compile all `.c` files without manual editing:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main

SRCS = $(wildcard *.c)
OBJS = 

all: $(TARGET)

$(TARGET): $(SRCS) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(OBJS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean
```
