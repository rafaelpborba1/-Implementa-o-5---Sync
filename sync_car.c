#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "sync_car.h"

void station_init(struct station *station) {
    pthread_mutex_init(&station->lock, NULL);
    pthread_cond_init(&station->train_arrived, NULL);
    pthread_cond_init(&station->train_loaded, NULL);

    station->waiting_passengers = 0;
    station->available_seats = 0;
    station->boarding_passengers = 0;
}

void station_load_car(struct station *station, int count) {
    (void)station;
    (void)count;
}

void station_wait_for_car(struct station *station) {
    (void)station;
}

void station_on_board(struct station *station) {
    (void)station;
}