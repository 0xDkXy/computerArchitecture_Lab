CC = cc

LRU : LRU.o main.o
	${CC} -o LRU LRU.o main.o

main.o : main.c LRU.h
	${CC} -c main.c

LRU.o : LRU.c LRU.h
	${CC} -c LRU.c

clean : 
	rm *.o
