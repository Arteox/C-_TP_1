Final: Ensemble.o Test.o
	g++ -o Final  Ensemble.o  Test.o
	valgrind --leak-check=yes  Final

Ensemble.o: Ensemble.cpp Ensemble.h
	g++ -c Ensemble.cpp -o Ensemble.o

Test.o: Test.cpp
	g++ -c Test.cpp -o Test.o

