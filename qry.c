#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"
#include "circulo.h"
#include "texto.h"
#include "quadra.h"
#include "instrumentoUrbano.h"
#include "lista.h"
#include "svg.h"
#include "verificacao.h"
#include "casos.h"
#include "sorts.h"

void pnt(FILE* txt, Lista list[11], int j, char corb[], char corp[]) {
    double x, y;
    No node;
    Info fig;

    for(node = getFirst(list[0]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (getIdCirc(fig) == j) {
            setCorbCirc(fig, corb);
            setCorpCirc(fig, corp);
            x = getXCirc(fig);
            y = getYCirc(fig);
            fprintf(txt, "x: %lf y: %lf\n", x, y);
            return;
        }
    }
    for(node = getFirst(list[1]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (getIdRet(fig) == j) {
            setCorbRet(fig, corb);
            setCorpRet(fig, corp);
            x = getXRet(fig);
            y = getYRet(fig);
            fprintf(txt, "x: %lf y: %lf", x, y);
            return;
        }
    }
    for(node = getFirst(list[2]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (getIdTxt(fig) == j) {
            setCorbTxt(fig, corb);
            setCorpTxt(fig, corp);
            x = getXTxt(fig);
            y = getYTxt(fig);
            fprintf(txt, "x: %lf y: %lf", x, y);
            return;
        }
    }
}

void delf(FILE* txt, Lista list[11], int j) {
    No node;
    Info fig;
    double x, y, r, w, h;
    char *corb, *corp, *text, *espessura;

    for(node = getFirst(list[0]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (getIdCirc(fig) == j) {
            x = getXCirc(fig);
            y = getYCirc(fig);
            r = getRCirc(fig);
            espessura = getEspessuraCirc(fig);
            corb = getCorbCirc(fig);
            corp = getCorpCirc(fig);
            fprintf(txt, "id: %d x: %lf y: %lf r: %lf espessura: %s corb: %s corp: %s\n", j, x, y, r, espessura, corb, corp);
            removeNode(list[0], node, 1);
            return;
        }
    }
    for(node = getFirst(list[1]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (getIdRet(fig) == j) {
            x = getXRet(fig);
            y = getYRet(fig);
            w = getWRet(fig);
            h = getHRet(fig);
            espessura = getEspessuraRet(fig);
            corb = getCorbRet(fig);
            corp = getCorpRet(fig);
            fprintf(txt, "id: %d x: %lf y: %lf w: %lf h: %lf espessura: %s corb: %s corp: %s\n", j, x, y, w, h, espessura, corb, corp);
            removeNode(list[1], node, 1);
            return;
        }
    }
    for(node = getFirst(list[2]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (getIdTxt(fig) == j) {
            x = getXTxt(fig);
            y = getYTxt(fig);
            corb = getCorbTxt(fig);
            corp = getCorpTxt(fig);
            text = getTexto(fig);
            fprintf(txt, "id: %d x: %lf y: %lf corb: %s corp: %s texto: %s\n", j, x, y, corb, corp, text);
            removeNode(list[2], node, 1);
            return;
        }
    }
}

void intersecao(FILE* svg, FILE* txt, Lista list[11], int j, int k){
    No node;
    Info fig1, fig2, aux;
    char tipo1, tipo2;
    for(node = getFirst(list[0]); node != NULL; node = getNext(node)){
        aux = getInfo(node);
        if(getIdCirc(aux) == j){
            fig1 = aux;
            tipo1 = 'c';
        }
        else if(getIdCirc(aux) == k){
            fig2 = aux;
            tipo2 = 'c';
        }
    }
    for(node = getFirst(list[1]); node != NULL; node = getNext(node)){
        aux = getInfo(node);
        if(getIdRet(aux) == j){
            fig1 = aux;
            tipo1 = 'r';
        }
        else if(getIdRet(aux) == k){
            fig2 = aux;
            tipo2 = 'r';
        }
    }
    if(tipo1 == 'c'){
        if(tipo2 == 'c'){
            circuloInt(fig1, j, fig2, k, txt, svg);
        }
        else{
            retanguloIntCirculo(fig1, fig2, j, k, txt, svg);
        }
    }
    else{
        if(tipo2 == 'c'){
            retanguloIntCirculo(fig2, fig1, k, j, txt, svg);
        }
        else{
            retanguloInt(fig1, j, fig2, k, txt, svg);
        }
    }
}

void pontoInterno(FILE* svg, FILE* txt, Lista list[11], int j, double xPonto,double yPonto){
    No node;
    Info info;
    double x,y,w,h;
    char cor[10];
    for(node = getFirst(list[0]); node != NULL; node = getNext(node)){
        info = getInfo(node);
        if(j == getIdCirc(info)){
            x = getXCirc(info);
            y = getYCirc(info);
            h = getRCirc(info);
            if(pontoInternoCirc(xPonto,yPonto,x,y,h)){
                fprintf(txt,"%d: circulo INTERNO\n",j);
                strcpy(cor,"blue");
            }
            else{
                fprintf(txt,"%d: circulo NAO INTERNO\n",j);
                strcpy(cor,"magenta");
            }
            fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke: \"%s\"; stroke-width: 1\" />\n", xPonto,yPonto,x,y,cor);
            fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" fill=\"%s\" stroke=\"%s\"/>\n",xPonto,yPonto,cor,cor);
            return;
        }
        
    }
    for(node = getFirst(list[1]); node != NULL; node = getNext(node)){
        info = getInfo(node);
        if(j == getIdRet(info)){
            x = getXRet(info);
            y = getYRet(info);
            h = getHRet(info);
            w = getHRet(info);
            if(pontoInternoRet(xPonto,yPonto,x,y,w,h)){
                fprintf(txt,"%d: retangulo INTERNO\n",j);
                strcpy(cor,"blue");
            }
            else{
                fprintf(txt,"%d: retangulo NAO INTERNO\n",j);
                strcpy(cor,"magenta");
            }
            fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke: \"%s\"; stroke-width: 1\" />\n", xPonto,yPonto,x + w/2,y + h/2,cor);
            fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" fill=\"%s\" stroke=\"%s\"/>\n",xPonto,yPonto,cor,cor);
            return;
        }
    }
}

void dq(FILE* svg,FILE* txt, Lista list[11],char id[], double r, int flag){
    Info info;
    No aux, node;
    int i, encontrado = 0;
    double x, y;
    switch (id[0]){
    case 'h':
        i = 4;
        fprintf(txt,"Hidrante: ");
        break;
    case 's':
        i = 5;
        fprintf(txt,"Semaforo: ");
        break;
    case 'r':
        i = 6;
        fprintf(txt,"Torre de Radio: ");
        break;
    }
    for(node = getFirst(list[i]); node != NULL; node = getNext(node)){
        info = getInfo(node);
        if(strcmp(getIdIU(info),id) == 0){
            x = getXIU(info);
            y = getYIU(info);
            encontrado = 1;
            fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"black\" stroke=\"black\"/>\n",x,y,r);
            fprintf(txt,"Id: %s X: %lf Y: %lf\n",id,x,y);
            break;
        }
    }
    if(!encontrado){
        fprintf(txt, "OBJETO NAO ENCONTRADO\n");
        return;
    }
    node = getFirst(list[3]);
    while(node != NULL){
        info = getInfo(node);
        if(quadraInternoCirc(info,x,y,r)){
            if(flag){
                fprintf(svg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"beige\" stroke=\"olive\"  stroke-width=\"%s\" rx=\"20\"/>\n",getXQuad(info),getYQuad(info),getWQuad(info),getHQuad(info),getEspessuraQuad(info));
            }
            fprintf(txt," Quadra removida: %s\n", getCEP(info));
            aux = node;
            node = getNext(node);
            removeNode(list[3], aux, 1);
        }
        else{
            node = getNext(node);
        }
    }
    fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"6\" fill=\"none\" stroke=\"red\"/>\n",x,y);
    fprintf(svg,"\t<circle cx=\"%lf\" cy=\"%lf\" r=\"7\" fill=\"none\" stroke=\"blue\"/>\n",x,y);
}

