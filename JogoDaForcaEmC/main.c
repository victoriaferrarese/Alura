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
int verificarChute(char letra);
void imprimirPalavra();

int main(void){

    sprintf(palavrasecreta, "HIPOPOTAMO");
    abertura();
    imprimirPalavra();
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

//Verifica se o chute é correto
int verificarChute(char letra){
    int achou = 0; //varíavel booleana (falso)
        for (int j = 0; j < strlen(chutes); j++){ //verifica se o chute é correto 
            if (chutes[j] == letra){
                achou = 1; //varíavel booleana (verdadeiro)
                break;
            }
        }
    return achou;
}

//Imprime a palavra secreta 
void imprimirPalavra(){
    int acertou = 0; // varíavel booleana (falso)
    int enforcou = 0; // varíavel booleana (falso)

    do{
        for (int i = 0; i < strlen(palavrasecreta); i++){ //percorre o array da palavra secreta
            
            int achou = verificarChute(palavrasecreta[i]);

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
