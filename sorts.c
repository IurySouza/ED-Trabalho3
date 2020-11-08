#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"
#include "casos.h"
#include "verificacao.h"
#include "posto.h"

int orientacao(CasosCovid a, CasosCovid b, CasosCovid c){
    double area = (getXCaso(b) - getXCaso(a)) * (getYCaso(c) - getYCaso(a)) - (getYCaso(b) - getYCaso(a)) * (getXCaso(c) - getXCaso(a));
    if(area > 1){
        return 1; //anti-horario
    }
    if(area < 1){
        return -1; //horario
    }
    return 0; //colinear
}

int comparar(CasosCovid p0, CasosCovid a, CasosCovid b){
    int aux = orientacao(p0,a,b);
    if(aux == 0){
        return distancia(getXCaso(p0),getYCaso(p0),getXCaso(b),getYCaso(b)) < distancia(getXCaso(p0),getYCaso(p0),getXCaso(a),getYCaso(a));
    }
    return aux == 1;
}

No partition(Lista l, No primeiro, No ultimo){
    No i = getPrevious(primeiro);
    for(No j = primeiro; j != ultimo; j = getNext(j)){
        if(comparar(getInfo(getFirst(l)), getInfo(j), getInfo(ultimo))){
            i = (i == NULL) ? primeiro : getNext(i); 
            swap(getInfo(i), getInfo(j));
        }
    }
    i = (i == NULL) ? primeiro : getNext(i); 
    swap(getInfo(i), getInfo(ultimo));
    return i; 
}

void quickSortList(Lista l, No primeiro, No ultimo){
    if(ultimo != NULL && primeiro != ultimo && getNext(ultimo) != primeiro){ 
        No p = partition(l, primeiro, ultimo);
        quickSortList(l, primeiro,getPrevious(p));
        quickSortList(l, getNext(p),ultimo);
    }
}

Lista convexHull(Lista list){
    No primeiro = getFirst(list), i;
    CasosCovid p2;
    CasosCovid p1 = getInfo(primeiro);
    for(i = getNext(primeiro); i != NULL; i = getNext(i)){
        p2 = getInfo(i);
        if(getYCaso(p2) < getYCaso(p1) || (getYCaso(p2) == getYCaso(p1) && getXCaso(p2) < getXCaso(p1))){
            p1 = p2;
        }
    }
    swap(getInfo(primeiro),p1);
    quickSortList(list,getNext(primeiro),getLast(list));
    int j = 1;
    for(i = getNext(primeiro); i != NULL; i = getNext(i)){
        p1 = getInfo(i);
        p2 = getInfo(getPrevious(i));
        if(orientacao(getInfo(primeiro),p1,p2) == 0){
            removeNode(list, getPrevious(i));
        }
        else{
            j++;
        }
    }
    if (j < 3){
        return NULL;
    }
    Lista envConv = createList();
    for(i = primeiro, j = 0; j < 3; j++, i = getNext(i)){
        insert(envConv,getInfo(i));
    }
    while(i != NULL){
        while (orientacao(getInfo(getPrevious(getLast(envConv))), getInfo(getLast(envConv)), getInfo(i)) != 1){
            removeNode(envConv,getLast(envConv));
        }
        insert(envConv,getInfo(i));
        i = getNext(i);
    }
    return envConv;
}

Info getIndexInfo(Lista list, int i) {
    Info info;
    No node;
    int j = 0;
    node = getFirst(list);
    while (j < i) {
        node = getNext(node);
        j++;
    }
    info = getInfo(node);
    return info;
}

void shellSort(Lista list, double x, double y) {
    Info info1, info2, aux;
    int i, j, h, tamanho = getTamanho(list);

    for (h = 1; h < tamanho; h = 3 * h + 1);

    while (h > 0) {
        h = (h - 1)/3;
        for (i = h; i < tamanho; i++) {
            aux = getIndexInfo(list, i);
            j = i;
            while (getPostoDist(getIndexInfo(list, j - h), x, y) > getPostoDist(aux, x, y)) {
                info1 = getIndexInfo(list, j);
                info2 = getIndexInfo(list, j - h);
                postoSwap(info1, info2);
                j -= h;
                if (j < h) {
                    break;
                }
            }
            postoSwap(getIndexInfo(list, j), aux);
        }
    }
}