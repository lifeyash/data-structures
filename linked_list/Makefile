CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = main
SRCS = main.c

all: $(TARGET)
	$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET).exe

run: $(TARGET)
	./$(TARGET)