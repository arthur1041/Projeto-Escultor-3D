# Compiler and flags
CXX = g++
CXXFLAGS = -Isrc/headers -std=c++17 -Wall -Wextra

# Diretórios
SRC_DIR = src
BUILD_DIR = build

# Busca recursiva por arquivos .cpp
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)

# Gera os objetos na pasta build com subdiretórios
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Nome do executável
TARGET = $(BUILD_DIR)/main

# Regra padrão (compilar o programa e executar)
all: $(TARGET)
	@echo "Running the program..."
	@if [ "$(OS)" = "Windows_NT" ]; then \
		$(TARGET).exe; \
	else \
		./$(TARGET); \
	fi

# Linka os objetos para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compila os arquivos .cpp em .o, criando os diretórios necessários
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@) # Cria o diretório do arquivo objeto, se necessário
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa os arquivos gerados
clean:
	rm -rf $(BUILD_DIR)

clear:
	rm -rf $(BUILD_DIR)

# Evita conflitos com arquivos reais chamados "all" ou "clean"
.PHONY: all clean
