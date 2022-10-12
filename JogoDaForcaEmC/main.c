#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variáveis globais
char palavrasecreta[20];
int tentativas = 0;
char chutes[26];

//Assinaturas
void abertura();
void receberChute();
int verificarChute(char letra);
void imprimirForca();
int enforcou();

int main(void){

    sprintf(palavrasecreta, "HIPOPOTAMO");
    abertura();
    imprimirForca();
    
}

void abertura(){

    printf("*******************************\n");
    printf("\tJOGO DA FORCA\n");
    printf("*******************************\n");
}

//Recebe o chute e adiciona no array de chutes 
void receberChute(){
    char chute;
    printf("Escolha uma letra: ");
    scanf("%c", &chute);
    chutes[tentativas] = chute;
    tentativas++;
    printf("CHUTE : %c\n",chute); //debuger
}

//Verifica se o chute é correto
int verificarChute(char letra){ //char letra = palavrasecreta[i], ou seja é a letra em que o loop da função imprimirForca está agora.
    int chuteCorreto = 0; //variável booleana (falso)
        for (int j = 0; j < strlen(chutes); j++){ //percorre array chutes
            if (chutes[j] == letra){ 
                chuteCorreto = 1; //variável booleana (verdadeiro)
                break;
            }
        }
    return chuteCorreto;
}
int enforcou(){
    int erros = 0;
    int existe = 0;//Variável booleana (falso)
    for(int i = 0; i < tentativas; i++){ 
        //printf("%d",erros);//debuger       
        for(int j = 0; j < strlen(palavrasecreta); j++){ //percorre o array da palavra secreta
            if (chutes[i] == palavrasecreta[j]){
                existe = 1; //variável booleana (verdadeiro)
                break;
            }
        }
    }   
    if (!existe){
        erros++;
        printf("ERROS : %d\n",erros);
    }
    //return erros >= 5; //expressão booleana que retorna verdadeiro caso erros >= 5
    if (erros < 5){
        return 0;
    }else {
        return 1;
    }
    
}
//Imprime a palavra secreta conforme os chutes são feitos
void imprimirForca(){
    int acertou = 0; //variável booleana (falso)
    do{
        for (int i = 0; i < strlen(palavrasecreta); i++){ //percorre o array da palavra secreta
            
            int chuteCorreto = verificarChute(palavrasecreta[i]); //recebe verdadeiro ou falso

            if (chuteCorreto){ 
                printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
            }
        } 
        printf("\n"); 
        receberChute();
    
    }while(!acertou && !enforcou()); //condição booleana 
}

/* BUGs  :

[1] A forca é impressa duas vezes. Após chutar corretamente a letra, a forca imprime a palavra secreta (com o chute correto revelado) duas vezes. Exemplo : Ao chutar H. É impresso "H _ _ _ _ _ _ _ _ _" duas vezes.
[2] Só o primeiro erro é contabilizado.
[3] Por enquanto o loop da função imprimirForca é infinito. (condições do do while em desenvolvimento).
*/