#ifndef __verificacao__
#define __verificacao__
#include <stdio.h>
#include "retangulo.h"
#include "circulo.h"
#include "quadra.h"

double maior(double n1, double n2);
//Retorna o maior double entre os parametros

double menor(double n1, double n2);
//Retorna o menor double entre os parametros

double distancia(double x1, double y1, double x2, double y2);
//Retorna a distancia entre dois pontos

void retanguloIntCirculo(Circulo c, Retangulo r, int idc, int idr, FILE* txt, FILE* svg);
//Executa comando i? quando as figuras forem um circulo e um retangulo

void circuloInt(Circulo c1, int idc1, Circulo c2, int idc2, FILE* txt, FILE* svg);
//Executa comando i? quando as figuras forem dois circulos

void retanguloInt(Retangulo r1, int idr1, Retangulo r2, int idr2, FILE* txt, FILE* svg);
//Executa comando i? quando as figuras forem dois retangulos

int quadraInternoCirc(Quadra q, double x, double y, double r);
//Verifica se a quadra esta inteiramente dentro do circulo de centro (x,y) e raio r;

int quadraInternoRet(Quadra q, double x, double y, double w, double h);
//Verifica se a quadra esta inteiramente dentro do retangulo de ponto (x,y), largura w e altura h;

int pontoInternoCirc(double xPonto, double yPonto, double xCirc, double yCirc, double r);
//Verifica se o ponto esta inteiramente dentro do circulo de centro (x,y) e raio r;

int pontoInternoRet(double xPonto, double yPonto, double xRet, double yRet, double w, double h);
//Verifica se o ponto esta inteiramente dentro do retangulo de ponto (x,y), largura w e altura h;

#endif