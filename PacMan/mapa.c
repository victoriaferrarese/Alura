//esse arquivo contem todas as funcoes relacionadas ao mapa (armazenar, alocar e liberar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pacman.h"
#include "ui.h"
#include "mapa.h" 

/* A variavel m (tipo MAPA) eh declarada no main, sendo assim esse arquivo nao a reconhece a nao ser que seja passado, como parametro, o endereco de memoria dela para cada funcao que ira acessa-la. Ex:
Main:
- armazenarMapa(&m); //manda o endereco
Mapa.c:
- void armazenarMapa(MAPA* m); //ponteiro que recebe o endereco */

/* Sendo assim, como m eh um ponteiro (MAPA* m), sempre que m for acessado devera ser tratado como tal. Ou seja, ao inves de: fscanf(f, "%d %d", &(m.linhas), &(m.colunas)), usamos: fscanf(f, "%d %d", &((m*).linhas), &((m*).colunas));

Porem existe uma maneira mais facil de representar (m*).linhas ou (m*).colunas, usando ->. Ex: 
- m->linhas
- m->colunas
- m->matriz */

//armazenando "mapa.txt" na matriz mapa
void armazenarMapa(MAPA* m){

    //lendo o arquivo "mapa.txt"
    FILE* f;
    f = fopen("mapa.txt", "r");

    //mensagem de erro
    if(f == 0){
        printf("Banco de dados indisponivel\n");
        exit(1);
    }
    
    //armazenando a quantidade de linhas e a quantidade de colunas (presentes na primeira linha de "mapa.txt")
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    alocarMapa(m);

    //armazenando o mapa na matriz. obs: Como um array é naturalmente um ponteiro nao ha necessidade de usar "&mapa[i]" no fscanf()
    for(int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]); //armazenamento feito linha por linha (por isso eh usado somente uma dimensao da matriz no loop)
     
    }

    //fechando "mapa.txt"
    fclose(f);  
}

//Alocando dinamicamente a matriz mapa na memoria 
void alocarMapa(MAPA* m){

    /* A funcao malloc() serve para alocar memoria durante a execucao do programa, retornando um ponteiro com o endereco do inicio do espaco alocado. Ex:
    -> int* v = malloc(sizeof(int)); //alocando um int
    -> int* v = malloc(sizeof(int) * 10); //alocando um array tipo int de tamanho 10 */

    /* Para alocar uma matriz dinamicamente, primeiro eh preciso alocar as linhas (arrays) e depois os elementos dentro de cada linha (colunas). obs: o fim de todo array é "\0", então deve ser somado 1 ao numero de colunas*/

    //alocando as linhas 
    m->matriz = malloc(sizeof(char*) * m->linhas);

    // alocando as colunas
    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * m->colunas + 1); 
    } 
}

//liberando a matriz mapa da memoria 
void liberarMapa(MAPA* m){

    /* Para liberar uma matriz da memoria eh preciso usar duas funcoes free(), uma para liberar o conteudo dos arrays (colunas) e outra para liberar os proprios arrays (linhas)*/

    for(int i = 0; i < m->linhas; i++){

        //liberando as colunas
        free(m->matriz[i]);   
    }
    //liberando as linhas
    free(m->matriz);
}

//identificando a posicao atual do pacman no mapa
int encontrarPacman(MAPA* m, POSICAO* p, char c){

    for (int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if (m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                return 1; //encontrou
            }
        }
    }
    return 0; //nao encontrou
}

//Verifica se a posicao desejada existe
int posicaoExistente(MAPA* m, int x, int y){
    //se posicao digitada for maior que a qtd de linhas
    if(x >= m->linhas)
        return 0; 
    
    //se posicao digitada for maior que a qtd de colunas
    if(y >= m->colunas)
        return 0; 

    return 1;
}

//retornando se o movimento eh valido: a posicao existe na matriz, nao eh uma matriz 
int movimentoValido(MAPA* m, int x, int y, char personagem){
    return posicaoExistente(m, x, y) && !encontrarParede(m, x, y) && !encontrarPersonagem(m, x, y, personagem);
}

//encontrando as paredes do mapa
int encontrarParede(MAPA* m, int x , int y){
    return 
        m->matriz[x][y] == PAREDE_HORIZONTAL ||
        m->matriz[x][y] == PAREDE_VERTICAL;
}

//encontrando os personagens iguais no mapa
int encontrarPersonagem(MAPA* m, int x, int y, char personagem){
    return 
        m->matriz[x][y] == personagem;
}

//Movendo os personagens pelo mapa 
void moverPersonagem(MAPA* m, int destinox, int destinoy,int origemx, int origemy){

    //armazenando o caractere do personagem
    char personagem = m->matriz[origemx][origemy];
    //movendo o personagem e zerando sua posicao antiga
    m->matriz[destinox][destinoy] = personagem;
    m->matriz[origemx][origemy] = VAZIO;
}

//fazendo uma copia do mapa original
void copiarMapa(MAPA* destino, MAPA* origem){
    
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    
    alocarMapa(destino);

    for(int i = 0; i < origem->linhas; i++){

        //copiando as strings da matriz original para a copia
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}
 