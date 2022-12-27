/* Diretivas de compilacao: ifndef 
O complilador nao reconhece o tipo MAPA na assinatura "void imprimirMapa(MAPA* m);" entao eh necessario importar o header em que MAPA foi declarado "#include "mapa.h".

Porem no arquivo "iu.c" as bibliotecas sao chamadas da seguinte maneira: 
#include "ui.h"
#include "mapa.h" 
Ou seja, "mapa.h" eh definido duas vezes no mesmo arquivo (uma vez no iu.c e outra vez no iu.h).

Dessa forma, no "mapa.h" preciso usar o "#ifndef _MAPA_H_" (le-se: if not defined), e em seguida definir a constante "_MAPA_H_". Ou seja, se a constante "_MAPA_H_" nao tiver sido definida quando o header for compilado, esse arquivo sera lido. Sendo assim, da proxima vez que o "mapa.h" for chamado tudo o que estiver entre o "#ifndef _MAPA_H_" e o "#endif" sera ignorado pelo compilador */

#ifndef _UI_H_
#define _UI_H

#include "mapa.h"

void imprimirparte(char desenho[4][7], int parte);
void imprimirMapa(MAPA* m);
void imprimirResultado(int ganhou, int perdeu);

#endif