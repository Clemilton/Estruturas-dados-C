#ifndef GRAPHMATRIX_H
#define QUEUE_H 1

#define vertex int


#include <stdio.h>
#include <stdlib.h>


typedef enum { false, true } bool;
struct graphMatrix {
	int v;
	int a;
	int **adj;
};

typedef struct graphMatrix *GraphMatrix;

int **MATRIXint( int r, int c, int val);

GraphMatrix GRAPHinit(int v);

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */
void GRAPHinsertArc( GraphMatrix G, vertex v, vertex w);

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc() remove do grafo G o arco v-w. A função supõe que v e w são distintos, positivos e menores que G->V. Se não existe arco v-w, a função não faz nada. */
void GRAPHremoveArc( GraphMatrix G, vertex v, vertex w);

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHshow() imprime, para cada vértice v do grafo G, em uma linha, todos os vértices adjacentes a v. */
void GRAPHshow( GraphMatrix G);

/*Retorna um vetor isSink, tal que  isSink[v] é true se e somente se v é um sorvedouro. */
int *soverdouros(GraphMatrix G);

void imprimeSoverdouros(GraphMatrix G);

/*Retorna um vetor isSource, tal que  isSource[v] é true se e somente se v é uma fonte. */
int *fontes(GraphMatrix G);

void imprimeFontes(GraphMatrix G);

void leArestas(GraphMatrix grafo,int qtd);

//Calcula o grau de entrada do vertice V(0 a V-1);
int GRAPHindeg(GraphMatrix grafo, int vertice);

/*Calcula o grau de saida do vertice V(0 a V-1) */
int GRAPHoutdeg(GraphMatrix grafo, int vertice);

/*Cria uma copia do grafo. Retorna o endereco de memoria */
GraphMatrix GRAPHcopy(GraphMatrix grafo);

void GRAPHdestroy(GraphMatrix *grafo);

//Verifica se um grafo é consistente
bool GRAPHcheck(GraphMatrix grafo);

bool GRAPHequal(GraphMatrix g1,GraphMatrix g2);
#endif

