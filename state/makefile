PROGS=state_test
CPP=g++
CPPARGS=-Wall -c99

all: ${PROGS}

.cpp.o:
	${CPP} ${CPPARGS} $@ $^

state_test: state_test.cpp BoardState.cpp

clean:
	rm -f *.o ${PROGS}
