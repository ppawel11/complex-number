test: test.o zespolona.o
	g++ test.o zespolona.o -o test
	rm *o
test.o: test.cpp
	g++ -c test.cpp
zespolona.o: zespolona.cpp
	g++ -c zespolona.cpp
