#ifndef __texto__
#define __texto__
#include <stdio.h>

typedef void* Texto;

Texto criarTexto(int id, float x, float y, char corp[], char corb[], char txt[]);
//"constructor" da estrutura texto

int getIdTxt(Texto txt);
//retorna o id do texto

float getXTxt(Texto txt);
//retorna o valor de x do texto

void setXTxt(Texto txt, float x);
// atualiza o valor de x do texto

float getYTxt(Texto txt);
// retorna o valor de y no texto

void setYTxt(Texto txt, float y);
// atualiza o valor de y no texto

char* getCorbTxt(Texto txt);
// retorna a cor da borda do texto

void setCorbTxt(Texto txt, char cor[]);
// atualiza o valor da cor da borda do texto

char* getCorpTxt(Texto txt);
// retorna a cor de preenchimento do texto

void setCorpTxt(Texto txt, char cor[]);
// atualiza o valor da cor de preenchimento do texto

char* getTexto(Texto txt);
// retorna o texto armazenado na estrutura

void setTexto(Texto txt, char linha[]);
// atualiza o texto armazenado na estrutura

void desenharTexto(FILE* svg, Texto txt);
// desenha o texto no arquivo svg

#endif