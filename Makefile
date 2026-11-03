# Compilation : make        Exécution : make run        Nettoyage : make clean
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic
SRC      = $(wildcard src/*.cpp)
TARGET   = rencontres

$(TARGET): $(SRC) $(wildcard src/*.h)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: run clean
