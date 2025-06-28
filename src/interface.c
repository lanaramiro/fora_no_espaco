#include <stdio.h>
#include <ncurses.h>
#include "../inc/interface.h"
#include "../inc/utils.h"

void iniciar_interface() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    clear();
    mvprintw(0, 0, "--- Jogo Fora no Espaço ---");
    refresh();
}

void atualizar_interface() {
    clear();
    mvprintw(0, 0, "--- Jogo Fora no Espaço ---");
    // Exemplo: mostrar quantidade de pedidos
    extern Pedido* lista_pedidos;
    int count = 0;
    Pedido* p = lista_pedidos;
    while (p) { count++; p = p->prox; }
    mvprintw(2, 0, "Pedidos na fila: %d", count);
    mvprintw(4, 0, "Pressione 'q' para sair.");
    refresh();
}

void finalizar_interface() {
    endwin();
}

int ler_input_usuario() {
    return getch();
}

void ler_string_usuario(char* buffer, int maxlen) {
    echo();
    curs_set(1);
    mvprintw(6, 0, "Digite o pedido (ex: 1b): ");
    getnstr(buffer, maxlen - 1);
    noecho();
    curs_set(0);
    move(6, 0);
    clrtoeol();
}