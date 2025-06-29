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
    mvprintw(0, 0, "+*-_+*Fora no Espaço*+_-*+");
    refresh();
}

void atualizar_interface() {
    clear();
    mvprintw(0, 0, "+*-_+*Fora no Espaço*+_-*+");

    extern Pedido* lista_pedidos;
    int count = 0;
    Pedido* p = lista_pedidos;
    while (p) { count++; p = p->prox; }

    mvprintw(2, 0, "Pedidos na fila: %d", count);
    // mvprintw(4, 0, "(q) Sair do jogo");
    // mvprintw(5, 0, "(i) Como Jogar");
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
    // mvprintw(6, 0, "Digite o pedido (ex: 1b): ");
    getnstr(buffer, maxlen - 1);
    noecho();
    curs_set(0);
    move(6, 0);
    clrtoeol();
}

void mostrar_instrucoes() {
    clear();
    mvprintw(0, 0, "+*-_+*Instruções do Jogo*+_-*+");

    mvprintw(2, 0, "Oi Jere, não entendi muito bem o contexto do jogo, então tomei a liberdade de criar um.");

    mvprintw(4, 0, "Você é um chefe de cozinha, a bordo de um restaurante espacial.");
    mvprintw(5, 0, "Esse restaurante é o mais famoso de todas as galáxias, graças a fundadora Lana,");
    mvprintw(6, 0, "que montou o cardápio mais incrível de todos:");
    mvprintw(7, 2, "* Banana Split (5s ingredientes + 5s preparo)");
    mvprintw(8, 2, "* Frango Frito (2s ingredientes + 2s preparo)");
    mvprintw(9, 2, "* Nhoque (3s ingredientes + 3s preparo)");
    mvprintw(10, 0, "Cardápio mais espacial que esse, impossível!");
    mvprintw(11, 0, "Seu trabalho é pedir para os tripulantes fazerem os pedidos.");
    mvprintw(12, 0, "Eh facil, digite o número do tripulante e qual pedido ele deve fazer (ex: 1b).");
    mvprintw(13, 0, "Boa sorte!");

    mvprintw(15, 0, "Pressione qualquer tecla para voltar ao menu...");
    refresh();
    getch();  
    clear();
    atualizar_interface();  
}
