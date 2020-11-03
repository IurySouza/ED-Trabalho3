#ifndef __regiao__
#define __regiao__

typedef void* Regiao;

Regiao criarRegiao(double x, double y, double w, double h, double d);
//"constructor" da estrutura regiao

double getXRegiao(Regiao reg);
//retorna o X da regiao

void setXRegiao(Regiao reg, double x);
//define o X da regiao

double getYRegiao(Regiao reg);
//retorna o Y da regiao

void setYRegiao(Regiao reg, double y);
//define o Y da regiao

double getWRegiao(Regiao reg);
//retorna a largura da regiao

void setWRegiao(Regiao reg, double w);
//define a largura da regiao

double getHRegiao(Regiao reg);
//retorna a altura da regiao

void setHRegiao(Regiao reg, double h);
//define a altura da regiao

double getDRegiao(Regiao reg);
//retorna a densidade da regiao

void setDRegiao(Regiao reg, double d);
//define a densidade da regiao

#endif