UNAME := $(shell uname)

#ifeq($(UNAME),Linux)
all:
	g++ -pthread -g -Wall -lm ./source/main.cpp ./source/functions.cpp ./source/System.cpp -o main.o
run:
	g++ -pthread -g -Wall -lm ./source/main.cpp ./source/functions.cpp ./source/System.cpp -o main.o
	./main.o
clear:
	find . -type f -executable -exec rm '{}' \;
#endif

#   mingw32-make -f Makefile #Para funcionar no Windows, Linux será somente escrever no terminal "make", ou "make run", acho