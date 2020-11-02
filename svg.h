#ifndef __svg__
#define __svg__
#include <stdio.h>
#include "lista.h"

FILE* iniciarSvg(char filename[]);
//Inicializa o arquivo e abre a tag svg

void fecharSvg(FILE* svg);
//fecha o arquivo e a tag svg

void desenharSvg(FILE* svg, Lista list[7]);
//adiciona no arquivo svg as figuras presentes nas listas

#endif