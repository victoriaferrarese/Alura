//Model: funcoes referentes a alteracoes de memoria (variaveis,arrays...)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void selecionarPalavra(char palavraSecreta[]){

    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f == 0){

        imprimirMensagemErro();
        exit(1);
    }
    int quantidadeDePalavras;
    fscanf(f, "%d", &quantidadeDePalavras);

    srand(time(NULL));
    int linhaSorteada = rand()%quantidadeDePalavras;
    
    for(int i = 1; i <= linhaSorteada; i++){

        fscanf(f,"%s",&palavraSecreta);    
    }
    printf("%s",palavraSecreta);
    fclose(f);
}