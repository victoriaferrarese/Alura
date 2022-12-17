//struct do tipo mapa que contem um conjunto de variaveis que sao relacionadas entre si (uma necessita da outra)

struct mapa { //variaveis tipo mapa
    char** matriz; //ponteiro de ponteiro
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; //O typedef permite que apelidemos o struct, nesse caso o apelido do struct mapa é MAPA

void armazenarMapa(MAPA* m);
void liberarMapa(MAPA* m);
void alocarMapa(MAPA* m);
void imprimirMapa(MAPA* m);