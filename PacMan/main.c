#include <stdio.h>
#include <stdlib.h>

    int linhas;
    int colunas;

   //mapa.txt sera armazenado em uma matriz 
  
    char** mapa; //ponteiro de ponteiro

int main(void){

    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("Banco de dados indisponivel\n");
        exit(1);
    }
    
    fscanf(f, "%d %d", &linhas, &colunas);
    printf("Linhas %d colunas %d\n", linhas, colunas);

    //Alocacao dinamica de memoria
    mapa = malloc(sizeof(char*) * linhas); 
    /*alocando espaco para linhas * ponteiros de caracteres ( arrays, que representam as linhas). Como estou alocando ponteiros, mapa é um ponteiro de ponteiro (um ponteiro de arrays), sendo assim deve ser declarada como char** */

    for(int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
    /* Dentro de cada um dos  arrays que foram alocados na memoria, atraves desse loop, estou alocando espaco para colunas * caracteres */
    /*a ultima posicao de uma matriz eh sempre o \0 (assim como um array), dessa forma eh necessario adicionar 1 na posicao da coluna da matriz */

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]); 
    /*o fscanf le o arquivo e armazena a informação em uma variavel/array. Porem como vou armazenar o mapa em uma matriz, preciso passar para a função apenas uma dimensao dessa matriz (linha). Assim, o mapa sera armazenado na matriz linha por linha.
    obs: Como um array é naturalmente um ponteiro nao ha necessidade de escrever &mapa[i]*/
    }
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    /* Como foram usados dois malloc(), devemos usar dois free(), um esvazia o espaco dentro de cada linha e o outro esvazia as proprias linhas da matriz. 
    obs: free() deve estar no fim do codigo todo*/

    for(int i = 0; i < 5; i++){
        //Para cada linha v[]
        free(mapa[i]);   
    }
    //Para o ponteiro v**
    free(mapa);
    
}