#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

//Alocacao dinamica de memoria: Alocando a matriz mapa dinamicamente na memoria
void alocarMapa(MAPA* m){

    //Alocacao dinamica de memoria
    m->matriz = malloc(sizeof(char*) * m->linhas); 
    /*alocando o espaco para ponteiros de caracteres (arrays, que representam as linhas). Como estou alocando ponteiros, mapa é um ponteiro de ponteiro (um ponteiro de arrays), sendo assim deve ser declarada como char** */

    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * ((*m).colunas + 1));
    }
    /* Dentro de cada um dos  arrays que foram alocados na memoria, estou alocando espaco para outros caracteres( formando assim, as colunas da matriz)*/
    /*a ultima posicao de uma matriz eh sempre o \0 (assim como um array), dessa forma eh necessario adicionar 1 na posicao da coluna da matriz */
}

//armazena o mapa do arquivo "mapa.txt" na matriz mapa
void armazenarMapa(MAPA* m){
    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("Banco de dados indisponivel\n");
        exit(1);
    }
    
    fscanf(f, "%d %d", &(m->linhas), &(m->linhas));
    alocarMapa(m);

    for(int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]); 
    /*o fscanf le o arquivo e armazena a informação em uma variavel/array. Porem como vou armazenar o mapa em uma matriz, preciso passar para a função apenas uma dimensao dessa matriz (linha). Assim, o mapa sera armazenado na matriz linha por linha.
    obs: Como um array é naturalmente um ponteiro nao ha necessidade de escrever &mapa[i]*/
    }

    fclose(f);  
}

void liberarMapa(MAPA* m){

        /* Como foram usados dois malloc(), devemos usar dois free(), um esvazia o espaco dentro de cada linha e o outro esvazia as proprias linhas da matriz. 
    obs: free() deve estar no fim do codigo todo*/

    for(int i = 0; i < m->linhas; i++){
        //Para cada linha v[]
        free(m->matriz[i]);   
    }
    //Para o ponteiro v**
    free(m->matriz);

}

//Imprime o mapa 
void imprimirMapa(MAPA* m){

    for(int i = 0; i < 5; i++){
        printf("%s\n", m->matriz[i]);
    }
}