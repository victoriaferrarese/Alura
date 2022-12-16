#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

struct mapa m; //declarando m : conjunto de variaveis do tipo mapa que contém matriz, lados e colunas.
    
int main(void){

    armazenarMapa();

    do{
        imprimirMapa();

        char comando;
        scanf(" %c", &comando);
        mover(comando);

    }while(!acabou());
    

    liberarMapa();
}

//Alocacao dinamica de memoria: Alocando a matriz mapa dinamicamente na memoria
void alocarMapa(){

    //Alocacao dinamica de memoria
    m.matriz = malloc(sizeof(char*) * m.linhas); 
    /*alocando o espaco para ponteiros de caracteres (arrays, que representam as linhas). Como estou alocando ponteiros, mapa é um ponteiro de ponteiro (um ponteiro de arrays), sendo assim deve ser declarada como char** */

    for(int i = 0; i < m.linhas; i++){
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));
    }
    /* Dentro de cada um dos  arrays que foram alocados na memoria, estou alocando espaco para outros caracteres( formando assim, as colunas da matriz)*/
    /*a ultima posicao de uma matriz eh sempre o \0 (assim como um array), dessa forma eh necessario adicionar 1 na posicao da coluna da matriz */
}

//armazena o mapa do arquivo "mapa.txt" na matriz mapa
void armazenarMapa(){
    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("Banco de dados indisponivel\n");
        exit(1);
    }
    
    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));
    alocarMapa();

    for(int i = 0; i < m.linhas; i++){
        fscanf(f, "%s", m.matriz[i]); 
    /*o fscanf le o arquivo e armazena a informação em uma variavel/array. Porem como vou armazenar o mapa em uma matriz, preciso passar para a função apenas uma dimensao dessa matriz (linha). Assim, o mapa sera armazenado na matriz linha por linha.
    obs: Como um array é naturalmente um ponteiro nao ha necessidade de escrever &mapa[i]*/
    }

    fclose(f);  
}

void liberarMapa(){

        /* Como foram usados dois malloc(), devemos usar dois free(), um esvazia o espaco dentro de cada linha e o outro esvazia as proprias linhas da matriz. 
    obs: free() deve estar no fim do codigo todo*/

    for(int i = 0; i < 5; i++){
        //Para cada linha v[]
        free(m.matriz[i]);   
    }
    //Para o ponteiro v**
    free(m.matriz);

}

//Imprime o mapa 
void imprimirMapa(){

    for(int i = 0; i < 5; i++){
        printf("%s\n", m.matriz[i]);
    }
}

int acabou(){
    return 0;
}

//identifica a posicao atual do pacman no mapa e o move de acordo com os comandos do usuario
void mover(char direcao){

    //variaveis que armazenarao as coordenadas do pacman (@)
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

    //movendo o pacman pelo mapa conforme o usuario escolhe a direcao pelo teclado
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
    m.matriz[x][y] = '.'; //substitui o local em que o pacman estava antes de se mover por "."
}