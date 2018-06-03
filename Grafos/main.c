#include <stdio.h>
#include "GraphList.h"
#include "GraphMatrix.h"

int main (){
	
	int vertices;
	printf("Digite o numero de vertices: ");
	scanf("%d",&vertices);
	
	GraphList grafo = graphList_init(vertices);
	
	graphList_insertArc(grafo,1,0);
	
	return 0;
}
