#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacman.h"
#include "mapa.h" 

//variaveis globais

MAPA m; //declarando a variavel m do tipo MAPA

POSICAO pacman; //declarando a variavel pacman do tipo posicao

int main(void){

    armazenarMapa(&m);
    //printf("\nmapa armazenado");
    encontrarPacman(&m, &pacman, PACMAN);
    //printf("\npacman encontrado\n");

    do{
        imprimirMapa(&m);
        //printf("\nmapa impresso");

        char comando;
        scanf(" %c", &comando);
        //printf("\ncomando recebido");
        moverPacman(comando);
        moverFantasma();

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
    //printf("\ndirecao valida");
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
    //printf("\n posicao existe");

    if(!posicaoDisponivel(&m, proximox, proximoy))
        return; //a funcao mover() para de ser executada
    //printf("\n posicao disponivel");
    
    moverPersonagem(&m, proximox, proximoy, pacman.x, pacman.y);
    //printf("\npersonagem movido");
    pacman.x = proximox;
    pacman.y = proximoy;
    
}

//Movendo os fantasmas para a direita(se possivel). obs:para fazer os fantasmas andarem é preciso um mapa auxiliar: copiarMapa()
void moverFantasma(){
    MAPA copia;

    copiarMapa(&copia, &m);
    printf("\nmapa copiado\n");
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){

            if(copia.matriz[i][j] == FANTASMA){
                if(posicaoDisponivel(&m, i, j+1) && posicaoExistente(&m, i, j+1)){
                    moverPersonagem(&m, i, j, i, j+1);
                }
            }
        }
    }
    liberarMapa(&copia);
}

