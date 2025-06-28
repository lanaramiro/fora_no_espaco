#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../inc/utils.h"

static pthread_t thread_mural;
static int ativo = 1;

void* gerar_pedidos(void* arg) {
    char tipo = 'b';
    int tripulante = 1;
    while (ativo) {
        Pedido* novo = criar_pedido(tripulante, tipo);
        adicionar_pedido(novo);
        sleep(3);
    }
    return NULL;
}

void iniciar_mural() {
    pthread_create(&thread_mural, NULL, gerar_pedidos, NULL);
}

void finalizar_mural() {
    ativo = 0;
    pthread_join(thread_mural, NULL);
}
