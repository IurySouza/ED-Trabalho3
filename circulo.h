#ifndef __circulo__
#define __circulo__
#include <stdio.h>

typedef void* Circulo;

Circulo criarCirculo(int id, double x, double y, double r, char espessura[], char corp[], char corb[]);
//"constructor" da estrutura circulo

int getIdCirc(Circulo circ);
// retorna o valor de id do circulo

double getXCirc(Circulo circ);
// retorna o valor de x do circulo

void setXCirc(Circulo circ, double x);
// atualiza o valor de x do circulo

double getYCirc(Circulo circ);
// retorna o valor de y do circulo

void setYCirc(Circulo circ, double y);
// atualiza o valor de y do circulo

double getRCirc(Circulo circ);
// retorna o valor do raio do circulo

void setRCirc(Circulo circ, double r);
// atualiza o valor do raio do circulo

char* getEspessuraCirc(Circulo circ);
// retorna o valor da espessura da borda do circulo

void setEspessuraCirc(Circulo circ, char espessura[]);
// atualiza o valor da espessura da borda do circulo

char* getCorbCirc(Circulo circ);
// retorna a cor da borda do circulo

void setCorbCirc(Circulo circ, char cor[]);
// atualiza a cor da borda do circulo

char* getCorpCirc(Circulo circ);
// retorna a cor de preenchimento do circulo

void setCorpCirc(Circulo circ, char cor[]);
// atualiza a cor de preenchimento do circulo

void desenharCirculo(FILE* svg, Circulo circulo);
// desenha o circulo no arquivo svg

#endif