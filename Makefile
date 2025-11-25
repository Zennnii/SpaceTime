# Compiler
CXX := g++
CXXFLAGS := -Wall -std=c++17 -Iinclude

# Libraries
LIBS := -lglfw3 -lglew32 -lopengl32 -lgdi32 -luser32 -lkernel32

# Source files (automatically find all .cpp in src/)
C_FILES := $(shell find src -name "*.cpp")
OBJ_FILES := $(C_FILES:.cpp=.o)

# Target executable
TARGET := SpaceTime

# Default rule
all: $(TARGET)

# Run
run:
	./spacetime.exe

# Link object files into executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $@ $(LIBS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ_FILES) $(TARGET)
                                                                                                                                                                                                                                                                                                                                                                                                                                  
.PHONY: all clean

#g++ -Iinclude src/main.cpp src/Window/Window.cpp -lglfw3 -lopengl32 -lgdi32 -o ParticleSimf