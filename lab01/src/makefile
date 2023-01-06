huffman : huffman_coding.o main.o 
	g++ -o huffman main.o huffman_coding.o

main.o : main.cpp huffman_coding.h
	g++ -c main.cpp

huffman_coding.o : huffman_coding.cpp huffman_coding.h
	g++ -c huffman_coding.cpp

clean : 
	rm main.o huffman_coding.o