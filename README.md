# -Implementa-o-5---Sync
repositorio destinado a implementação 5 de sincronização
Sincronização do Metrô

1. Arquivos .c Utilizados

*sync_car.c:* Contém a implementação da struct station e das funções de sincronização de threads (station_init, station_load_car, station_wait_for_car e station_on_board).

*teste.c:* Arquivo de testes que foi disponibilizado e cria as threads concorrentes (passageiros e trem) para simular e validar o embarque.

2. Sistema Operacional de Desenvolvimento

SO: Linux(Ubuntu via WSL) 

3. Como Compilar, Executar e Testar
   
Compilar:
'''bash
make

(Gera o executável sync_car)

Após isso, colocar o 
'''bash
./sync_car

Executar e Testar:

'''bash 
make run

Limpar arquivos gerados:
'''bash
make clean
