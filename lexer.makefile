CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -I include
# CXXFLAGS = -Wall -Werror -Wextra

SRCS = showcases/lexer_showcase.cpp src/lexer.cpp src/preprocessor.cpp src/utility_funcs.cpp

OBJS = $(SRCS:src/%.cpp=bin/%.o)

TARGET = bin/lexer

.INTERMEDIATE: $(OBJS)

all: $(TARGET)

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
