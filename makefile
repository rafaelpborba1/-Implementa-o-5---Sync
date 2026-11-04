CC = gcc
CFLAGS = -Wall -Wextra -pthread -std=c99 -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -Wno-unused-parameter

all: sync_car

sync_car: teste.c sync_car.c
	$(CC) $(CFLAGS) -o sync_car teste.c sync_car.c

run: sync_car
	./sync_car

clean:
	rm -f sync_car *.o