#ifndef __casos__
#define __casos__
#include "lista.h"

typedef void* CasosCovid; 

CasosCovid createCasos(double x, double y, char cep[], char face, int numero, int n);

double getXCaso(CasosCovid caso);

double getYCaso(CasosCovid caso);

char* getCEPCaso(CasosCovid caso);

char getFaceCaso(CasosCovid caso);

int getNumeroCaso(CasosCovid caso);

int getNCasos(CasosCovid caso);

void swap(CasosCovid *a, CasosCovid *b);

void desenharCasos(FILE* svg, CasosCovid caso);

#endif