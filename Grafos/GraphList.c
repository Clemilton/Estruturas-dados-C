#include "GraphList.h"

link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

bool searchList(link l, vertex num){
	link aux=l;
	
	while(aux!=NULL){
		if(aux->w ==num)
			return true;
		aux=aux->next;
	}
	return false;
}

GraphList graphList_init( int V) { 
   GraphList G = malloc( sizeof *G);
   G->v = V; 
   G->a = 0;
   G->adj = malloc( V * sizeof (link));
   for (vertex v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

void graphList_insertArc( GraphList G, vertex v, vertex w) { 
   for (link a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->a++;
}

void graphList_show(GraphList g){
	
	for( int i =0 ; i < g->v ; i++){
		printf("%d :",i);
		
		for(link aux = g->adj[i]; aux!=NULL; aux= aux->next){
			printf(" %d",aux->w);
		}
		printf("\n");
	}
}

int * graphList_sorverdouros(GraphList g){
	
	int * vetor = malloc(sizeof(int) * g->v);
	
	for(int i = 0 ; i < g->v ; i++)
		vetor[i] = 0;
	
	for(int i = 0 ; i< g->v ; i++){
		if(g->adj[i]==NULL)
			vetor[i]=1;
		
	}
	return vetor;
	
}

void graphList_imprimeSorverdouros(GraphList g){

	int * v = graphList_sorverdouros(g);
	printf("\nVertices Sorverdouros: ");
	for(int i=0;i < g->v ; i++)
		if(v[i]==1)
			printf(" %d",i);
	
}

int*  graphList_isSource(GraphList g){
	int * vetor = malloc(sizeof(int) * g->v);
	
	for(int i = 0 ; i < g->v ; i++)
		vetor[i] = 1;
		
	for(int num = 0; num < g->v; num++){
		for(int i=0; i < g->v ; i++) {
			int b = searchList(g->adj[i],num);
			if(b==true){
				vetor[num]=0;
				break;
			}
		}
	}
	return vetor;
}

void graphList_imprimeFontes(GraphList g){
	
	int * v = graphList_isSource(g);
	
	printf("\nVertices fontes: ");
	for(int i=0;i < g->v ; i++)
		if(v[i]==1)
			printf(" %d",i);
	
}

