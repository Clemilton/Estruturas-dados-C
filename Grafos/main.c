#include <stdio.h>
#include "GraphList.h"


int main (){
	
	int vertices;
	printf("Digite o numero de vertices: ");
	scanf("%d",&vertices);
	
	GraphList grafo = graphList_init(vertices);

	graphList_insertArc(grafo,0,1);
	graphList_insertArc(grafo,0,5);
	graphList_insertArc(grafo,1,0);
	graphList_insertArc(grafo,1,5);
	graphList_insertArc(grafo,2,4);
	graphList_insertArc(grafo,3,1);
	graphList_insertArc(grafo,5,3);


	graphList_show(grafo);

	graphList_imprimeFontes(grafo);
	graphList_imprimeSorverdouros(grafo);
	
	return 0;
}
