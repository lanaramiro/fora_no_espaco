#include <stdlib.h>
#include <string.h>
#include "../inc/utils.h"

Pedido* lista_pedidos = NULL;
pthread_mutex_t mutex_pedidos = PTHREAD_MUTEX_INITIALIZER;

void adicionar_pedido(Pedido* pedido) {
    pthread_mutex_lock(&mutex_pedidos);
    pedido->prox = lista_pedidos;
    lista_pedidos = pedido;
    pthread_mutex_unlock(&mutex_pedidos);
}

Pedido* remover_pedido() {
    pthread_mutex_lock(&mutex_pedidos);
    Pedido* p = lista_pedidos;
    if (p) lista_pedidos = p->prox;
    pthread_mutex_unlock(&mutex_pedidos);
    return p;
}

Pedido* criar_pedido(int tripulante, char tipo) {
    Pedido* p = (Pedido*)malloc(sizeof(Pedido));
    p->id = tripulante;
    switch (tipo) {
        case 'b':
            strcpy(p->tipo, "Banana Split");
            p->tempo_ingredientes = 5;
            p->tempo_preparo = 5;
            break;
        case 'f':
            strcpy(p->tipo, "Frango Frito");
            p->tempo_ingredientes = 2;
            p->tempo_preparo = 2;
            break;
        case 'n':
            strcpy(p->tipo, "Nhoque");
            p->tempo_ingredientes = 3;
            p->tempo_preparo = 3;
            break;
        default:
            free(p);
            return NULL;
    }
    p->prox = NULL;
    return p;
}


