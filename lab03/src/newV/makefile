CC = cc

test_message : test_message.o
	cc -o test_message test_message.o

test_message.o : message.c message.h
	cc -c -o test_message.o message.c -DTEST_MESSAGE 

clean :
	rm *.o
