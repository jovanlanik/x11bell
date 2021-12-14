# X11 Bell
# Copyright (c) 2020 Jovan Lanik

# Makefile

NAME := x11bell
CC := gcc

CFLAGS += -Wall -pedantic -std=c11
LDFLAGS += -lX11 -Wl,-S

SRC = source.c
OBJ = $(SRC:%.c=%.o)

TRASH = $(OBJ) $(NAME)

.PHONY: all clean

all: $(NAME)
clean:
	@rm $(TRASH) | true
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@
