#ifndef GRAPHLIST_H
#define GRAPHLIST_H 1

#define vertex int


#include <stdio.h>
#include <stdlib.h>
#include "bool.h"


/* A lista de adjacência de um vértice v é composta por nós do tipo node. 
 * Cada nó da lista corresponde a um arco e contém um vizinho w de v e o 
 * endereço do nó seguinte da lista. Um link é um ponteiro para um node. */
typedef struct node *link;
struct node { 
   vertex w; 
   link next; 
};


/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura graph representa um grafo.
 *  O campo adj é um ponteiro para o vetor de listas de adjacência, o campo V contém 
 *  o número de vértices e o campo A contém o número de arcos do grafo. */
struct graphList {
   int v; 
   int a; 
   link *adj; 
};
/* Um Graph é um ponteiro para um graph. */

typedef struct graphList *GraphList;

/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o
 * endereço a de um novo nó tal que a->w == w e a->next == next. */
link NEWnode( vertex w, link next);

int searchList(link l,vertex n);

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinit() constrói 
 *  um grafo com vértices 0 1 .. V-1 e nenhum arco. */
GraphList graphList_init( int V);


/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função GRAPHinsertArc() insere
 *  um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. 
 *  Se o grafo já tem um arco v-w, a função não faz nada. */
void graphList_insertArc( GraphList G, vertex v, vertex w);

/*Imprime o grafo */
void graphList_show(GraphList G);

/*Retorna um vetor isSink, tal que  isSink[v] é true se e somente se v é um sorvedouro. */
int * graphList_sorverdouros(GraphList g);

void  graphList_imprimeSorverdouros(GraphList g);

/*Retorna um vetor isSource, tal que  isSource[v] é true se e somente se v é uma fonte. */
int *graphList_isSource(GraphList g);

void graphList_imprimeFontes(GraphList g);

/* Calcula o grau de entrada de um vertice v de um grafo g*/
int graphList_GRAPHindeg(GraphList g,int vertice);

/* Calcula o grau de saida de um vertice v de um grafo g*/
int graphList_GRAPHoutdeg(GraphList,int vertice);

#endif
