
//struct do tipo mapa que contem um conjunto de variaveis que sao relacionadas entre si (uma necessita da outra)
struct mapa {
    char** matriz; //ponteiro de ponteiro
    int linhas;
    int colunas;
};

void armazenarMapa();
void liberarMapa();
void alocarMapa();
int acabou();
void mover(char direcao);
void imprimirMapa();
