test: test.o complex.o
	g++ test.o complex.o -o test
	rm *o
test.o: test.cpp
	g++ -c test.cpp
complex.o: complex.cpp
	g++ -c complex.cpp
