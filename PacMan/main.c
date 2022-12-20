#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h" 

//variaveis globais

MAPA m; //declarando a variavel m do tipo MAPA
POSICAO pacman; //declarando a variavel pacman do tipo posicao

int main(void){

    armazenarMapa(&m);
    encontrarPacman(&m, &pacman, '@');

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

    int proximox = pacman.x;
    int proximoy = pacman.y;

    //movendo o pacman pelo mapa conforme o usuario digita as direcoes 
    switch(direcao){
        case 'a':
            proximoy--;
            break;
        case 'd':
            proximoy++;
            break;
        case 'w': 
           proximox--;
            break;
        case 's':
            proximox++;
            break;    
        default :
            m.matriz[pacman.x][pacman.y] = '@';
    }

    if(!posicaoExistente(&m, proximox, proximoy))
        return; //a funcao mover() para de ser executada

    if(!posicaoDisponivel(&m, proximox, proximoy)){
        return; //a funcao mover() para de ser executada
    }
    
    moverPersonagem(&m, proximox, proximoy, &pacman);
}

