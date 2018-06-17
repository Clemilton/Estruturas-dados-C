all:	GraphMatrix.o GraphList.o main.o
	gcc -o main GraphMatrix.o GraphList.o main.o

GraphMatrix.o:	GraphMatrix.c
	gcc -c GraphMatrix.c

GraphList.o: GraphList.c
	gcc -c GraphList.c

main.o: main.c
	gcc -c main.c
	
clean:
	rm -rf *.o

vai:
	./main.o
