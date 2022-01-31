# X11 Bell
# Copyright (c) 2021 Jovan Lanik

# Makefile

NAME := x11bell
PREFIX ?= /usr/local
INSTALL ?= install
CC ?= gcc
CFLAGS += -std=c11
LDFLAGS += -lX11 -Wl,-S

SRC = source.c
OBJ = $(SRC:%.c=%.o)

TRASH = $(OBJ) $(NAME)

.PHONY: all clean install uninstall

all: $(NAME)
clean:
	@rm $(TRASH) | true
install:
	$(INSTALL) $(NAME) $(DESTDIR)/bin
uninstall:
	rm -f $(DESTDIR)$(BINDIR)
$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@
