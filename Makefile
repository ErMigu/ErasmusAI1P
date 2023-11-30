# Definir el compilador
CXX = g++
# Definir las banderas de compilación
CXXFLAGS = -Wall -g

# Lista de archivos .cpp (como dependencias)
CPP_FILES := $(wildcard *.cpp)

# Sustituir la extensión .cpp por .o para los archivos objeto
OBJ_FILES := $(CPP_FILES:.cpp=.o)

# Nombre del ejecutable
EXECUTABLE := erasmusAI

all: $(EXECUTABLE)

# Regla para enlazar los archivos objeto en el ejecutable final
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos .cpp en archivos .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regla para limpiar los archivos compilados
clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)

.PHONY: all clean
