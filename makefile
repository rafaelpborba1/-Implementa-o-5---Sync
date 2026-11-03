CC = gcc
CFLAGS = -Wall -Wextra -pthread -std=c99

all: sync_car

sync_car: main.c sync_car.c
	$(CC) $(CFLAGS) -o sync_car main.c sync_car.c

clean:
	rm -f sync_car *.o