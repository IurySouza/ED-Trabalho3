#include <stdio.h>
#include <stdlib.h>
#include "regiao.h"

typedef struct regiao {
    double x;
    double y;
    double w;
    double h;
    double d;
} RegiaoStruct;

Regiao criarRegiao(double x, double y, double w, double h, double d) {
    RegiaoStruct* regiao = (RegiaoStruct*) malloc(sizeof(RegiaoStruct));
    regiao->x = x;
    regiao->y = y;
    regiao->w = w;
    regiao->h = h;
    regiao->d = d;
    return regiao;
}

double getXRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->x;
}

void setXRegiao(Regiao reg, double x) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->x = x;
}

double getYRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->y;
}

void setYRegiao(Regiao reg, double y) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->y = y;
}

double getWRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->w;
}

void setWRegiao(Regiao reg, double w) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->w = w;
}

double getHRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->w;
}

void setHRegiao(Regiao reg, double h) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->h = h;
}

double getDRegiao(Regiao reg) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    return regiao->d;
}

void setDRegiao(Regiao reg, double d) {
    RegiaoStruct* regiao = (RegiaoStruct*) reg;
    regiao->d = d;
}