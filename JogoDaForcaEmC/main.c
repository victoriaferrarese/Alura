#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abertura();

int main(void){

    char palavrasecreta[20];
    sprintf(palavrasecreta, "HIPOPOTAMO"); //o array recebe "HIPOPOTAMO" como valor.
    
    int acertou = 0;
    int enforcou = 0;

    char chutes[26]; //array que registra todos os chutes feitos pelo usuário.
    int tentativas = 0;

    abertura();

    do{

        for(int i = 0; i < strlen(palavrasecreta); i++){ //percorre a palavrasecreta
            int achou = 0; //variável de controle para a verificação do chute
            for(int j = 0; j < tentativas; j++){

                if(chutes[j] == palavrasecreta[i]){
                    achou = 1; //caso o chute esteja certo a variável de controle vira verdadeira (boolean)
                    break;
                }
            }
            if(achou){
                printf("%c ",palavrasecreta[i]);
            }else {
                printf("_ ");
            }
        }
        printf("\n");

        char chute;
        printf("\nChute uma letra: ");
        scanf("%c", &chute);

        chutes[tentativas]= chute;
        tentativas++;

    }while(!acertou && !enforcou); //lógica booleana : enquanto a sentença for verdadeira o loop acontece.
}
void abertura(){
    printf("************************\n");
    printf("     JOGO DA FORCA\n");
    printf("************************\n");
}