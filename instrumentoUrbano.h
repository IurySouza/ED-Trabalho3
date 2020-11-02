#ifndef __InstrumentoUrbano__
#define __InstrumentoUrbano__
#include <stdio.h>

typedef void* Instrumento;

Instrumento criarInstrumento(char id[], double x, double y, char espessura[], char corp[], char corb[]);
//"constructor" da estrutura instrumento urbano

char* getIdIU(Instrumento instrumento);
// retorna o id do instrumento urbano

double getXIU(Instrumento instrumento);
// retorna o valor de x do instrumento urbano

void setXIU(Instrumento instrumento, double x);
// atualiza o valor de x do instrumento urbano

double getYIU(Instrumento instrumento);
//retorna o valor de y do instrumento urbano

void setYIU(Instrumento instrumento, double y);
// atualiza o valor de y do instrumento urbano

char* getEspessuraIU(Instrumento instrumento);
// retorna o valor da espessura da borda do instrumento urbano

void setEspessuraIU(Instrumento instrumento, char espessura[]);
// atualiza o valor da espessura da borda do instrumento urbano

char* getCorbIU(Instrumento instrumento);
// retorna a cor da borda do instrumento urbano

void setCorbIU(Instrumento instrumento, char corb[]);
// atualiza o valor da cor da borda do instrumento urbano

char* getCorpIU(Instrumento instrumento);
// retorna a cor de preenchimento do instrumento urbano

void setCorpIU(Instrumento instrumento, char corp[]);
// atualiza o valor da cor de preenchimento do instrumento urbano

void desenharIU(FILE* svg, Instrumento instrumento);
// desenha o instrumento urbano no arquivo svg

#endif