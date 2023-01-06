CC = g++
huffman : huffman_coding.o main.o 
	${CC} -o huffman main.o huffman_coding.o

main.o : main.cpp huffman_coding.h
	${CC} -c main.cpp

huffman_coding.o : huffman_coding.cpp huffman_coding.h
	${CC} -c huffman_coding.cpp

clean : 
	rm main.o huffman_coding.o