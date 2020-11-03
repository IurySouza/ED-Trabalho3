#ifndef __leitura__
#define __leitura__
#include <stdio.h>
#include "lista.h"
#include "retangulo.h"
#include "circulo.h"
#include "texto.h"
#include "quadra.h"
#include "instrumentoUrbano.h"

void pnt(FILE* txt, Lista list[10], int j, char corb[], char corp[]);
//Pinta a borda e o preenchimento da forma/texto de acordo com os parametros passados

void delf(FILE* txt, Lista list[10], int j);
//Deleta a forma/texto de identificador j

void intersecao(FILE* svg, FILE* txt, Lista list[10], int j, int k);
//Seleciona as figuras para realizar o comando i?

void pontoInterno(FILE* svg, FILE* txt, Lista list[10], int j, double xPonto,double yPonto);
//Verifica se o ponto é interno a figura e desenha no svg o ponto e a linha

void dq(FILE* svg, FILE* txt, Lista list[10], char cepid[], double r, int flag);
//Executa o comando dq

void del(FILE* svg, FILE *txt, Lista list[10], char cepid[]);
//Deleta a quadra, hidrante, semáforo ou torre de rádio de acordo com o cep ou id passado pelo parâmetro

void cbq(FILE* txt, Lista list[10], double x, double y, double r, char cstrk[]);
//Muda a cor da borda para cstrk de todas as quadras que estiverem dentro do circulo centrado em x,y e raio r

void crd(FILE* txt, Lista list[10], char cepid[]);
//Adiciona ao arquivo txt as informações sobre a quadra/instrumento urbano

void car(FILE* svg, FILE* txt, Lista list[10], double px, double py, double pw, double ph);
//Calcula a area das figuras dentro do retangulo e adiciona as informações nos arquivos de saida

void cv(Lista list[10], int n, char cep[], char face, int num);

#endif