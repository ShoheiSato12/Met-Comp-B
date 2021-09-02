all:
	g++ -pthread -g -Wall -lm ./source/main.cpp ./source/functions.cpp -o main.o
run:
	g++ -pthread -g -Wall -lm ./source/main.cpp ./source/functions.cpp -o main.o
	./main.o
clear:
	find . -type f -executable -exec rm '{}' \;



#   mingw32-make -f Makefile #Para funcionar no Windows, Linux será somente escrever no terminal "make", ou "make run", acho