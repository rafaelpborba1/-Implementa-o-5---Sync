# -Implementa-o-5---Sync
repositorio destinado a implementação 5 de sincronização
Sincronização do Metrô

1. Arquivos .c Utilizados

*sync_car.c:* Detalhamento das funções de sincronização de threads (station_init, station_load_car, station_wait_for_car e station_on_board).

*sync_car.h*: esboço das funções e criação da struct station

*teste.c:* Arquivo de testes que foi disponibilizado e cria as threads concorrentes (passageiros e trem) para simular e validar o embarque.

*evidencias.log*: guarda todas as saidas do terminal em um arquivo

*makefile*: roda o programa via make e automatizado

2. Sistema Operacional de Desenvolvimento

SO: Linux(Ubuntu via WSL) 

3. Como Compilar, Executar e Testar
   
Compilar:

make

(Gera o executável sync_car)

Após isso, colocar o 

./sync_car

Executar e Testar:

make run

Limpar arquivos gerados:

make clean
