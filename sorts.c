#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"
#include "casos.h"

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
    CasosCovid p1 = getInfo(primeiro), p2;
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
    for(;i != NULL; i = getNext(i)){
        while (orientacao(getInfo(getPrevious(getLast(envConv))), getInfo(getLast(envConv)), getInfo(i)) != 1){
            removeNode(envConv,getLast(envConv));
        }
        insert(envConv,getInfo(i));
    }
    return envConv;
}