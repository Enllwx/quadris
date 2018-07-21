# This is the Makefile for creating a3q3

# This is the compiler name
CXX = g++

# This variable will give the compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror=vla -Wpedantic -MMD -g

# This variable will give the linker flags
LINKER = ${CXX}


# $< will point the first file in the dependency chain
# $@ will point the last file in the dependency chain

# The name of the executable to produce
EXEC = quadris

# The SRC variable holds a list of all our *.cc files.
SRC = $(wildcard *.cc)

# The OBJECTS variable holds a list of object files that are produced.
# Each source file should be compiled into an object file.
OBJECTS = $(patsubst %.cc, %.o, $(SRC))

# List of the dependency files that G++ will produce. There should be one .d file
# for each .o file.
DEPENDS = $(OBJECTS:.o=.d)

# The first and default rule. This can be invoked by running 'make' or 'make program_name'
# In the rule the `$@` variable refers to the name of the target
# and `$+` refers to the list of files the rule depends on (in this case the OBJECT files)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $+

# This is an "implicit" rule for every object file. Each object file depends on
# the source file of the same name. In the rule the `$<` refers to the file it depends on
# (some source file) and `$@` refers to the name of the target (some object file).

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# The include directive will import in all of the rules in the .d files that g++
# creates for us.
-include $(DEPENDS)

# This will run the executable.
run: ${EXEC}
	./$<

# This runs the executable through valgrind. It is very useful for finding memory leaks.
memcheck: ${EXEC}
	valgrind --leak-check=full --dsymutil=yes ./$<

# This removes the dependency files, object files, the executable and
# the .dSYM directory that valgrind will generate.
clean:
	rm -f $(DEPENDS) $(OBJECTS) $(EXEC)
	rm -rf ${EXEC}.dSYM/ 
.PHONY: clean
# @ silences output
#test:
#    @cp ${EXECSDIR}/${EXECGIVEN} ${TESTDIR}                 # copy over given exec
#    @mv ${TESTDIR}/${EXECGIVEN} ${TESTDIR}/sol_${EXECGIVEN} # prefix it with sol_
#    @cp ${EXEC} ${TESTDIR}                                  # copy over your exec
#    @(cd ${TESTDIR}\                                        # go into test dir
#    && ./produceOutputs ${SUITE} ./sol_${EXECGIVEN}\        # run produceOutputs
#    && ./runSuite ${SUITE} ./${EXEC})                       # run runSuite
#.PHONY: test
