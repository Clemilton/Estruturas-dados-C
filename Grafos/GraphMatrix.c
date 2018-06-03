#include "GraphMatrix.h"

int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

GraphMatrix GRAPHinit(int v){
	GraphMatrix G = malloc(sizeof*G);
	
	G->v=v;
	G->a=0;
	
	G->adj=MATRIXint(v,v,0);
	
	return G;
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinsertArc() insere um arco v-w no grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */

void GRAPHinsertArc( GraphMatrix G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->a++;
   }
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc() remove do grafo G o arco v-w. A função supõe que v e w são distintos, positivos e menores que G->V. Se não existe arco v-w, a função não faz nada. */

void GRAPHremoveArc( GraphMatrix G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->a--;
   }
}
/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHshow() imprime, para cada vértice v do grafo G, em uma linha, todos os vértices adjacentes a v. */

void GRAPHshow( GraphMatrix G) { 
	if(G==NULL){
		printf("Grafo vazio!!");
		return;
		
	}
	printf("Endereco: %p\n",G);
	
   for (vertex v = 0; v < G->v; ++v) {
      printf( "%2d:", v);
      for (vertex w = 0; w < G->v; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

/*Retorna um vetor isSink, tal que  isSink[v] é true se e somente se v é um sorvedouro. */
int *soverdouros(GraphMatrix G){
	int vertices = G->v;
	int* isSink = malloc(sizeof(int)*vertices);
	for(int i=0;i<vertices;i++){
		isSink[i]=1;
	}
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			if(G->adj[i][j]==1){
				isSink[i]=0;
				break;
			}
		}

	}

	return isSink;
}

void imprimeSoverdouros(GraphMatrix G){
	
	int * v = soverdouros(G);
	int i;
	printf("\nVertices Soverdouros: ");
	
	for(i=0;i<G->v;i++){
		if (v[i]==1){
			printf("%d ",i);
		}
		
	}

}
/*Retorna um vetor isSource, tal que  isSource[v] é true se e somente se v é uma fonte. */
int *fontes(GraphMatrix G){
	int vertices = G->v;
	int* isSource = malloc(sizeof(int)*vertices);
	for(int i=0;i<vertices;i++){
		isSource[i]=1;
	}
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			if(G->adj[j][i]==1){
				isSource[i]=0;
				break;
			}
		}

	}

	return isSource;
}

void imprimeFontes(GraphMatrix G){
	
	int * v = fontes(G);
	int i;
	printf("\nVertices Fontes: ");
	
	for(i=0;i<G->v;i++){
		if (v[i]==1){
			printf("%d ",i);
		}
		
	}

}
void leArestas(GraphMatrix grafo,int qtd){
	int v,w;
	
	for(int i = 0 ;i<qtd;i++){
		scanf("%d%d",&v,&w);
		GRAPHinsertArc(grafo,v,w);
	}	
}
//Calcula o grau de entrada do vertice V(0 a V-1);
int GRAPHindeg(GraphMatrix grafo, int vertice){
	int num=0;
	for(int j=0;j<grafo->v;j++){
		num+=grafo->adj[j][vertice];
	}
	return num;
}

//Calcula o grau de saida do vertice V(0 a V-1);
int GRAPHoutdeg(GraphMatrix grafo, int vertice){
	int num=0;
	for(int j=0;j<grafo->v;j++){
		num+=grafo->adj[vertice][j];
	}
	return num;
}
/*Cria uma copia do grafo. Retorna o endereco de memoria */
GraphMatrix GRAPHcopy(GraphMatrix grafo){
	GraphMatrix copia = GRAPHinit(grafo->v);
	
	for(int v=0 ; v < copia->v ; v++){
		for( int w = 0 ; w < copia->v; w++){
			if(grafo->adj[v][w]){
				copia->adj[v][w]=1;
				copia->a++;
			}
		}
	}
	return copia;
	
}

void GRAPHdestroy(GraphMatrix *grafo){	
	for(int x = 0 ; x< (*grafo)->v; x++)
		free((*grafo)->adj[x]);
	free((*grafo)->adj);
	*grafo=NULL;
	
}
//Verifica se um grafo é consistente
bool GRAPHcheck(GraphMatrix grafo){
	for(int i=0 ; i < grafo->v ; i++){
		if(grafo->adj[i][i]==1)
			return false;
		
	}
	return true;
}

bool GRAPHequal(GraphMatrix g1,GraphMatrix g2){
	
	if(( g1->a != g2->a) || ( g1->v != g2->v ))
		return false;
		
	
	for(int i=0 ; i < g1->v ; i++)
		for(int j=0 ; j < g1->v ; j++)
			if(g1->adj[i][j] != g2->adj[i][j] ) 
				return false;
	
	return true;
}

