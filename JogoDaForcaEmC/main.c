#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abertura();
void receberChute(chutes,tentativas);

int main(void){

    char palavrasecreta[20];
    sprintf(palavrasecreta, "HIPOPOTAMO"); //o array recebe "HIPOPOTAMO" como valor.
    
    int acertou = 0;
    int enforcou = 0;

    char chutes[26]; //array que registra todos os chutes feitos pelo usuário.
    int tentativas = 0;

    abertura();

    do{
        //imprime a palavra secreta
        for(int i = 0; i < strlen(palavrasecreta); i++){ 
            int achou = 0; //variável de controle para a verificação do chute

            //verifica se a letra ja foi chutada
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

        receberChute(chutes,tentativas);

    }while(!acertou && !enforcou); //lógica booleana : enquanto a sentença for verdadeira o loop acontece.
}

void abertura(){
    printf("************************\n");
    printf("     JOGO DA FORCA\n");
    printf("************************\n\n\n");
}

void receberChute(chutes,tentativas){

    char chute;
        printf("\nChute uma letra: ");
        scanf("%c", &chute);

        chutes[tentativas]= chute;
        tentativas++;
}