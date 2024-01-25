CFLAGS=-Wall -Werror -Wextra -std=c11
CC=gcc

EXEC=main

all: clean $(EXEC)
	./$(EXEC)

$(EXEC):
	$(CC) $(CFLAGS) $(EXEC).c -o $(EXEC)

clean:
	rm -f $(EXEC)