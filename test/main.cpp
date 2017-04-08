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

struct Stats {
	string codigo;
	string nome;
	int nascimentos[21];
};


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

	Stats *informacoes = new Stats[contaMunicipios];/**<alocacao dinamica para elementos do tipo Stats*/

	int count = 0;

	//letuira e armazenamento de dados e QC das linhas
	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	while(count < contaMunicipios) {

		entrada >> informacoes->codigo;

		int somaHorizontal = 0;

		getline(entrada, informacoes->nome, ';');

		for(int i=0; i<21; i++) {
			entrada >> informacoes->nascimentos[i]; entrada.ignore();
			somaHorizontal += informacoes->nascimentos[i];
			

		}
		int totalLinha = 0;
		entrada >> totalLinha;//elementos da ultima coluna

		if(somaHorizontal != totalLinha) {
			cout << "Inconsistencia entre dados e total no municipio: " << informacoes->nome << endl;
		}
		count++;
		informacoes += 1;
	}
	//QC das colunas
	
	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	count = 0;
	int somaVertical = 0;
	string str1;
	int totalH = 0;
	//Pulando elementos iniciais da linha
	getline(entrada, str1, ';');
	while(count <= contaMunicipios+1) {

		if(count == contaMunicipios+1) {
			
			//Pegando elementos da ultima linha
			for(int i=0; i<21; i++) {
				entrada >> totalH;
				entrada.ignore();
				
				//somando informacoes das colunas
				for(int k = 0; k<21; k++) {
					for(int j=0; j<contaMunicipios; j++) {
						somaVertical += informacoes->nascimentos[k];
						cout << "test" << endl;
					}
					if(somaVertical != totalH) {
						cout << "Inconsistencia entre dados e total no municipio: " <<(1994+k) << endl;
					}
					somaVertical = 0;
					informacoes +=1;
				}
			}
		}
		count++;
	}
		
	cout << contaMunicipios << endl;;
	entrada.close();
	return 0;		
}


	
	

