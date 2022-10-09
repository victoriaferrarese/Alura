#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variáveis globais
char palavrasecreta[20];
int tentativas = 0;
char chute;
char chutes[26];

//Assinaturas
void abertura();
void receberChute();
void verificarChute();

int main(void){

    sprintf(palavrasecreta, "HIPOPOTAMO");
    abertura();
    verificarChute();
}
void abertura(){

    printf("*******************************\n");
    printf("\tJOGO DA FORCA\n");
    printf("*******************************\n");
}
//Recebe o chute e adiciona no array de chutes 
void receberChute(){

    printf("Escolha uma letra: ");
    scanf("%c", &chute);
    chutes[tentativas] = chute;
    tentativas++;
}
//verifica se o chute é correto & imprime a palavra secreta 
void verificarChute(){
    int acertou = 0; // boolean (falso)
    int enforcou = 0; // boolean (falso)

    do{
        for (int i = 0; i < strlen(palavrasecreta); i++) //percorre o array da palavra secreta
        {
            int achou = 0;
            for (int j = 0; j < strlen(chutes); j++) //verifica se o chute é correto 
            {
                if (chutes[j] == palavrasecreta[i])
                {
                    achou = 1;
                    break;
                }
            }
            if (achou){
                printf("%c ", palavrasecreta[i]);
            }
            else{
                printf("_ ");
            }
        } 
        printf("\n");
        receberChute();

    }while(!acertou && !enforcou); //condição booleana 
}
