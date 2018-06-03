#include <stdio.h>
#include "GraphMatrix.h"

int main (){
	
	int vertices;
	printf("Digite o numero de vertices: ");
	scanf("%d",&vertices);
	
	GraphMatrix grafo = GRAPHinit(vertices);
	
	leArestas(grafo,7);
	GraphMatrix copia = GRAPHcopy(grafo);
	
	printf("%d",GRAPHequal(grafo,copia));
	
	return 0;
}
