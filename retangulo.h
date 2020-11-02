#ifndef __retangulo__
#define __retangulo__
#include <stdio.h>

typedef void* Retangulo;

Retangulo criarRetangulo(int id, double x, double y, double w, double h, char espessura[], char corp[], char corb[]);
// "constructor da estrutura retangulo"

int getIdRet(Retangulo ret);
// retorna o id do retangulo

double getXRet(Retangulo ret);
// retorno o x do retangulo

void setXRet(Retangulo ret, double x);
// atualiza o valor de x do retangulo

double getYRet(Retangulo ret);
// retorna o valor de y do retangulo

void setYRet(Retangulo ret, double y);
// atualiza o valor de y do retangulo

char* getEspessuraRet(Retangulo ret);
// retorna o valor da espessura da borda do retangulo

void setEspessuraRet(Retangulo ret, char espessura[]);
// atualiza o valor da espessura da borda do retangulo

double getWRet(Retangulo ret);
// retorna o valor de w do retangulo

void setWRet(Retangulo ret, double w);
// atualiza o valor de w do retangulo

double getHRet(Retangulo ret);
// retorna o valor de h do retangulo

void setHRet(Retangulo ret, double h);
// atualiza o valor de h do retangulo

char* getCorbRet(Retangulo ret);
// retona a cor de borda do retangulo

void setCorbRet(Retangulo ret, char cor[]);
// atualiza o valor da cor de preenchimento do retangulo

char* getCorpRet(Retangulo ret);
// retorna a cor de preenchimento do retangulo

void setCorpRet(Retangulo ret, char cor[]);
// atualiza a cor de preenchimento do retangulo

void desenharRetangulo(FILE* svg, Retangulo retangulo);
//desenha o retangulo no arquivo svg

#endif