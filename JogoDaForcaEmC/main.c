#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variaveis globais
char palavrasecreta[20];
int chutesRealizados = 0;
char chutes[26];
char chute;

//Assinaturas
void abertura();
void receberChute();
int verificarChute(char letra);
void imprimirForca();
int enforcou();
int ganhou();

int main(void){

    sprintf(palavrasecreta, "HIPOPOTAMO");
    abertura();

    do{

        imprimirForca();
        printf("\n");
        receberChute();
        printf("\n");

    }while(!ganhou() && !enforcou()); //condicao booleana 

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

    chutes[chutesRealizados] = chute;
    chutesRealizados++;
}

//Verifica se o chute eh correto
int verificarChute(char letra){ //char letra = palavrasecreta[i], ou seja eh a letra em que o loop da funcao imprimirForca esta agora.
    int chuteCorreto = 0; //variavel booleana (falso)
        for (int j = 0; j < chutesRealizados; j++){ //percorre array chutes
            if (chutes[j] == letra){ 
                chuteCorreto = 1; //variavel booleana (verdadeiro)
                break;
            }
        }
    return chuteCorreto;
}

//Imprime a palavra secreta conforme os chutes sao feitos
void imprimirForca(){
    
        for (int i = 0; i < strlen(palavrasecreta); i++){ //percorre o array da palavra secreta
            
            if (verificarChute(palavrasecreta[i])){ //se verificarChute = verdadeiro
                printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
            }
        } 
        printf("\n");  
    
}
//contabiliza erros e verifica se o limite de erros foi atingido
int enforcou(){ 
    int erros = 0; //max = 5
    for(int i = 0; i < chutesRealizados; i++){ 
        int existe = 0;//Variavel booleana (falso)       
        for(int j = 0; j < strlen(palavrasecreta); j++){ //percorre o array da palavra secreta
            if (chutes[i] == palavrasecreta[j]){
                existe = 1; //variavel booleana (verdadeiro)
                break;
            }
        } 
        if (!existe) erros++;        
    }
    return erros >= 5; //expressao booleana que retorna verdadeiro caso erros >= 5   
}
//verifica se todas as letras da palavra secreta foram acertadas
int ganhou(){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if (verificarChute(palavrasecreta[i])){
            return 0; //se chute = verdadeiro (1), retorna 0;
        }
    }
    return 1; //se ganhou = falso 
}

/* BUGs  :

*/