# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99 -O2 -Wno-unused-result

# Raylib libraries
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Project files
SRC = main.c data/player.c data/enemy.c
OUT = game

# Include paths
INCLUDES = -Iengine -Igui

# Output rule
all:
	$(CC) $(SRC) -o $(OUT) $(INCLUDES) $(CFLAGS) $(LIBS)

# Clean rule
clean:
	rm -f $(OUT)