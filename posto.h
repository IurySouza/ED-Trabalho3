#ifndef __postos__h
#define __postos__h

typedef void* Posto;

Posto criarPosto(double x, double y);
//"constructor" da estrutura posto

Posto getXPosto(Posto posto);
//retorna a coordenada X do posto

Posto setXPosto(Posto posto, double x);
//define a posição X do posto

Posto getYPosto(Posto posto);
//retorna a coordenada Y do posto

Posto setYPosto(Posto posto, double y);
//define a posição Y do posto

void desenhaPosto(FILE* svg, Posto posto);
//desenha o posto no arquivo SVG

#endif