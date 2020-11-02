#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"

typedef struct retangulo{
    int id;
    double x;
    double y;
    double w;
    double h;
    char espessura[10];
    char corb[22];
    char corp[22];
} RetanguloStruct;

Retangulo criarRetangulo(int id, double x, double y, double w, double h, char espessura[], char corp[], char corb[]){
    RetanguloStruct* retangulo = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));
    retangulo->id = id;
    retangulo->x = x;
    retangulo->y = y;
    retangulo->w = w;
    retangulo->h = h;
    strcpy(retangulo->espessura, espessura);
    strcpy(retangulo->corb, corb);
    strcpy(retangulo->corp, corp);
    return retangulo;
}

int getIdRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->id;
}

double getXRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->x;
}

void setXRet(Retangulo ret, double x){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    retangulo->x = x;
}

double getYRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->y;
}

void setYRet(Retangulo ret, double y){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    retangulo->y = y;
}

char* getEspessuraRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->espessura;
}

void setEspessuraRet(Retangulo ret, char espessura[]){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    strcpy(retangulo->espessura, espessura);
}

double getWRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->w;
}

void setWRet(Retangulo ret, double w){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    retangulo->w = w;
}

double getHRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->h;
}

void setHRet(Retangulo ret, double h){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    retangulo->h = h;
}

char* getCorbRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->corb;
}

void setCorbRet(Retangulo ret, char cor[]){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    strcpy(retangulo->corb, cor);
}

char* getCorpRet(Retangulo ret){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    return retangulo->corp;
}

void setCorpRet(Retangulo ret, char cor[]){
    RetanguloStruct* retangulo = (RetanguloStruct*) ret;
    strcpy(retangulo->corp, cor);
}

void desenharRetangulo(FILE* svg, Retangulo retangulo){
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    fprintf(svg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\"  stroke-width=\"%s\"/>\n",ret->x,ret->y,ret->w,ret->h,ret->corp,ret->corb,ret->espessura);
}