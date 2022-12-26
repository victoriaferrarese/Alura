//header de mapa.c

//Diretivas de compilacao (explicacao no arquivo ui.h)
#ifndef _MAPA_H_
#define _MAPA_H_

#define PACMAN '@'
#define FANTASMA 'o'
#define PILULA '0'
#define BOMBA 'b'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'


/*Structs são uma maneira de agrupar diversas variaveis que se relacionam entre si em um unico lugar. Além disso ao inves de declarar cada uma das variaveis presentes na struct no main, basta declarar uma variavel do tipo mapa */

//struct tipo mapa 
struct mapa { 

    char** matriz; //matriz = ponteiro de ponteiro
    int linhas;
    int colunas;
};

/*O typedef permite que apelidemos uma struct, assim ao inves de escrever "struct mapa", escrevemos apenas o apelido*/

//Apelidando a struct mapa de MAPA
typedef struct mapa MAPA; 

/*Para acessar uma das variaveis da struct eh preciso usar ".". EX: m.linhas / m.matriz 
obs: m eh o nome da variavel tipo mapa declarada no main*/

//struct tipo posicao
struct posicao {

    int x; //armazena a linha  em que o pacman (@) esta 
    int y; //armazena a coluna em que o pacman (@) esta 
};

typedef struct posicao POSICAO;

void armazenarMapa(MAPA* m);
void alocarMapa(MAPA* m);
void liberarMapa(MAPA* m);
int encontrarPacman(MAPA* m, POSICAO* p, char c);
int posicaoExistente(MAPA* m, int x, int y);
int posicaoDisponivel(MAPA* m, int x, int y);
int movimentoValido(MAPA* m, int x, int y, char personagem);
int encontrarParede(MAPA* m, int x , int y);
int encontrarPersonagem(MAPA* m, int x, int y, char personagem);
void moverPersonagem(MAPA* m, int destinox, int destinoy,int origemx, int origemy);
void copiarMapa(MAPA* copia, MAPA* original);

#endif
