#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

typedef struct circulo{
    int id;
    double x;
    double y;
    double r;
    char espessura[10];
    char corb[22];
    char corp[22];
} CirculoStruct;

Circulo criarCirculo(int id, double x, double y, double r, char espessura[], char corp[], char corb[]){
    CirculoStruct* circulo = (CirculoStruct*) malloc(sizeof(CirculoStruct));
    circulo->id = id;
    circulo->x = x;
    circulo->y = y;
    circulo->r = r;
    strcpy(circulo->espessura, espessura);
    strcpy(circulo->corb, corb);
    strcpy(circulo->corp, corp);
    return circulo;
}

int getIdCirc(Circulo circ){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    return circulo->id;
}

double getXCirc(Circulo circ){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    return circulo->x;
}

void setXCirc(Circulo circ, double x){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    circulo->x = x;
}

double getYCirc(Circulo circ){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    return circulo->y;
}

void setYCirc(Circulo circ, double y){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    circulo->y = y;
}


double getRCirc(Circulo circ){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    return circulo->r;
}

void setRCirc(Circulo circ, double r){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    circulo->r = r;
}

char* getEspessuraCirc(Circulo circ){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    return circulo->espessura;
}

void setEspessuraCirc(Circulo circ, char espessura[]){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    strcpy(circulo->espessura, espessura);
}


char* getCorbCirc(Circulo circ){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    return circulo->corb;
}

void setCorbCirc(Circulo circ, char cor[]){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    strcpy(circulo->corb, cor);
}

char* getCorpCirc(Circulo circ){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    return circulo->corp;
}

void setCorpCirc(Circulo circ, char cor[]){
    CirculoStruct* circulo = (CirculoStruct*) circ;
    strcpy(circulo->corp, cor);
}

void desenharCirculo(FILE* svg, Circulo circulo){
    CirculoStruct* circ = (CirculoStruct*) circulo;
    fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>\n",circ->x,circ->y,circ->r,circ->corp,circ->corb,circ->espessura);
}