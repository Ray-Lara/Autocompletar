# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -O0 -g -ansi -pedantic -std=c++11

# Arquivo de saída
EXECUTABLE = prog

# Arquivos fonte
SOURCES = main.cpp Termo.cpp Autocompletar.cpp

# Arquivos de cabeçalho
HEADERS = Termo.h Autocompletar.h Lista.h

# Regras padrão (all)
all: $(EXECUTABLE)

# Regra para compilar arquivos .cpp em arquivos .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para criar o executável a partir dos arquivos .o
$(EXECUTABLE): $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE)

# Limpeza dos arquivos gerados
clean:
	rm -f $(EXECUTABLE) *.o
