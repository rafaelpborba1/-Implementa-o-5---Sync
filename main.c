#include <stdio.h>
#include "sync_car.h"

int main() {
    struct station st;

    station_init(&st);

    printf("Estacao inicializada com sucesso!\n");
    printf("Passageiros aguardando: %d\n", st.waiting_passengers);

    return 0;
}