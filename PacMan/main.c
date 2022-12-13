#include <stdio.h>
#include <stdlib.h>

int main(void){

    //mapa.txt sera armazenado em uma matriz 
    char mapa[5][11]; 
    /*as dimensoes do mapa sao 5 x 10. Porem a ultima posicao de uma matriz eh sempre o \0, assim como um array, dessa forma eh necessario adicionar 1 na posicao da coluna da matriz */

    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("Banco de dados indisponivel\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
    fscanf(f, "%s", mapa[i]); 
    /*o fscanf le o arquivo e armazena a informação em um array. Porem como vou armazenar o mapa em uma matriz, preciso passar para a função apenas uma dimensao dessa matriz (linha). Assim, o mapa sera armazenado na matriz linha por linha */
    }

    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }
    
}