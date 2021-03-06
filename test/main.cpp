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

#include <string>
using std::string;
using std::stoi;

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
		return 0;
	}

	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	while(getline(entrada, codigoMunicipio)) {
		//cout << codigoMunicipio << endl;
		contaMunicipios++;
		
	}
	contaMunicipios -= 1;

	Stats *informacoes = new Stats[contaMunicipios];/**<alocacao dinamica para elementos do tipo Stats*/

	int count = 0; /**<variavel de controle para leitura dos dados*/
	string str2; /**<variavel para avaliar entradas dos valores*/

	entrada.clear();
	entrada.seekg(entrada.beg);

	int ii=0;

	//letuira e armazenamento de dados e QC das linhas
	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	while(count < contaMunicipios) {

		entrada >> informacoes[ii].codigo;
		//cout << informacoes->codigo << endl;		

		getline(entrada, informacoes[ii].nome, ';');

		int somaHorizontal = 0;

		//cout << informacoes->nome << endl;
		for(int i=0; i<21; i++) {
			getline(entrada, str2, ';');
			
			if(str2 == "-") {
				str2 = "0";
			}
			int avaliando = stoi(str2);		
						
			informacoes[ii].nascimentos[i] = avaliando;
			//cout << avaliando << endl;
			//getchar();
									
			somaHorizontal += informacoes[ii].nascimentos[i];			

		}

		int totalLinha = 0;
		entrada >> totalLinha;//elementos da ultima coluna
		//cout << "Total: " << totalLinha << endl;
		//cout << "somaH: " << somaHorizontal << endl;
		if(somaHorizontal != totalLinha) {
			cout << "Inconsistencia entre dados e total no municipio: " << informacoes->nome << endl;
			return 0;

		}
		count++;
		//informacoes += 1;
		ii++;
	}
	
	//cout << informacoes[0].nascimentos[0] << endl;
	//QC das colunas
	
	entrada.clear();
	entrada.seekg(entrada.beg);

	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	count = 0;
	int somaVertical = 0;
	string str1;
	int totalH = 0;

	while(count < (contaMunicipios+2)) {		
		
		if(count == contaMunicipios) {
			//cout << "test" << endl;
			//Pulando elementos iniciais da linha
			getline(entrada, str1, ';');
			//cout << str1 << endl;
			//Pegando elementos da ultima linha
			for(int i=0; i<21; i++) {
				getline(entrada, str1, ';');
				totalH = stoi(str1);
				//cout << "Total: " << totalH << endl;
				//getchar();
				//somando informacoes das colunas
				
				for(int j=0; j<contaMunicipios; j++) {
					//cout << informacoes[j].nascimentos[i] << endl;
					//getchar();
					somaVertical += informacoes[j].nascimentos[i];
					//cout << "somaH: " << somaVertical << endl;

				}
				//cout << "soma: " << somaVertical << endl;
				//cout << "Total: " << totalH << endl;
				//cout << "somaH: " << somaVertical << endl;
				if(somaVertical != totalH) {
					cout << "Inconsistencia entre dados e total no municipio: " <<(1994+i) << endl;
					return 0;
				}
			somaVertical = 0;
			//informacoes +=1;
				
			}
		}
		count++;
		getline(entrada, codigoMunicipio);
	}
		
	cout << contaMunicipios << endl;;
	entrada.close();
	return 0;		
}


	
	

