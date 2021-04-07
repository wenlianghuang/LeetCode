CC:=g++
CXXFLAGS=-g -m64 -O2 -Wall -std=c++14

.PHONY: WS clean clear
src=$(wildcard ./src/*.cxx)
directory=$(notdir $(src))
obj := $(patsubst %.cxx,%.o,$(directory))

all 	:	WS 	

WS 	:	$(obj)
	$(CC) $^ -o $@
main.o	:	./src/main.cxx  
	$(CC) -c $(CXXFLAGS) $< -o $@ 
Solution.o	:	./src/Solution.cxx ./inc/Solution.h
	$(CC) -c $(CXXFLAGS) $< -o $@

clean:clear

clear:
	rm -rf *.o
