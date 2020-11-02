#ifndef __leitura__
#define __leitura__
#include <stdio.h>
#include <string.h>
#include "lista.h"

char *obterNomeArquivo(char path[]);
//retorno o nome do arquivo sem a extensao e o as pastas dos path

void geo(Lista list[7], char geoArq[], char saida[]);
//le o arquivo .geo e adiciona os elementos nas lsitas

void qry(Lista list[7], char path[], char nomeSaida[]);
//le o arquivo .qry e chama as funcoes que realizam os comandos

void tratamento(char path[], char outPath[], char paramGeo[], char paramQry[]);
//recebe os parametros do programa, trata os parametros e chama as funcoes geo e qry

#endif