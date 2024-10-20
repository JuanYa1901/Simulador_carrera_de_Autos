# Definimos el compilador y las banderas de compilación
CXX = g++
CXXFLAGS = -std=c++11 -pthread

# Nombre del archivo ejecutable
EXEC = carrera

# Archivos fuente
SRC = Tarea_1.cpp  

# Regla por defecto para compilar
all: $(EXEC)

# Regla para crear el ejecutable
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

# Regla para limpiar archivos generados
clean:
	rm -f $(EXEC)
