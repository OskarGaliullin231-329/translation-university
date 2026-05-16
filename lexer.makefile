CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -I include
# CXXFLAGS = -Wall -Werror -Wextra

SRCS = src/lexer.cpp src/preprocessor.cpp src/utility_funcs.cpp
MAIN_SRC = showcases/lexer_showcase.cpp

OBJS = $(SRCS:src/%.cpp=bin/%.o)
MAIN_OBJ = bin/lexer_showcase.o

TARGET = bin/lexer

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
