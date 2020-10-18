EXECS=matrixSPMD-PavelNichita
MPICC?=mpicc
CC=g++ -std=c++14 -Wall

all: erathostenes

erathostenes: erathostenes.cc NumberAndStatus.o Numbers.o
	${CC} -o $@ $^

Numbers.o: Numbers.h Numbers.cc
	${CC} -c Numbers.cc

NumberAndStatus.o: NumberAndStatus.h NumberAndStatus.cc
	${CC} -c NumberAndStatus.cc

clean:
	rm *.o erathostenes
