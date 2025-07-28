CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

TARGET = sss
SRC = src/sss.cpp test/main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
