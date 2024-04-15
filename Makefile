CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g
LDFLAGS = -lm `sdl2-config --cflags --libs`

SRCDIR = ./src
INCDIR = ./headers

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = maze

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): $(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
