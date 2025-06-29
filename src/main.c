#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include "../inc/mural.h"
#include "../inc/tripulante.h"
#include "../inc/chefe.h"
#include "../inc/interface.h"
#include "../inc/utils.h"

int main() {
    iniciar_interface();
    iniciar_tripulantes(1);
    iniciar_chefe();

    int sair = 0;
    char buffer[16];
    while (!sair) {
        atualizar_interface();
        mvprintw(5, 0, "(i) Instruções");
        mvprintw(6, 0, "(q) Sair");
        mvprintw(7, 0, "Digite um pedido (ex: 1b):");
        refresh();
        ler_string_usuario(buffer, sizeof(buffer));
        if (buffer[0] == 'q' || buffer[0] == 'Q') {
            sair = 1;
        } else if (buffer[0] == 'i' || buffer[0] == 'I') {
            mostrar_instrucoes();
        } else if (strlen(buffer) == 2 && buffer[0] >= '1' && buffer[0] <= '9') {
            int tripulante = buffer[0] - '0';
            char tipo = buffer[1];
            Pedido* novo = criar_pedido(tripulante, tipo);
            if (novo) {
                adicionar_pedido(novo);
            } else {
                mvprintw(7, 0, "Tipo de pedido inválido!");
                refresh();
                usleep(1000000);
                move(7, 0); clrtoeol();
            }
        }
    }

    finalizar_chefe();
    finalizar_tripulantes();
    //finalizar_mural();
    finalizar_interface();
    return 0;
}