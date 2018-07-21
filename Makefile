CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -MMD -g
OBJECTS=block.o difficulty.o levelzero.o levelone.o leveltwo.o levelthree.o levelfour.o grid.o blockholder.o textdisplay.o hintgenerator.o score.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=quadris
TEST_SUITE=quadris.txt

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean

zip:
	zip ${EXEC}.zip *
.PHONY: zip

run:
	make
	./${EXEC}
.PHONY: run

valgrind:
	make
	valgrind ./${EXEC}
.PHONY: valgrind
