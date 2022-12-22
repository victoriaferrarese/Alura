//header do main.c

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int fimDeJogo();
void moverPacman(char direcao);
void moverFantasma();
int direcaoFantasma(int x, int y, int* destinox, int* destinoy);
