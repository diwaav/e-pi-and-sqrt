# CITE : TA Omar helped us build the makefile together during section

CC = clang
CFLAGS = -Werror -Wall -Wextra -Wpedantic
TARGET = mathlib-test
LFLAGS = -lm

OBJECTS = mathlib-test.o e.o madhava.o euler.o bbp.o viete.o newton.o
HEADERS = mathlib.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) $^ -o $@

%.o: %.c mathlib.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(TARGET) *.o

format:
	clang-format -i -style=file *.[ch]
