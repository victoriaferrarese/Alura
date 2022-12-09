#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

//Variaveis globais
char palavrasecreta[20];
int chutesRealizados = 0;
char chutes[26];

int main(void){

    abertura();
    selecionarPalavra();
    imprimirForca();

    do{
        receberChute();
        imprimirForca();

    }while(!ganhou() && !enforcou()); //condicao booleana: enquanto ganhou() = 0 (falso) e enforcou = 0 (falso)  

    adicionarPalavra();
    
}

//Imprime o titulo do jogo
void abertura(){

    printf("*******************************\n");
    printf("\tJOGO DA FORCA\n");
    printf("*******************************\n\n");
}

//seleciona a palavra secreta 
void selecionarPalavra(){
    
    FILE* f; //declarando a variavel f : tipo FILE. Obs : é um ponteiro para o arquivo txt

    f = fopen("palavras.txt","r"); 
    /*a funcao fopen acessa arquivos que estao no mesmo diretorio, retornando o endereco de memoria desse arquivo (retorna um ponteiro)
    -> fopen("nome do arquivo", "r = leitura")*/

    //mensagem de erro
    if (f == 0){ //se o arquivo for nulo 
        printf("Desculpe, banco de dados indisponivel...\n\n");
        exit(1); //funcao que indica erro no programa. Obs: exit(0) = programa funcionando com exito
    }

    int quantidadeDePalavras; //variavel que recebera a primeira linha do arquivo f (que corresponde à quantidade de palavras que o arquivo f contém).

    fscanf(f, "%d", &quantidadeDePalavras); 
    /*a funcao fscanf le arquivos de texto (a partir da primeira linha) e armazena (a primeira linha) em uma variavel
    -> fscanf(arquivo, "tipo de dado", &variavel em que sera armazenado)*/
    
    srand(time(NULL)); //gera a semente do srand 

    int numeroSorteado = rand() % quantidadeDePalavras; //sorteia o numero da linha arquivo f 

    for(int i = 0; i <= numeroSorteado; i++){ 
        fscanf(f, "%s", &palavrasecreta); //le a string (ate \n)
    }

    fclose(f); //fecha o arquivo
}

//adiciona uma palavra nova ao banco de dados
void adicionarPalavra(){

    char resposta;
    
    printf("Voce deseja adicionar uma nova palavra ao jogo? (S/N)\n");
    scanf(" %c", &resposta);
    
    if(resposta == 'S') {
        
        char novaPalavra[20];

        printf("Digite a palavra:\n");
        scanf("%s", &novaPalavra);
        
        FILE* f; //declarando a variavel f : tipo FILE. Obs : é um ponteiro para o arquivo txt

        f = fopen("palavras.txt", "r+"); 
        /*a funcao fopen acessa arquivos que estao no mesmo diretorio, retornando o endereco de memoria desse arquivo (retorna um ponteiro)
        -> fopen("nome do arquivo", "r+ = leitura e escrita")*/

        //mensagem de erro
        if (f == 0){ //se o arquivo for nulo 
        printf("Desculpe, banco de dados indisponivel...\n\n");
        exit(1); //funcao que indica erro no programa. Obs: exit(0) = programa funcionando com exito
        }
        
        int quantidadeDePalavras;
        fscanf(f, "%d", &quantidadeDePalavras); //le a primeira linha do arquivo f e armazena na variavel quantidadeDePalavras
        quantidadeDePalavras++; //soma 1 na variavel, uma vez que uma palavra esta sendo adicionada ao banco de dados 

        //Uma vez que o arquivo foi aberto e o fscanf ja leu a primeira linha do arquivo, agora ele esta apontando para a segunda linha. Porem precisamos voltar a primeira linha para alterar o numero que indica a quantidade de palavras do arquivo.

        fseek(f, 0, SEEK_SET);
        /*a funcao fseek posiciona a linha do arquivo que iremos ler/escrever (obs: seek = procurar)
        -> fseek("nome do arquivo", posicao no arquivo (linha), constante que indica que a posicao eh em relacao ao comeco do arquivo(primeira linha))*/

        fprintf(f,"%d",quantidadeDePalavras); //atualiza a primeira linha do arquivo

        fseek(f, 0, SEEK_END);
        /*a funcao fseek posiciona a linha do arquivo que iremos ler/escrever (obs: seek = procurar)
        -> fseek("nome do arquivo", posicao no arquivo (linha), constante que indica que a posicao eh em relacao ao final do arquivo(ultima linha))*/
        
        fprintf(f, "\n%s", novaPalavra); 
        /*a funcao fprintf escreve em arquivos de texto (a partir da primeira linha) 
        -> fprintf(arquivo, "tipodedado", oqueseraescrito)*/

        fclose(f); //fecha o arquivo
    }

}
//Recebe o chute e adiciona no array de chutes 
void receberChute(){
    char chute;
    printf("Escolha uma letra: ");
    scanf(" %c", &chute); // != scanf("%c", &chute);

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
        if (!verificarChute(palavrasecreta[i])){
            return 0; //se chute = verdadeiro (1), retorna 0;
        }
    }
    return 1; //se ganhou = falso 
}
