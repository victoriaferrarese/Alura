#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "view.h"
#include "controller.h"

int main(void){

    char palavrasecreta[20];

    escolherpalavra(palavrasecreta);
    imprimepalavrasecreta(palavrasecreta);
    
    /* Modelo MVC: 
    -> header: void escolherpalavra(char palavrasecreta[]); -> assinatura de uma funcao 
    -> main : escolherpalavra(palavrasecreta); -> chamando uma funcao
    */
}