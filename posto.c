#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "posto.h"

typedef struct posto {
    double x;
    double y;
} PostoStruct;

Posto criarPosto(double x, double y) {
    PostoStruct* posto = (PostoStruct*) malloc(sizeof(PostoStruct));
    posto->x = x;
    posto->y = y;
    return posto;
}

double getXPosto(Posto post) {
    PostoStruct* posto = (PostoStruct*) post;
    return posto->x;
}

void setXPosto(Posto post, double x) {
    PostoStruct* posto = (PostoStruct*) post;
    posto->x = x;
}

double getYPosto(Posto post) {
    PostoStruct* posto = (PostoStruct*) post;
    return posto->y;
}

void setYPosto(Posto post, double y) {
    PostoStruct* posto = (PostoStruct*) post;
    posto->y = y;
}

void desenharPosto(FILE* svg, Posto post) {
    PostoStruct* posto = (PostoStruct*) post;
    fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" fill=\"black\" />\n", posto->x, posto->y);
}


void postoSwap(Posto *p1, Posto *p2){  
    PostoStruct* a = (PostoStruct*) p1;
    PostoStruct* b = (PostoStruct*) p2;
    PostoStruct temp = *a;  
    *a = *b;  
    *b = temp;
}

double getPostoDist(Posto post, double x, double y) {
    PostoStruct* posto = (PostoStruct*) post;
    return sqrt(pow(posto->x - x, 2) + pow(posto->y - y, 2));
}