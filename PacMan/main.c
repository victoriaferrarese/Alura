#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h" 
#include "ui.h"

//variaveis globais

MAPA m; //declarando a variavel m do tipo MAPA

POSICAO pacman; //declarando a variavel pacman do tipo posicao

int possuiPipula = 0;

int main(void){

    armazenarMapa(&m);
    
    encontrarPacman(&m, &pacman, PACMAN);
    
    do{

        printf("Pilulas: %s\n", (possuiPipula ? "SIM" : "NAO"));
        imprimirMapa(&m);
        
        char comando;
        scanf(" %c", &comando);
        
        moverPacman(comando);
        if(comando == BOMBA) definirExplosaoPilula();
        moverFantasma();

    }while(!fimDeJogo());

    liberarMapa(&m);
}

//fim de jogo
int fimDeJogo(){
    POSICAO pos; //criado somente porque a funcao encontrarPacMan precisa de um parametro desse
    int pacmanExiste = encontrarPacman(&m, &pos, PACMAN);

    return !pacmanExiste; //se o pacman morreu o jogo acaba
}

//declarando as possiveis direcoes para o Pacman
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

    if(!movimentoValido(&m, proximox, proximoy, PACMAN))
        return; //a funcao mover() para de ser executada
    
    //confere se o Pacman encontrou uma pilula
    if(encontrarPersonagem(&m, proximox, proximoy, PILULA))
        possuiPipula = 1;
    
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
    srand(time(0)); 
    for(int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if(movimentoValido(&m, opcoes[posicao][0], opcoes[posicao][1], FANTASMA)){

            //destinox e destinoy recebem as coordenadas da prox posicao do fantasma
            *destinox = opcoes[posicao][0];
            *destinoy = opcoes[posicao][1];

            return 1;
        }
    }
}   

//definindo o tamanho da explosao da funcao explodirPilula()
void definirExplosaoPilula(){

    if(!possuiPipula) return;

    explodirPilula(pacman.x, pacman.y, 0, 1, 3);
    explodirPilula(pacman.x, pacman.y, 0, -1, 3);
    explodirPilula(pacman.x, pacman.y, 1, 0, 3);    
    explodirPilula(pacman.x, pacman.y, -1, 0, 3);

    possuiPipula = 0;
}

//funcao reursiva: explodindo a pipula que o pacman pegou no mapa
void explodirPilula(int x, int y, int somax, int somay, int qtd){
    
    //a funcao só para de se chamar quando o valor de "qtd" chegar a 0
    if(qtd == 0) return;

    int novox = x + somax;
    int novoy = y + somay;
    
    if(!posicaoExistente(&m, novox, novoy)) return;
    if(encontrarParede(&m, novox, novoy)) return;

    //apagando posicao a direita do pacman
    m.matriz[novox][novoy] = VAZIO;

    //chamando a propria funcao e diminuindo o valor de qtd
    explodirPilula(novox, novoy, somax, somay, qtd - 1);
        
}