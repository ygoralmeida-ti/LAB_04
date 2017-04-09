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
all: tarefa1 tarefa2

debug: CFLAGS01 += -g -O0
debug: tarefa1 tarefa2

# Alvo (target) para a construcao do executavel tarefa1
# Define os arquivos mainT1.o, calcOperacoesT1.o e imprimeT1.o como dependencias
tarefa1: $(OBJ_DIR)/tarefa1/mainT1.o $(OBJ_DIR)/tarefa1/calcOperacoesT1.o $(OBJ_DIR)/tarefa1/imprimeT1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS01) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel tarefa1 criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto imprimeT1.o
# Define o arquivo imprimeT1.cpp e imprimeT1.h como dependencias.
$(OBJ_DIR)/tarefa1/imprimeT1.o: $(SRC_DIR)/tarefa1/imprimeT1.cpp $(INC_DIR01)/imprimeT1.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto calcOperacoesT1.o
# Define o arquivo calcOperacoesT1.cpp, calcOperacoesT1.h, estruturaT1.h como dependencias.
$(OBJ_DIR)/tarefa1/calcOperacoesT1.o: $(SRC_DIR)/tarefa1/calcOperacoesT1.cpp $(INC_DIR01)/estruturaT1.h $(INC_DIR01)/calcOperacoesT1.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto mainT1.o
# Define o arquivo mainT1.cpp, estruturaT1.h, calcOperacoesT1.h e imprimeT1.h como dependencias.
$(OBJ_DIR)/tarefa1/mainT1.o: $(SRC_DIR)/tarefa1/mainT1.cpp $(INC_DIR01)/estruturaT1.h $(INC_DIR01)/imprimeT1.h $(INC_DIR01)/calcOperacoesT1.h
	$(CC) -c $(CFLAGS01) -o $@ $<


#=======================================================================================


INC_DIR02=./include/tarefa2
CFLAGS02 = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR02)

# Alvo (target) para a construcao do executavel tarefa2
# Define os arquivos mainT2.o, calcOperacoesT2.o, imprimeT2.o, calcTaxaT2.o e taxaT2.o como dependencias
tarefa2: $(OBJ_DIR)/tarefa2/mainT2.o $(OBJ_DIR)/tarefa2/calcOperacoesT2.o $(OBJ_DIR)/tarefa2/imprimeT2.o $(OBJ_DIR)/tarefa2/calcTaxaT2.o $(OBJ_DIR)/tarefa2/taxaT2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS02) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel tarefa1 criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto taxaT2.o
# Define o arquivo taxaT2.cpp, taxaT2.h e estruturaT2.h como dependencias.
$(OBJ_DIR)/tarefa2/taxaT2.o: $(SRC_DIR)/tarefa2/taxaT2.cpp $(INC_DIR02)/taxaT2.h $(INC_DIR02)/estruturaT2.h
	$(CC) -c $(CFLAGS02) -o $@ $<

# Alvo (target) para a construcao do objeto calcTaxaT2.o
# Define o arquivo calcTaxaT2.cpp, calcTaxaT2.h, estruturaT2.h e taxaT2.h como dependencias.
$(OBJ_DIR)/tarefa2/calcTaxaT2.o: $(SRC_DIR)/tarefa2/calcTaxaT2.cpp $(INC_DIR02)/calcTaxaT2.h $(INC_DIR02)/estruturaT2.h $(INC_DIR02)/taxaT2.h
	$(CC) -c $(CFLAGS02) -o $@ $<

# Alvo (target) para a construcao do objeto imprimeT2.o
# Define o arquivo imprimeT2.cpp e imprimeT2.h como dependencias.
$(OBJ_DIR)/tarefa2/imprimeT2.o: $(SRC_DIR)/tarefa2/imprimeT2.cpp $(INC_DIR02)/imprimeT2.h
	$(CC) -c $(CFLAGS02) -o $@ $<

# Alvo (target) para a construcao do objeto calcOperacoesT2.o
# Define o arquivo calcOperacoesT2.cpp, calcOperacoesT2.h, estruturaT2.h como dependencias.
$(OBJ_DIR)/tarefa2/calcOperacoesT2.o: $(SRC_DIR)/tarefa2/calcOperacoesT2.cpp $(INC_DIR02)/estruturaT2.h $(INC_DIR02)/calcOperacoesT2.h
	$(CC) -c $(CFLAGS02) -o $@ $<

# Alvo (target) para a construcao do objeto mainT2.o
# Define o arquivo mainT2.cpp, estruturaT2.h, calcOperacoesT2.h, imprimeT2.h e calcTaxaT2.h como dependencias.
$(OBJ_DIR)/tarefa2/mainT2.o: $(SRC_DIR)/tarefa2/mainT2.cpp $(INC_DIR02)/estruturaT2.h $(INC_DIR02)/imprimeT2.h $(INC_DIR02)/calcOperacoesT2.h $(INC_DIR02)/calcTaxaT2.h
	$(CC) -c $(CFLAGS02) -o $@ $<

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