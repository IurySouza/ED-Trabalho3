#ifndef __posto__
#define __posto__

typedef void* Posto;

Posto criarPosto(double x, double y);
//"constructor" da estrutura posto

double getXPosto(Posto posto);
//retorna a coordenada X do posto

void setXPosto(Posto posto, double x);
//define a posição X do posto

double getYPosto(Posto posto);
//retorna a coordenada Y do posto

void setYPosto(Posto posto, double y);
//define a posição Y do posto

void desenharPosto(FILE* svg, Posto posto);
//desenha o posto no arquivo SVG

#endif