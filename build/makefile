CXX = g++
CXXFLAGS = -std=c++17
INCLUDEPATH = -I "C:/sfml/SFML-2.5.1/include"
LIBSPATH = -L "C:/sfml/SFML-2.5.1/lib"
LIBS = $(LIBSPATH) -lsfml-graphics -lsfml-window -lsfml-system

#Get all the source files from the src folder
SOURCES:=$(wildcard ../src/*.cpp)

#Create object files from matching source files
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

all: $(OBJECTS)
	$(CXX) $(OBJECTS) -o bin/game $(LIBS)

$(OBJECTS): ../src/%.o : ../src/%.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCLUDEPATH) $< -o $@

clean:
	rm -f ../src/*.o