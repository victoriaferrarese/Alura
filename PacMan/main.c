#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h" 

//variaveis globais

MAPA m; //declarando a variavel m do tipo MAPA

POSICAO pacman; //declarando a variavel pacman do tipo posicao

int main(void){

    armazenarMapa(&m);
    
    encontrarPacman(&m, &pacman, PACMAN);
    

    do{
        imprimirMapa(&m);
        

        char comando;
        scanf(" %c", &comando);
        
        moverPacman(comando);
        moverFantasma();
        printf("\nmovido\n");

    }while(!fimDeJogo());

    liberarMapa(&m);
}

//fim de jogo
int fimDeJogo(){
    return 0;
}

int direcaoValida(char direcao){
    return direcao == CIMA || direcao == BAIXO || direcao == ESQUERDA || direcao == DIREITA;
}

//movendo o pacman de acordo com os comandos do usuario
void moverPacman(char direcao){

    if(!direcaoValida(direcao))
        return;

    int proximox = pacman.x;
    int proximoy = pacman.y;

    //movendo o pacman pelo mapa conforme o usuario digita as direcoes 
    switch(direcao){
        case ESQUERDA:
            proximoy--;
            break;
        case DIREITA:
            proximoy++;
            break;
        case CIMA: 
           proximox--;
            break;
        case BAIXO:
            proximox++;
            break;    
    }

    if(!posicaoExistente(&m, proximox, proximoy))
        return; //a funcao mover() para de ser executada

    if(!posicaoDisponivel(&m, proximox, proximoy))
        return; //a funcao mover() para de ser executada
    
    moverPersonagem(&m, proximox, proximoy, pacman.x, pacman.y);
    
    pacman.x = proximox;
    pacman.y = proximoy; 
}

//Movendo os fantasmas para a direita(se possivel). obs:para fazer os fantasmas andarem é preciso um mapa auxiliar: copiarMapa()
void moverFantasma(){
    MAPA copia;

    copiarMapa(&copia, &m);
    
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){

            if(copia.matriz[i][j] == FANTASMA){

                int destinox;
                int destinoy;

                int destinoFantasma = direcaoFantasma(i, j, &destinox, &destinoy);

                //se destinoFantasma = verdadeiro
                if(destinoFantasma) {
                    moverPersonagem(&m, destinox, destinoy,i, j);
                }
            }
        }
    }
    liberarMapa(&copia);
}

//sorteando a proxima posicao do fantasma
int direcaoFantasma(int x, int y, int* destinox, int* destinoy){

    //declarando uma matriz com todas as opcoes possiveis de movimentos (esq., dir., cima e baixo)
    int opcoes [4][2] ={ {x,y+1}, {x,y-1}, {x+1,y}, {x-1,y} };

    //sorteando 10 vezes uma posicao
    srand(time(NULL)); 
    for(int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if(posicaoExistente(&m, opcoes[posicao][0], opcoes[0][posicao]) && posicaoDisponivel(&m, opcoes[posicao][0], opcoes[posicao][1])){

            //destinox e destinoy recebem as coordenadas da prox posicao do fantasma
            *destinox = opcoes[posicao][0];
            *destinoy = opcoes[posicao][1];

            return 1;
        }
    }
}   