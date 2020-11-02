#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct texto{
    int id;
    float x;
    float y;
    char txt[255];
    char corb[22];
    char corp[22];
} TextoStruct;

Texto criarTexto(int id, float x, float y, char corp[], char corb[], char txt[]){
    TextoStruct* texto = (TextoStruct*) malloc(sizeof(TextoStruct));
    texto->id = id;
    texto->x = x;
    texto->y = y;
    strcpy(texto->corb, corb);
    strcpy(texto->corp, corp);
    strcpy(texto->txt, txt);
    return texto;
}

int getIdTxt(Texto txt){
    TextoStruct* texto = (TextoStruct*) txt;
    return texto->id;
}

float getXTxt(Texto txt){
    TextoStruct* texto = (TextoStruct*) txt;
    return texto->x;
}

void setXTxt(Texto txt, float x){
    TextoStruct* texto = (TextoStruct*) txt;
    texto->x = x;
}

float getYTxt(Texto txt){
    TextoStruct* texto = (TextoStruct*) txt;
    return texto->y;
}

void setYTxt(Texto txt, float y){
    TextoStruct* texto = (TextoStruct*) txt;
    texto->y = y;
}

char* getCorbTxt(Texto txt){
    TextoStruct* texto = (TextoStruct*) txt;
    return texto->corb;
}

void setCorbTxt(Texto txt, char cor[]){
    TextoStruct* texto = (TextoStruct*) txt;
    strcpy(texto->corb, cor);
}

char* getCorpTxt(Texto txt){
    TextoStruct* texto = (TextoStruct*) txt;
    return texto->corp;
}

void setCorpTxt(Texto txt, char cor[]){
    TextoStruct* texto = (TextoStruct*) txt;
    strcpy(texto->corp, cor);
}

char* getTexto(Texto txt){
    TextoStruct* texto = (TextoStruct*) txt;
    return texto->txt;
}

void setTexto(Texto txt, char linha[]){
    TextoStruct* texto = (TextoStruct*) txt;
    strcpy(texto->txt, linha);
}

void desenharTexto(FILE* svg, Texto txt){
    TextoStruct* texto = (TextoStruct*) txt;
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%s</text>\n",texto->x,texto->y,texto->corb,texto->corp,texto->txt);
}
