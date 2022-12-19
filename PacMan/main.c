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

    //se posicao digitada for maior que a qtd de linhas
    if(proximox >= m.linhas){
        return; //a funcao mover() para de ser executada
    }

    //se posicao digitada for maior que a qtd de colunas
    if(proximoy >= m.colunas){
        return; //a funcao mover() para de ser executada
    }

    //se posicao digitado for uma parede
    if(m.matriz[proximox][proximoy] != '.'){
        return; //a funcao mover() para de ser executada
    }

    //atualizando a posicao atual e a posicao antiga do pacman
    m.matriz[proximox][proximoy] = '@';
    m.matriz[pacman.x][pacman.y] = '.';
    pacman.x = proximox;
    pacman.y = proximoy;
}