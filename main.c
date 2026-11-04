#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "sync_car.h"

struct station st;

void* passenger_thread(void* arg) {
    int id = *(int*)arg;
    
    station_wait_for_car(&st);
    printf("[Passageiro %d] Conseguiu vaga e embarcou!\n", id);
    
    station_on_board(&st);
    printf("[Passageiro %d] Sentado com sucesso.\n", id);
    
    return NULL;
}

void* train_thread(void* arg) {
    int seats = *(int*)arg;
    printf("\n---> [TREM] Chegou na estacao com %d vagas disponíveis! <===\n\n", seats);
    
    station_load_car(&st, seats);
    
    printf("\n---> [TREM] Fechou as portas e partiu! <===\n\n");
    return NULL;
}

int main() {
    station_init(&st);

    pthread_t pass[5];
    int pass_ids[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        pthread_create(&pass[i], NULL, passenger_thread, &pass_ids[i]);
    }

    sleep(1);

    pthread_t train;
    int seats = 3;
    pthread_create(&train, NULL, train_thread, &seats);

    pthread_join(train, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(pass[i], NULL);
    }

    printf("Passageiros ainda na fila da estacao: %d\n", st.waiting_passengers);

    return 0;
}