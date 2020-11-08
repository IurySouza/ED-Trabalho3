#ifndef __ordenar__
#define __ordenar__
#include "lista.h"
#include "casos.h"

No partition(Lista l, No primeiro, No ultimo);
//organiza a lista de colocando todos os elementos "maiores" fiquem depois do ultimo elemento

void quickSortList(Lista l, No primeiro, No ultimo);
//ordena uma lista pelo algoritmo quicksort

int orientacao(CasosCovid a, CasosCovid b, CasosCovid c);
//verifica se os 3 pontos estao no sentido anti-horario

int comparar(CasosCovid p0, CasosCovid a, CasosCovid b);
//funcao para comparar dois valores de um lista que está sendo ordenada no quicksort

Lista convexHull(Lista list);
//obtem a envoltoria convexa de uma lista de endereços

void shellSort(Lista list, double x, double y);

Info getIndexInfo(Lista list, int i);

#endif