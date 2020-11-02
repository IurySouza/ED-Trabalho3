#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadra.h"

typedef struct quadra{
    char cep[20];
    double x;
    double y;
    double w;
    double h;
    char espessura[10];
    char corb[22];
    char corp[22];
}QuadraStruct;

Quadra criarQuadra(char cep[], double x, double y, char espessura[], double w, double h, char corp[], char corb[]){
    QuadraStruct* quadra = (QuadraStruct*) malloc(sizeof(QuadraStruct));
    quadra->x = x;
    quadra->y = y;
    quadra->h = h;
    quadra->w = w;
    strcpy(quadra->espessura, espessura);
    strcpy(quadra->cep,cep);
    strcpy(quadra->corb,corb);
    strcpy(quadra->corp,corp);
    return quadra;
}

char* getCEP(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cep;
}

double getXQuad(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->x;
}

void setXQuad(Quadra quadra, double x){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->x = x;
}

double getYQuad(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->y;
}

void setYQuad(Quadra quadra, double y){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->y = y;
}

double getWQuad(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->w;
}

void setWQuad(Quadra quadra, double w){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->w = w;
}

double getHQuad(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->h;
}

void setHQuad(Quadra quadra, double h){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->h = h;
}

char* getEspessuraQuad(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->espessura;
}

void setEspessuraQuad(Quadra quadra, char espessura[]){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->espessura, espessura);
}

char* getCorbQuad(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->corb;
}

void setCorbQuad(Quadra quadra, char corb[]){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->corb,corb);
}

char* getCorpQuad(Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->corp;
}

void setCorpQuad(Quadra quadra, char corp[]){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->corp,corp);
}

void desenharQuadra(FILE* svg, Quadra quadra){
    QuadraStruct* quad = (QuadraStruct*) quadra;
    fprintf(svg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\"  stroke-width=\"%s\"/>\n",quad->x,quad->y,quad->w,quad->h,quad->corp,quad->corb,quad->espessura);
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" >%s</text>\n", quad->x + quad->w/2, quad->y + quad->h/2, quad->cep);
}