void del(FILE* svg, FILE* txt, Lista list[11], char cepid[]) {
    Info fig;
    No node;
    int i = 3;
    double x, y, w, h;
    char *corb, *corp, *espessura;
    switch (cepid[0]){
    case 'h':
        i = 4;
        fprintf(txt, "Hidrante: ");
        break;
    case 's':
        i = 5;
        fprintf(txt, "Semaforo: ");
        break;
    case 'r':
        i = 6;
        fprintf(txt, "Torre de Radio: ");
        break;
    }

    if (i == 3) {
        for(node = getFirst(list[i]); node != NULL; node = getNext(node)) {
            fig = getInfo(node);
            if (strcmp(cepid, getCEP(fig)) == 0) {
                w = getWQuad(fig);
                h = getHQuad(fig);
                x = getXQuad(fig);
                y = getYQuad(fig);
                espessura = getEspessuraQuad(fig);
                corb = getCorbQuad(fig);
                corp = getCorpQuad(fig);
                fprintf(txt, "CEP: %s x: %lf y: %lf w: %lf h: %lf espessura: %s corb: %s corp: %s\n", cepid, x, y, w, h, espessura, corb, corp);
                x += w/2;
                y += h/2;
                fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"0\" style=\"stroke: black; stroke-width: 1\" />\n", x, y, x);
                fprintf(svg, "\t<text x=\"%lf\" y=\"0\">CEP: %s</text>\n", x + 3,cepid);
                removeNode(list[i], node, 1);
                return;
            }
        }
    } 
    else {
        for(node = getFirst(list[i]); node != NULL; node = getNext(node)) {
            fig = getInfo(node);
            if (strcmp(cepid, getCEP(fig)) == 0) {
                x = getXIU(fig);
                y = getYIU(fig);
                espessura = getEspessuraIU(fig);
                corb = getCorbIU(fig);
                corp = getCorpIU(fig);
                fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"0\" style=\"stroke: black; stroke-width: 1\"/>\n", x, y, x);
                fprintf(svg, "\t<text x=\"%lf\" y=\"0\">ID: %s</text>\n", x + 3,cepid);
                fprintf(txt, "ID: %s x: %lf y: %lf espessura: %s corb: %s corp: %s\n", cepid, x, y, espessura, corb, corp);
                removeNode(list[i], node, 1);
                return;
            }
        }
    }
    printf("Nao encontrado\n");
}

