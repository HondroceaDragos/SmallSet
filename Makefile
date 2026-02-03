GCC=gcc
FLAGS=-Wall -Werror -Wextra -O2
SRC=main.c
UTILS=./src/*.c
TARGET=example.exe

# Create a dynamic library (shared)
DLL_NAME=libsmallset

.PHONY:build clean run

all: run

# Compile it separately
$(DLL_NAME): $(UTILS)
	$(GCC) $(CFLAGS) -shared $(UTILS) -o $(DLL_NAME).dll

build: $(SRC) $(DLL_NAME)
	$(GCC) $(FLAGS) $(SRC) -L. -lsmallset -o $(TARGET)

run: build
	./$(TARGET)

clean:
	del $(TARGET)