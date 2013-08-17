# Build everything.
all : parser_code

# 
# Section responsible for building C++ parser and scanner of GTL.
# 

# Build parser's classes - both scanner and actual parser.
parser_code : src/gtl/parser.cpp src/gtl/parser.hpp src/gtl/scanner.cpp

# Generate C++ scanner.
src/gtl/scanner.cpp : src/gtl/f_n_b/scanner.l
	flex --verbose --outfile=src/gtl/scanner.cpp src/gtl/f_n_b/scanner.l

# Generates C++ parser.
src/gtl/parser.cpp src/gtl/parser.hpp : src/gtl/f_n_b/parser.y
	bison --verbose --output=src/gtl/parser.cpp --defines=src/gtl/parser.hpp src/gtl/f_n_b/parser.y

#Removes parser's classes.
parser_clean :
	rm -f src/gtl/parser.cpp src/gtl/parser.hpp src/gtl/scanner.cpp
