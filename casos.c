#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "casos.h"

typedef struct Endereco{
    double x;
    double y;
    char cep[20];
    char face;
    int numero;
    int n;
}EnderecoStruct;

CasosCovid createCasos(double x, double y, char cep[], char face, int numero, int n){
    EnderecoStruct* caso = (EnderecoStruct*) malloc(sizeof(EnderecoStruct));
    caso->x = x;
    caso->y = y;
    caso->numero = numero;
    caso->n = n;
    caso->face = face;
    strcpy(caso->cep,cep);
    return caso;
}

double getXCaso(CasosCovid caso){
    EnderecoStruct* c = (EnderecoStruct*) caso;
    return c->x;
}


double getYCaso(CasosCovid caso){
    EnderecoStruct* c = (EnderecoStruct*) caso;
    return c->y;
}

char* getCEPCaso(CasosCovid caso){
    EnderecoStruct* c = (EnderecoStruct*) caso;
    return c->cep;
}

char getFaceCaso(CasosCovid caso){
    EnderecoStruct* c = (EnderecoStruct*) caso;
    return c->face;
}

int getNumeroCaso(CasosCovid caso){
    EnderecoStruct* c = (EnderecoStruct*) caso;
    return c->numero;
}

int getNCasos(CasosCovid caso){
    EnderecoStruct* c = (EnderecoStruct*) caso;
    return c->n;
}

void swap(CasosCovid *p1, CasosCovid *p2){  
    EnderecoStruct* a = (EnderecoStruct*) p1;
    EnderecoStruct* b = (EnderecoStruct*) p2;
    EnderecoStruct temp = *a;  
    *a = *b;  
    *b = temp;  
}