void cbq(FILE* txt, Lista list[11], double x, double y, double r, char cstrk[]) {
    No node;
    Info fig;
    for(node = getFirst(list[3]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (quadraInternoCirc(fig, x, y, r)) {
            setCorbQuad(fig, cstrk);
            fprintf(txt, "CEP: %s\n", getCEP(fig));
        }
    }
}

void crd(FILE* txt, Lista list[11], char cepid[]) {
    No node;
    Info fig;
    int i = 3;
    double x, y;
    char tipo[15] = "Quadra";
    switch (cepid[0]) {
    case 'h':
        i = 4;
        fprintf(txt, "Hidrante: ");
        strcpy(tipo, "Hidrante");
        break;
    case 's':
        i = 5;
        fprintf(txt, "Semaforo: ");
        strcpy(tipo, "Semaforo");
        break;
    case 'r':
        i = 6;
        fprintf(txt, "Torre de Radio: ");
        strcpy(tipo, "Torre de radio");
        break;  
    }
    if (i == 3) {
        for (node = getFirst(list[i]); node != NULL; node = getNext(node)) {
            fig = getInfo(node);
            if (strcmp(cepid, getCEP(fig)) == 0) {
                x = getXQuad(fig);
                y = getYQuad(fig);
                fprintf(txt, "Tipo: %s x: %lf y: %lf\n", tipo, x, y);
                return;
            }
        }
    } else {
        for (node = getFirst(list[i]); node != NULL; node = getNext(node)) {
            fig = getInfo(node);
            if (strcmp(cepid, getIdIU(fig)) == 0) {
                x = getXIU(fig);
                y = getYIU(fig);
                fprintf(txt, "Tipo: %s x: %lf y: %lf\n", tipo, x, y);
                return;
            }
        }
    }
}

void car(FILE* svg, FILE* txt, Lista list[11], double px, double py, double pw, double ph) {
    Info fig;
    No node;
    char textoArea[30];
    double area = 0, x, y, w, h;
    fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\"/>\n", px, py, pw, ph);
    fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"0\"/>\n", px, py, px);
    for(node = getFirst(list[3]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (quadraInternoRet(fig, px, py, pw, ph)) {
            x = getXQuad(fig);
            y = getYQuad(fig);
            w = getWQuad(fig);
            h = getHQuad(fig);
            area += (w * h);
            sprintf(textoArea,"Area: %lf m²",w * h);
            insert(list[2],criarTexto(-1,x + w/2, y + h/2,"black","black",textoArea));
            fprintf(txt, "CEP: %s %lf\n", getCEP(fig), w * h);
        }
    }
    fprintf(svg, "\t<text x=\"%lf\" y=\"0\">Area total: %lf m²</text>\n", px + 3, area);
    fprintf(txt, "Area total: %lf\n", area);
}

