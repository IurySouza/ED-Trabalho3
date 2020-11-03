#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"
#include "circulo.h"
#include "texto.h"
#include "quadra.h"
#include "instrumentoUrbano.h"
#include "lista.h"
#include "qry.h"
#include "svg.h"

char *obterNomeArquivo(char path[]){
    char *aux = strrchr(path,'/');
    if(aux == NULL){
        return strtok(path,".");
    }
	return strtok(&aux[1],".");
}

void geo(Lista list[7], char geoArq[], char saida[]){
    char tipo[4] ,corb[22] ,corp[22], cepid[20], texto[255];
    int i;
    double x, y, w, h, d;
    char cw[10] = "1";
    char rw[10] = "1";
    char eq[10] = "1";
    char eh[10] = "1";
    char es[10] = "1";
    char er[10] = "1";
	char corQP[22] = "blue";
	char corQB[22] = "blue";
	char corHP[22] = "blue";
	char corHB[22] = "blue";
	char corSP[22] = "blue";
	char corSB[22] = "blue";
	char corRP[22] = "blue";
	char corRB[22] = "blue";
    FILE* geo = fopen(geoArq,"r");
    if(geo == NULL){
        printf("erro ao abrir o arquivo\n");
        exit(1);
    }
    while(fscanf(geo,"%s", tipo) != EOF){
        if (strcmp(tipo,"nx") == 0){
            fscanf(geo,"%lf", &x);
            if(fgetc(geo) != '\n'){
                fscanf(geo,"%lf %lf %lf %lf\n", &x, &y, &h, &w);
            }
        }
        else if(strcmp(tipo,"c") == 0){
            fscanf(geo,"%d %lf %lf %lf %s %s\n", &i, &h, &x, &y, corb, corp);
            insert(list[0], criarCirculo(i,x,y,h,cw,corp,corb));
        }
        else if(strcmp(tipo,"r") == 0){
            fscanf(geo,"%d %lf %lf %lf %lf %s %s\n", &i, &w, &h, &x, &y, corb, corp);
            insert(list[1], criarRetangulo(i,x,y,w,h,rw,corp,corb));
        }
        else if(strcmp(tipo,"t") == 0){
            fscanf(geo,"%d %lf %lf %s %s\n", &i, &x, &y, corb, corp);
            fgets(texto, 255, geo);
            insert(list[2], criarTexto(i,x,y,corp,corb,texto));
        }
        else if(strcmp(tipo,"q") == 0){
            fscanf(geo,"%s %lf %lf %lf %lf\n", cepid, &x, &y, &w, &h);
            insert(list[3], criarQuadra(cepid,x,y,eq,w,h,corQP,corQB));
        }
        else if(strcmp(tipo,"h") == 0){
            fscanf(geo,"%s %lf %lf\n", cepid, &x, &y);
            insert(list[4], criarInstrumento(cepid,x,y,eh,corHP,corHB));
        }
        else if(strcmp(tipo,"s") == 0){
            fscanf(geo,"%s %lf %lf\n", cepid, &x, &y);
            insert(list[5], criarInstrumento(cepid,x,y,es,corSP,corSB));
        }
        else if(strcmp(tipo,"rb") == 0){
            fscanf(geo,"%s %lf %lf\n", cepid, &x, &y);
            insert(list[6], criarInstrumento(cepid,x,y,er,corRP,corRB));
        }
        else if(strcmp(tipo,"cq") == 0){
            fscanf(geo,"%s %s %s\n", eq, corQP, corQB);
        }
        else if(strcmp(tipo,"ch") == 0){
            fscanf(geo,"%s %s %s\n", eh, corHP, corHB);
        }
        else if(strcmp(tipo,"cs") == 0){
            fscanf(geo,"%s %s %s\n", es, corSP, corSB);
        }
        else if(strcmp(tipo,"cr") == 0){
            fscanf(geo,"%s %s %s\n", er, corRP, corRB);
        }
        else if(strcmp(tipo,"sw") == 0){
            fscanf(geo,"%s %s\n", cw, rw);
        }
        else if(strcmp(tipo, "ps") == 0) {
            fscanf(geo, "%lf %lf\n", &x, &y);
        }
        else if(strcmp(tipo, "dd") == 0) {
            fscanf(geo, "%lf %lf %lf %lf %lf\n", &x, &y, &w, &h, &d);
        }
    }
    FILE* svg = iniciarSvg(saida);
    desenharSvg(svg,list);
    fecharSvg(svg);
    fclose(geo);
    
}

