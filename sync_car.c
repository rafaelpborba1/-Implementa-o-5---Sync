#include <pthread.h>
#include "sync_car.h"

void station_init(struct station *station) {
    station->waiting_passengers = 0;
    station->free_seats = 0;
    station->boarded_passengers = 0;
    pthread_mutex_init(&station->lock, NULL);
    pthread_cond_init(&station->car_arrived, NULL);
    pthread_cond_init(&station->passengers_boarded, NULL);
}

void station_wait_for_car(struct station *station) {
    pthread_mutex_lock(&station->lock);

    station->waiting_passengers++;

    while (station->free_seats == 0) {
        pthread_cond_wait(&station->car_arrived, &station->lock);
    }

    station->waiting_passengers--;
    station->free_seats--;

    pthread_mutex_unlock(&station->lock);
}

void station_on_board(struct station *station) {
    pthread_mutex_lock(&station->lock);

    station->boarded_passengers++;
    pthread_cond_signal(&station->passengers_boarded);

    pthread_mutex_unlock(&station->lock);
}

void station_load_car(struct station *station, int count) {
    pthread_mutex_lock(&station->lock);

    if (count == 0 || station->waiting_passengers == 0) {
        pthread_mutex_unlock(&station->lock);
        return;
    }

    station->free_seats = count;
    station->boarded_passengers = 0;

    int passengers_to_board = station->waiting_passengers < count ? station->waiting_passengers : count;

    pthread_cond_broadcast(&station->car_arrived);

    while (station->boarded_passengers < passengers_to_board) {
        pthread_cond_wait(&station->passengers_boarded, &station->lock);
    }

    station->free_seats = 0;

    pthread_mutex_unlock(&station->lock);
}