target 	:= main 
OBJDIR  := ./build/ 
objs 	:=  
CC 		:= g++
CFLAGS 	:= -g -Wall -lm -pthread

all: $(target)
run: $(target)
	./$(target)
deps := $(patsubst %.o, %.d, $(objs))
# -include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

main: $(objs)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: ./source/%.cpp	
	$(CC) $(CFLAGS) -c  $<  -o $@ $(DEPFLAGS)

clean:
	rm -f $(target) $(objs) $(deps)



#   mingw32-make -f Makefile #Para funcionar no Windows, Linux será somente escrever no terminal "make", ou "make run", acho