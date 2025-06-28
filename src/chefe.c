#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "../inc/chefe.h"

static pthread_t thread_chefe;
static int ativo = 1;

void* rotina_chefe(void* arg) {
    while (ativo) {
        // Simulando atribuição automática por agora
        sleep(1);
    }
    return NULL;
}

void iniciar_chefe() {
    pthread_create(&thread_chefe, NULL, rotina_chefe, NULL);
}

void finalizar_chefe() {
    ativo = 0;
    pthread_join(thread_chefe, NULL);
}
