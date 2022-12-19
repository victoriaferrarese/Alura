#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h" 

//variaveis globais

MAPA m; //declarando a variavel m do tipo MAPA
POSICAO pacman; //declarando a variavel pacman do tipo posicao

int main(void){

    armazenarMapa(&m);
    encontrarPosicao(&m, &pacman, '@');

    do{
        imprimirMapa(&m);

        char comando;
        scanf(" %c", &comando);
        mover(comando);

    }while(!fimDeJogo());

    liberarMapa(&m);
}

//fim de jogo
int fimDeJogo(){
    return 0;
}

//movendo o pacman de acordo com os comandos do usuario
void mover(char direcao){

    //substituindo o local em que o pacman estava antes de se mover por "."
    m.matriz[pacman.x][pacman.y] = '.'; 

    //movendo o pacman pelo mapa conforme o usuario digita as direcoes e atualizando sua posicao nova
    switch(direcao){
        case 'a':
            m.matriz[pacman.x][pacman.y-1] = '@';
            pacman.y--;
            break;
        case 'd':
            m.matriz[pacman.x][pacman.y+1] = '@';
            pacman.y++;
            break;
        case 'w': 
            m.matriz[pacman.x-1][pacman.y] = '@';
            pacman.x--;
            break;
        case 's':
            m.matriz[pacman.x+1][pacman.y] = '@';
            pacman.x--;
            break;    
    }

    
}