#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../inc/utils.h"
#include <stdlib.h>

static pthread_t tripulante;
static int ativo = 1;

void* rotina_tripulante(void* arg) {
    while (ativo) {
        Pedido* p = remover_pedido();
        if (p) {
            printf("Tripulante preparando %s (id %d)\n", p->tipo, p->id);
            sleep(p->tempo_ingredientes);
            printf("Fazendo %s (id %d)\n", p->tipo, p->id);
            sleep(p->tempo_preparo);
            printf("Pedido %d entregue!\n", p->id);
            free(p);
        } else {
            sleep(1);
        }
    }
    return NULL;
}

void iniciar_tripulantes(int qtd) {
    pthread_create(&tripulante, NULL, rotina_tripulante, NULL);
}

void finalizar_tripulantes() {
    ativo = 0;
    pthread_join(tripulante, NULL);
}