#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <ncurses.h>
#include "../inc/utils.h"
#include <stdlib.h>

static pthread_t tripulante;
static int ativo = 1;
static int linha_atual = 10; // Começar a partir da linha 10
static pthread_mutex_t mutex_display = PTHREAD_MUTEX_INITIALIZER;

void* rotina_tripulante(void* arg) {
    while (ativo) {
        Pedido* p = remover_pedido();
        if (p) {
            // Lock para evitar conflitos na tela
            pthread_mutex_lock(&mutex_display);
            
            mvprintw(linha_atual++, 0, "Tripulante preparando %s (id %d)", p->tipo, p->id);
            refresh();
            
            pthread_mutex_unlock(&mutex_display);
            
            sleep(p->tempo_ingredientes);
            
            pthread_mutex_lock(&mutex_display);
            
            mvprintw(linha_atual++, 0, "Fazendo %s (id %d)", p->tipo, p->id);
            refresh();
            
            pthread_mutex_unlock(&mutex_display);
            
            sleep(p->tempo_preparo);
            
            pthread_mutex_lock(&mutex_display);
            
            mvprintw(linha_atual++, 0, "Pedido %d entregue!", p->id);
            refresh();
            
            // Limitar o número de linhas na tela
            if (linha_atual > 20) {
                linha_atual = 10; // Resetar para o início
                // Limpar a área de mensagens
                for (int i = 10; i <= 20; i++) {
                    move(i, 0);
                    clrtoeol();
                }
            }
            
            pthread_mutex_unlock(&mutex_display);
            
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