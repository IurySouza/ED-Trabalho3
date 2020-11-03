#include <stdio.h>
#include <stdlib.h>
#include "posto.h"

typedef struct posto {
    double x;
    double y;
} PostoStruct;

Posto criarPosto(double x, double y) {
    PostoStruct* posto = (PostoStruct*) malloc(sizeof(PostoStruct));
    posto->x = x;
    posto->y = y;
}

Posto getXPosto(Posto post) {
    PostoStruct* posto = (PostoStruct*) post;
    return posto->x;
}

void setXPosto(Posto post, double x) {
    PostoStruct* posto = (PostoStruct*) post;
    posto->x = x;
}

Posto getYPosto(Posto post) {
    PostoStruct* posto = (PostoStruct*) post;
    return posto->y;
}

void setYPosto(Posto post, double y) {
    PostoStruct* posto = (PostoStruct*) post;
    posto->y = y;
}

void desenhaPosto(FILE* svg, Posto post) {
    PostoStruct* posto = (PostoStruct*) post;
    fprintf();
}