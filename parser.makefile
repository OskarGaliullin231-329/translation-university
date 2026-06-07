CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -I include
# CXXFLAGS = -Wall -Werror -Wextra

SRCS = src/parser.cpp src/lexer.cpp src/preprocessor.cpp src/utility_funcs.cpp src/AST.cpp src/ASTNode.cpp src/Expression.cpp src/Statement.cpp src/ExpressionDerivatives.cpp src/StatementDerivatives.cpp
MAIN_SRC = showcases/parser_showcase.cpp

OBJS = $(SRCS:src/%.cpp=bin/%.o)
MAIN_OBJ = bin/parser_showcase.o

TARGET = bin/parser

.INTERMEDIATE: $(OBJS) $(MAIN_OBJ)

all: $(TARGET)

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(MAIN_OBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)
