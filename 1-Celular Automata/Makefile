all:
	g++ ./source/automataNeuman.cpp ./source/automataMoore.cpp ./source/main.cpp ./source/plotting.cpp -o teste.o
run:
	g++ ./source/automataNeuman.cpp ./source/automataMoore.cpp ./source/main.cpp ./source/plotting.cpp -o teste.o
	./teste.o
clear:
	find . -type f -executable -exec rm '{}' \;

#   mingw32-make -f Makefile #Para funcionar no Windows, Linux será somente escrever no terminal "make", ou "make run", acho