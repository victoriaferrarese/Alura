//ui: user interface

#include <stdio.h>
#include "mapa.h" 

char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhopacman[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhofantasma[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

//imprimindo as linhas do ui.h
void imprimirparte(char desenho[4][7], int parte){

    printf("%s", desenho[parte]);
}

//Imprime o mapa (linha por linha)
void imprimirMapa(MAPA* m){

    //imprime linha a linha 
    for(int i = 0; i < m->linhas; i++){

        //para cada linha do modelo (mapa.txt), serao 4 linhas novas como mostra o ui.h
        for(int parte = 0; parte < 4; parte++){

            for(int j = 0; j < m->colunas; j++){
                
                switch(m->matriz[i][j]){
                    case FANTASMA:
                        imprimirparte(desenhofantasma, parte);
                        break; 

                    case PACMAN:
                        imprimirparte(desenhopacman, parte);
                        break;

                    //esse case aceita as duas opcoes:
                    case PAREDE_HORIZONTAL:
                        imprimirparte(desenhoparede, parte);
                        break;
                    case PAREDE_VERTICAL:
                        imprimirparte(desenhoparede, parte);
                        break;
                    
                    case PILULA:
                        imprimirparte(desenhopilula, parte);
                        break;
                    
                    case VAZIO:
                        imprimirparte(desenhovazio, parte);
                        break;
                }
            }
            printf("\n");
        }
    }   
}
void imprimirResultado(int ganhou, int perdeu){
    if(ganhou = 1){
        printf("PARABENS, VOCE GANHOU!!");
        return;
    }
    else if (perdeu = 1){
        printf("VOCE PERDEU :(");
        return;

    }
}
