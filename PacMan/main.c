#include <stdio.h>
#include <stdlib.h>

    int linhas;
    int colunas;
  
    char** mapa; //ponteiro de ponteiro

int main(void){

    armazenarMapa();
    
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    liberarMapa();
}

//Alocacao dinamica de memoria: Alocando a matriz mapa dinamicamente na memoria
void alocarMapa(){

    //Alocacao dinamica de memoria
    mapa = malloc(sizeof(char*) * linhas); 
    /*alocando o espaco para ponteiros de caracteres (arrays, que representam as linhas). Como estou alocando ponteiros, mapa é um ponteiro de ponteiro (um ponteiro de arrays), sendo assim deve ser declarada como char** */

    for(int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
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
    
    fscanf(f, "%d %d", &linhas, &colunas);
    alocarMapa();

    for(int i = 0; i < linhas; i++){
        fscanf(f, "%s", mapa[i]); 
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
        free(mapa[i]);   
    }
    //Para o ponteiro v**
    free(mapa);

}