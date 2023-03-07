#
# PROGRAM:   assign6
# AUTHOR:    Noah Allen
# LOGON ID:  z1888906
# DUE DATE:  March 9th, 2023
#

# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic -std=c++14

# Rule to link object code files to create executable file
assign6: assign6.o matrix.o
	$(CXX) $(CCFLAGS) -o assign6 $^

# Rules to compile source code files to object code
assign6.o: assign6.cpp matrix.h
matrix.o: matrix.cpp matrix.h

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign6 *.o