void qry(Lista list[7], char path[], char nomeSaida[]){
    char* pathTxt = malloc((5 + strlen(nomeSaida))*sizeof(char));
    char* pathSvg = malloc((5 + strlen(nomeSaida))*sizeof(char));
    sprintf(pathTxt,"%s.txt",nomeSaida);
    sprintf(pathSvg,"%s.svg",nomeSaida);
    FILE* consulta = fopen(path,"r");
    FILE* saida = fopen(pathTxt,"w");
    FILE* svg = iniciarSvg(pathSvg);
    if(saida == NULL || consulta == NULL){
        printf("erro ao abrir o arquivo\n");
        exit(1);
    }
    int j,k,i;
    double x,y,h,w;
    char tipo[5], cepid[20], corb[22], corp[22];
    while(fscanf(consulta,"%s",tipo) != EOF){
        if(strcmp(tipo,"o?") == 0){
            fscanf(consulta,"%d %d\n",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            intersecao(svg,saida,list,j,k);
        }
        else if(strcmp(tipo,"i?") == 0){
	        fscanf(consulta,"%d %lf %lf\n",&j,&x,&y);
	        fprintf(saida,"%s %d %lf %lf\n",tipo,j,x,y);
	        pontoInterno(svg,saida,list,j,x,y);
        }
        else if(strcmp(tipo,"pnt") == 0){
	        fscanf(consulta,"%d %s %s\n",&j,corb,corp);
	        fprintf(saida,"%s %d %s %s\n",tipo,j,corb,corp);
	        pnt(saida,list,j,corb,corp);
        }
        else if(strcmp(tipo,"pnt*") == 0){
            fscanf(consulta,"%d %d %s %s\n",&j,&k,corb,corp);
            fprintf(saida,"%s %d %d %s %s\n",tipo,j,k,corb,corp);
            for(i = j; i <= k; i++){
                pnt(saida,list,i,corb,corp);
            }
        }
        else if(strcmp(tipo,"delf") == 0){
            fscanf(consulta,"%d\n",&j);
            fprintf(saida,"%s %d\n",tipo,j);
            delf(saida,list,j);
        }
        else if(strcmp(tipo,"delf*") == 0){
            fscanf(consulta,"%d %d\n",&j,&k);
            fprintf(saida,"%s %d %d\n",tipo,j,k);
            for(i = j; i <= k; i++){
                delf(saida,list,i);
            }
        }
        else if(strcmp(tipo,"dq") == 0){
            fscanf(consulta,"%s", cepid);
            if(strcmp(cepid,"#") == 0){
                i = 1;
                fscanf(consulta,"%s %lf",cepid,&h);
                fprintf(saida,"%s # %s %lf",tipo,cepid,h);
            }else{
                i = 0;
                fscanf(consulta,"%s %lf",cepid,&h);
                fprintf(saida,"%s %s %lf",tipo,cepid,h);
            }
            dq(svg,saida,list,cepid,h,i);
        }
        else if(strcmp(tipo,"del") == 0){
            fscanf(consulta,"%s\n", cepid);
            fprintf(saida,"%s %s\n",tipo,cepid);
            del(svg,saida,list,cepid);
        }
        else if(strcmp(tipo,"cbq") == 0){
            fscanf(consulta,"%lf %lf %lf %s\n", &x, &y ,&h, corb);
            fprintf(saida,"%s %lf %lf %lf %s\n", tipo, x, y ,h, corb);
            cbq(saida,list,x,y,i,corb);
        }
        else if(strcmp(tipo,"crd") == 0){
            fscanf(consulta,"%s\n", cepid);
            fprintf(saida,"%s %s\n",tipo,cepid);
            crd(saida,list,cepid);
        }
        else if(strcmp(tipo,"car") == 0){
            fscanf(consulta,"%lf %lf %lf %lf\n", &x, &y ,&w, &h);
            fprintf(saida,"%s %lf %lf %lf %lf\n", tipo, x, y, w, h);
            car(svg,saida,list,x,y,w,h);
        }

    }
    desenharSvg(svg,list);
    fecharSvg(svg);
    fclose(saida);
    fclose(consulta);
    free(pathSvg);
    free(pathTxt);
}

void tratamento(char path[], char outPath[], char paramGeo[], char paramQry[]){
    char *geoArq = NULL;
    char *qryArq = NULL;
    char *nomeArq = NULL;
    char *nomeQry = NULL;
    char *saida = NULL;
    char *saidaGeo = NULL;
    char *saidaQry = NULL;
    int i;
    if (path != NULL) {
        if(path[strlen(path) - 1] != '/'){
            geoArq = (char *)malloc((strlen(paramGeo)+strlen(path)+2)*sizeof(char));
    	    sprintf(geoArq,"%s/%s",path,paramGeo);
        }
		else{
            geoArq = (char *)malloc((strlen(paramGeo)+strlen(path)+1)*sizeof(char));
    	    sprintf(geoArq,"%s%s",path,paramGeo);
        }
        if (paramQry != NULL){
            qryArq = (char *)malloc((strlen(paramQry)+strlen(path)+2)*sizeof(char));
            sprintf(qryArq,"%s/%s",path,paramQry);
        }
	} else {
		geoArq = (char *)malloc((strlen(paramGeo)+1)*sizeof(char));
    	strcpy(geoArq, paramGeo);
        if(paramQry != NULL){
            qryArq = (char *)malloc((strlen(paramQry)+1)*sizeof(char));
            strcpy(qryArq, paramQry);
        }
	}
    nomeArq = obterNomeArquivo(paramGeo);
    if (outPath[strlen(outPath) - 1] == '/'){
        saida = (char*)malloc((strlen(nomeArq) + strlen(outPath) + 1)*sizeof(char));
        sprintf(saida,"%s%s",outPath,nomeArq);
    }
    else{
        saida = (char*)malloc((strlen(nomeArq) + strlen(outPath) + 2)*sizeof(char));
        sprintf(saida,"%s/%s",outPath,nomeArq);
    }
    saidaGeo = (char*)malloc((strlen(saida) + 5)*sizeof(char));
    sprintf(saidaGeo,"%s.svg",saida);
    Lista list[7];
    for(i = 0; i < 7; i++){
        list[i] = createList();
    }
    geo(list, geoArq,saidaGeo);
    if (paramQry != NULL){
        nomeQry = obterNomeArquivo(paramQry);
        saidaQry = (char*)malloc((strlen(outPath) + strlen(saida) + 2)*sizeof(char));
        sprintf(saidaQry,"%s-%s",saida,nomeQry);
        qry(list,qryArq,saidaQry);
        free(saidaQry);
        free(qryArq); 
    }
    free(geoArq);
    free(saida);
    free(saidaGeo);
    for(i = 0; i < 7; i++){
        removeList(list[i]);
    }
}