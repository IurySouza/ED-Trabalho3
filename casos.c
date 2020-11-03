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

void desenharQuadra(FILE* svg, CasosCovid caso){
    EnderecoStruct* c = (EnderecoStruct*) caso;
    double h = 10, w = 5;
    double x = getXCaso(c);
    double y = getYCaso(c);
    switch (getFaceCaso(c)){
    case 's':
        y -= h;
        break;
    case 'o':
        x -= w;
        break;
    }
    fprintf(svg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" />\n",x,y,w,h,"orange");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" fill=\"white\" >%d</text>\n",x + w/2,y + h/2,getNCasos(c));
}