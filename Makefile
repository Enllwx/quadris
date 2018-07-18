CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -MMD -g
OBJECTS=block.o difficulty.o levelzero.o grid.o blockholder.o textdisplay.o test.o
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

# test:
# 	make
# 	cp ${EXEC} tests/${EXEC}-solution
# 	cd tests && runSuite ./${TEST_SUITE} ./${EXEC}-solution
# .PHONY: test

valgrind:
	make
	valgrind ./${EXEC}
.PHONY: valgrind
