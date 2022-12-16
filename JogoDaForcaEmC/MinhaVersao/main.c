#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "model.h"
#include "view.h"
#include "controller.h"

int main(void){

    char palavraSecreta[20];

    imprimirAbertura();
    selecionarPalavra(palavraSecreta);
    
}

    /* Modelo MVC: 
    -> header: void escolherpalavra(char palavrasecreta[]); -> assinatura de uma funcao 
    -> main : escolherpalavra(palavrasecreta); -> chamando uma funcao
    */