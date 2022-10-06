#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char palavrasecreta[20];
    sprintf(palavrasecreta, "HIPOPOTAMO"); //o array recebe "HIPOPOTAMO" como valor.
    
    int acertou = 0;
    int enforcou = 0;

    do{
        char chute;
        scanf("%c", &chute);

        for(int i = 0; i < strlen(palavrasecreta); i++){
            if (chute == palavrasecreta[i]){
                acertou = 1;
                printf("posicao %d\n",i);
            }
        }
        if (acertou == 0){
            enforcou = 1;
        }
    }while(!acertou && !enforcou); //lógica booleana : enquanto a sentença for verdadeira o loop acontece.
}