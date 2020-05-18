stack : test.o 
	g++ -o stack test.o 

test.o : main.cpp stack.h
	g++ -c main.cpp

clean : 
	rm stack *.o
    