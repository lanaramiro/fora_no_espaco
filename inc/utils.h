#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>

typedef struct Pedido {
    int id;
    char tipo[32];
    int tempo_ingredientes;
    int tempo_preparo;
    struct Pedido* prox;
} Pedido;

extern Pedido* lista_pedidos;
extern pthread_mutex_t mutex_pedidos;

void adicionar_pedido(Pedido* pedido);
Pedido* remover_pedido();
Pedido* criar_pedido(int tripulante, char tipo);

#endif