void cv(Lista list[11], int n, char cep[], char face, int num){
    No node;
    Info fig;
    double x, y, h, w;
    for(node = getFirst(list[3]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (strcmp(cep, getCEP(fig)) == 0) {
            x = getXQuad(fig);
            y = getYQuad(fig);
            h = getHQuad(fig);
            w = getWQuad(fig);
            break;
        }
    }
    if(node == NULL){
        printf("Quadra nao encontrada\n");
        return;
    }
    switch (face){
    case 'n':
        x += num;
        break;
    case 's':
        x += num;
        y += h;
        break;
    case 'l':
        y += num;
        break;
    case 'o':
        x += w;
        y += num;
        break;
    }
    insert(list[9],createCasos(x,y,cep,face,num,n));
}

void soc(FILE* svg, FILE* txt, Lista list[11], int k, char cep[], char face, int num) {
    No node;
    Info fig;
    double x, y, w, h;
    for (node = getFirst(list[3]); node != NULL; node = getNext(node)) {
        fig = getInfo(node);
        if (strcmp(getCEP(fig), cep) == 0) {
            x = getXQuad(fig);
            y = getYQuad(fig);
            w = getWQuad(fig);
            h = getHQuad(fig);
            break;
        }
    }
    if(node == NULL) {
        printf("Quadra não encontrada.\n");
        return;
    }
    switch(face) {
    case 'n':
        x += num;
        break;
    case 's':
        x += num;
        y += h;
        break;
    case 'l':
        y += num;
        break;
    case 'o':
        x += w;
        y += num;
        break;
    }
    shellSort(list[7], x, y);
    int* tamanho1 = (int*)malloc(sizeof(int));
    *tamanho1 = getTamanho(list[10]);
    fprintf(svg, "\t<rect id=\"%d\" x=\"%lf\" y=\"%lf\" width=\"10\" height=\"4\" style=\"fill:blue;stroke-width:2;stroke:white\" />\n",*tamanho1, x, y);
    insert(list[10],tamanho1);
    int i = 0;
    node = getFirst(list[7]);
    while (i < k) {
        fig = getInfo(node);
        int* tamanho2 = (int*)malloc(sizeof(int));
        *tamanho2 = getTamanho(list[10]);
        fprintf(svg, "\t<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"2\" stroke-dasharray=\"5\" />\n",*tamanho2, getXPosto(fig), getYPosto(fig), x, y);
        insert(list[10],tamanho2);
        fprintf(txt, "x: %lf y: %lf\n", getXPosto(fig), getYPosto(fig));
        node = getNext(node);
        i++;
    }
}

void ci(FILE* svg, FILE* txt, Lista list[11], double x, double y, double r){
    No node;
    Info fig;
    int flag = 1, n = 0;
    double d, inc, area;
    char cor[22];
    Posto posto = NULL;
    for(node = getFirst(list[8]); node != NULL; node = getNext(node)){
        fig = getInfo(node);
        if(circIntRegiao(fig,x,y,r)){
            d = getDRegiao(fig);
            flag = 0;
            break;
        }
    }
    insert(list[0],criarCirculo(0,x,y,r,"5px","none","green"));

    if(flag){
        printf("O circulo não está dentro de uma região onde a densidade demografica e conhecida");
        return;
    }
    Lista l = createList();
    Lista casos = NULL;
    for(node = getFirst(list[9]); node != NULL; node = getNext(node)){
        fig = getInfo(node);
        if(pontoInternoCirc(getXCaso(fig),getYCaso(fig),x,y,r)){
            insert(l,fig);
            fprintf(txt,"X : %lf y : %lf\n", getXCaso(fig),getYCaso(fig));
            n += getNCasos(fig);
        }
    }
    if(getFirst(l) == NULL){
        free(l);
        printf("Não foi encontrado casos na região\n");
        return;
    }
    else if(getTamanho(l) > 2){
        casos = convexHull(l);
    }
    else{
        printf("Não é possivel formar o poligono, apenas %d endereco(s)\n",getTamanho(l));
    }
    if(casos == NULL){
        casos = l;
    }
    else{
        removeList(l,0);
    }
    area = obterArea(casos);
    fprintf(txt,"Numero de casos : %d\nArea : %lf\n",n,area);
    if(area != 0){
        inc = 10 * n/(d * area);
        if(inc < 0.1){
            strcpy(cor, "00FFFF");
            fprintf(txt,"Categoria : A - Livre de Covid\n");
        }
        else if(inc < 5){
            strcpy(cor, "008080");
            fprintf(txt,"Categoria : B - Baixa incidencia\n");
        }
        else if(inc < 10){
            strcpy(cor, "FFFF00");
            fprintf(txt,"Categoria : C - Media incidencia\n");
        }
        else if(inc < 20){
            strcpy(cor, "FF0000");
            fprintf(txt,"Categoria : D - Alta incidencia\n");
        }
        else{
            strcpy(cor, "800080");
            fprintf(txt,"Categoria : E - Catastrofico\n");
            for(node = getFirst(list[7]); node != NULL; node = getNext(node)){
                fig = getInfo(node);
                if(pontoInternoCirc(getXPosto(fig), getYPosto(fig), x, y, r)){
                    posto = fig;
                }
            }
            if(posto == NULL){
                posto = centroide(casos,area);
                fprintf(txt,"Necessário novo posto em (%lf,%lf)\n",getXPosto(posto),getYPosto(posto));
            }
        }
    }
    else{
        fprintf(txt,"Não é possivel obter a categoria da região, apenas um caso dentro do circulo\n");
    }
    int* tamanho = (int*)malloc(sizeof(int));
    *tamanho = getTamanho(list[10]);
    fprintf(svg,"\t<polygon id=\"%d\" fill=\"%s\" fill-opacity=\"0.2\" stroke=\"red\" stroke-width=\"5px\" points=\"",*tamanho, cor);
    insert(list[10],tamanho);
    for(node = getFirst(casos); node != NULL; node = getNext(node)){
        fig = getInfo(node);
        fprintf(svg," %lf,%lf",getXCaso(fig),getYCaso(fig));
    }
    fprintf(svg," \"/>\n");
    removeList(casos,0);
}