#ifndef __ordenar__
#define __ordenar__
#include "lista.h"
#include "casos.h"

No partition(Lista l, No primeiro, No ultimo);

void quickSortList(Lista l, No primeiro, No ultimo);

int orientacao(CasosCovid a, CasosCovid b, CasosCovid c);

int comparar(CasosCovid p0, CasosCovid a, CasosCovid b);

Lista convexHull(Lista list);

#endif