CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main

# All C source files (compiled directly without generating .o files)
SRCS = $(wildcard *.c)

# Optional object files: Add any .o files here if you need them in the future
OBJS = 

all: $(TARGET)

# Compiles all .c files directly into the target executable
$(TARGET): $(SRCS) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(OBJS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Deletes the main executable and any leftover .o files
clean:
	rm -f $(TARGET) *.o

.PHONY: all run clean
