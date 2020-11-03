#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"
#include "circulo.h"
#include "texto.h"
#include "quadra.h"
#include "instrumentoUrbano.h"
#include "lista.h"
#include "casos.h"

FILE* iniciarSvg(char filename[]){
    
    FILE* svg = fopen(filename, "w");
    if(svg == NULL){
        printf("erro ao abrir o arquivo\n");
        exit(1);
    }
    fprintf(svg, "<svg>\n");
    return svg;
}

void fecharSvg(FILE* svg){
    fprintf(svg, "</svg>");
    fclose(svg);
}

void desenharSvg(FILE* svg, Lista list[10]){
    No node;
    for(node = getFirst(list[0]); node != NULL; node = getNext(node)){
        desenharCirculo(svg, getInfo(node));
    }
    for(node = getFirst(list[1]); node != NULL; node = getNext(node)){
        desenharRetangulo(svg, getInfo(node));
    }
    for(node = getFirst(list[2]); node != NULL; node = getNext(node)){
        desenharTexto(svg, getInfo(node));
    }
    for(node = getFirst(list[3]); node != NULL; node = getNext(node)){
        desenharQuadra(svg, getInfo(node));
    }
    for(int i = 4; i < 7; i++){
        for(node = getFirst(list[i]); node != NULL; node = getNext(node)){
            desenharIU(svg, getInfo(node));
        }
    }
    for(node = getFirst(list[9]); node != NULL; node = getNext(node)){
        desenharCasos(svg,getInfo(node));
    }
}
