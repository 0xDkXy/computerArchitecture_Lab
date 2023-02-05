CC = cc

main : tunnel.o message.o main.o
	cc -o main main.o message.o tunnel.o -lpthread

main.o: main.c
	cc -c main.c

tunnal.o : tunnal.c
	cc -c tunnel.c

message.o : message.c
	cc -c message.c

test_message : test_message.o
	cc -o test_message test_message.o
    

test_message.o : message.c message.h
	cc -c -o test_message.o message.c -DTEST_MESSAGE 

clean :
	rm *.o
