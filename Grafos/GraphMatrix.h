#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H 1

#define vertex int


#include <stdio.h>
#include <stdlib.h>
#include "bool.h"


struct graphMatrix {
	int v;
	int a;
	int **adj;
};

typedef struct graphMatrix *GraphMatrix;

int **MATRIXint( int r, int c, int val);

GraphMatrix graphMatrix_init(int v);

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função graphMatrix_insertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */
void graphMatrix_insertArc( GraphMatrix G, vertex v, vertex w);

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função graphMatrix_removeArc() remove do grafo G o arco v-w. A função supõe que v e w são distintos, positivos e menores que G->V. Se não existe arco v-w, a função não faz nada. */
void graphMatrix_removeArc( GraphMatrix G, vertex v, vertex w);

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função graphMatrix_show() imprime, para cada vértice v do grafo G, em uma linha, todos os vértices adjacentes a v. */
void graphMatrix_show( GraphMatrix G);

/*Retorna um vetor isSink, tal que  isSink[v] é true se e somente se v é um sorvedouro. */
int *graphMatrix_sorverdouros(GraphMatrix G);

void graphMatrix_imprimeSoverdouros(GraphMatrix G);

/*Retorna um vetor isSource, tal que  isSource[v] é true se e somente se v é uma fonte. */
int *graphMatrix_fontes(GraphMatrix G);

void graphMatrix_imprimeFontes(GraphMatrix G);

void graphMatrix_leArestas(GraphMatrix grafo,int qtd);

//Calcula o grau de entrada do vertice V(0 a V-1);
int graphMatrix_indeg(GraphMatrix grafo, int vertice);

/*Calcula o grau de saida do vertice V(0 a V-1) */
int graphMatrix_outdeg(GraphMatrix grafo, int vertice);

/*Cria uma copia do grafo. Retorna o endereco de memoria */
GraphMatrix graphMatrix_copy(GraphMatrix grafo);

void graphMatrix_destroy(GraphMatrix *grafo);

//Verifica se um grafo é consistente
bool graphMatrix_check(GraphMatrix grafo);

bool graphMatrix_equal(GraphMatrix g1,GraphMatrix g2);
#endif

