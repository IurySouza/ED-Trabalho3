#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instrumentoUrbano.h"

typedef struct instrumento{
    char id[20];
    double x;
    double y;
    char espessura[10];
    char corb[22];
    char corp[22];
} InstrumentoStruct;

Instrumento criarInstrumento(char id[], double x, double y, char espessura[], char corp[], char corb[]){
    InstrumentoStruct* iu = (InstrumentoStruct*)malloc(sizeof(InstrumentoStruct));
    iu->x = x;
    iu->y = y;
    strcpy(iu->espessura, espessura);
    strcpy(iu->id,id);
    strcpy(iu->corb,corb);
    strcpy(iu->corp,corp);
    return iu;
}

char* getIdIU(Instrumento instrumento){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    return iu->id;
}

double getXIU(Instrumento instrumento){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    return iu->x;
}

void setXIU(Instrumento instrumento, double x){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    iu->x = x;
}

double getYIU(Instrumento instrumento){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    return iu->y;
}

void setYIU(Instrumento instrumento, double y){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    iu->y = y;
}

char* getEspessuraIU(Instrumento instrumento){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    return iu->espessura;
}

void setEspessuraIU(Instrumento instrumento, char espessura[]){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    strcpy(iu->espessura, espessura);
}

char* getCorbIU(Instrumento instrumento){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    return iu->corb;
}

void setCorbIU(Instrumento instrumento, char corb[]){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    strcpy(iu->corb, corb);
}

char* getCorpIU(Instrumento instrumento){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    return iu->corp;
}

void setCorpIU(Instrumento instrumento, char corp[]){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    strcpy(iu->corp, corp);
}

void desenharIU(FILE* svg, Instrumento instrumento){
    InstrumentoStruct* iu = (InstrumentoStruct*) instrumento;
    fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\"/>\n",iu->x,iu->y,iu->corp,iu->corb,iu->espessura);
}