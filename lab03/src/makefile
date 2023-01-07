CC = cc

pipeline : pipeline.o main.o
	cc -o pipeline pipeline.o main.o -lpthread

main.o : main.c pipeline.h
	cc -c main.c 

pipeline.o : pipeline.c pipeline.h
	cc -c pipeline.c 

clean :
	rm *.o