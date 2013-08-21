# 
# Section containing macros.
#
FLEX = flex
BISON = bison

FNB = f_n_b
HEAD = headers
SRC = src
GTL = gt/gtl

FNB_BUILT = $(HEAD)/$(GTL)/parser.hpp $(SRC)/$(GTL)/parser.cpp $(SRC)/$(GTL)/scanner.cpp $(SRC)/$(GTL)/location.hh $(SRC)/$(GTL)/position.hh $(SRC)/$(GTL)/stack.hh

# Build everything.
all : parser_code

# 
# Section responsible for building C++ parser and scanner of GTL.
# 

# Generate C++ scanner (.cpp only).
$(SRC)/$(GTL)/scanner.cpp : $(FNB)/scanner.l
	$(FLEX) $(FNB)/scanner.l

# Generates C++ parser (.cpp and .hpp).
$(HEAD)/$(GTL)/parser.hpp $(SRC)/$(GTL)/parser.cpp : $(FNB)/parser.y
	$(BISON) --defines=$(HEAD)/$(GTL)/parser.hpp --output=$(SRC)/$(GTL)/parser.cpp $(FNB)/parser.y

# Build parser's classes - both scanner and actual parser.
bison : $(FNB_BUILT)

#Removes parser's classes.
bison_clean :
	rm -f $(FNB_BUILT)
