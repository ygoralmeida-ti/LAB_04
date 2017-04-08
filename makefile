#Makefile for "Laboratorio 4" C++ application
#Created by Ygor Almeida 08/04/2017

RM = rm -rf

# Compilador
CC=g++

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR01=./include/tarefa1
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

# Outras variaveis

# Opcoes de compilacao
CFLAGS01 = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR01)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug doc

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: tarefa1

debug: CFLAGS01 += -g -O0
debug: tarefa1

# Alvo (target) para a construcao do executavel tarefa1
# Define os arquivos mainT1.o como dependencias
tarefa1: $(OBJ_DIR)/tarefa1/mainT1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS01) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel tarefa1 criado em $(BIN_DIR)] +++"
	@echo "============="


# Alvo (target) para a construcao do objeto mainT1.o
# Define o arquivo mainT1.cpp e estruturaT1.h como dependencias.
$(OBJ_DIR)/tarefa1/mainT1.o: $(SRC_DIR)/tarefa1/mainT1.cpp $(INC_DIR01)/estruturaT1.h
	$(CC) -c $(CFLAGS01) -o $@ $<


#=======================================================================================


# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/tarefa?/*