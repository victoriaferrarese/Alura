//View: funcoes referentes a interacoes com o usuario (printf)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

void imprimirAbertura(){
    
    printf("*******************************\n");
    printf("\tJOGO DA FORCA\n");
    printf("*******************************\n\n");
}

void imprimirMensagemErro(){

    printf("Desculpe, banco de dados indisponivel...");
}

void imprimirPalavraSecreta(char palavraSecreta[]){

    printf("%s",palavraSecreta);
}