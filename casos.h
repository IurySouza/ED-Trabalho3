#ifndef __casos__
#define __casos__
#include "lista.h"

typedef void* CasosCovid; 

CasosCovid createCasos(double x, double y, char cep[], char face, int numero, int n);
//Retorna um void pointer para uma struct armazenando informacoes sobre casos de covid

double getXCaso(CasosCovid caso);
//Retorna o valor de x da struct

double getYCaso(CasosCovid caso);
//Retorna o valor de y da struct

char* getCEPCaso(CasosCovid caso);
//Retorna o valor do cep da struct

char getFaceCaso(CasosCovid caso);
//Retorna a face da struct

int getNumeroCaso(CasosCovid caso);
//Retorna o valor numero da struct

int getNCasos(CasosCovid caso);
//Retorna o numero de casos de covid da struct

void swap(CasosCovid *a, CasosCovid *b);
//troca o valor de dois ponteiros CasosCovid

void desenharCasos(FILE* svg, CasosCovid caso);
//Adiciona uma representação da struct em um arquivo svg

#endif