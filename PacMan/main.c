#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h" 

MAPA m; //declarando m : conjunto de variaveis do tipo mapa que contem matriz, lados e colunas.
    
int main(void){

    armazenarMapa(&m);

    do{
        imprimirMapa(&m);

        char comando;
        scanf(" %c", &comando);
        mover(comando);

    }while(!acabou());

    liberarMapa(&m);
}

//fim de jogo
int acabou(){
    return 0;
}

//identificando a posicao atual do pacman no mapa e o movendo de acordo com os comandos do usuario
void mover(char direcao){

    //variaveis que armazenam as coordenadas do pacman (@)
    int x;
    int y;

    for (int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if (m.matriz[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    //movendo o pacman pelo mapa conforme o usuario digita as direcoes
    switch(direcao){
        case 'a':
            m.matriz[x][y-1] = '@';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            break;
        case 'w': 
            m.matriz[x-1][y] = '@';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            break;    
    }

    //substituindo o local em que o pacman estava antes de se mover por "."
    m.matriz[x][y] = '.'; 
}