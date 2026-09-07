CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/baddie.c src/homie.c src/resolver.c src/side_chick.c src/main.c
TARGET = bin/brainrot.exe

all: $(TARGET)

$(TARGET): $(SRC)
	@if not exist bin mkdir bin
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	@echo [BRAINROT] Build complete: $(TARGET)

run: $(TARGET)
	@$(TARGET)

clean:
	@if exist bin rmdir /s /q bin
	@echo [BRAINROT] Cleaned bin/

.PHONY: all run clean
