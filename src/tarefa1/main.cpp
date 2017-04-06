/**
*@file 		main.cpp
*@brief		Programa principal para as tarefas do lab_04
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		06/04/2017
*@date		06/04/2017
*/

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cerr;
using std::endl;
using std::cout;
using std::endl;

#include <cstdlib>

#include <string>
using std::string;

#include "estrutura.h"

int main(int argc, char *argv[]) {

	string codigoMunicipio;
	int contaMunicipios = 0;

	ifstream entrada(argv[1]);
	if(!entrada) {
		cerr << "O arquivo de entrada nao foi encontrado!" << endl;
	}

	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	while(getline(entrada, codigoMunicipio)) {
		//cout << codigoMunicipio << endl;
		contaMunicipios++;
		
	}
	contaMunicipios -= 1;

	Stats *informacoes = new Stats[contaMunicipios];

	int count = 0;

	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	while(count < contaMunicipios) {
		entrada >> informacoes.codigo;

		getline(entrada, informacoes.nome, ";");
		for(int i=0; i<21, i++) {
			entrada >> informacoes.nascimento[i];
			entrada.ignore();
		}

	}



	
	cout << contaMunicipios << endl;;
	entrada.close();
	return 0;
}