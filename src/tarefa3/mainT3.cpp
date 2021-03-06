/**
*@file 		mainT3.cpp
*@brief		Programa principal para as tarefas do lab_04
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		06/04/2017
*@date		08/04/2017
*/

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cerr;
using std::endl;
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;
using std::stoi;

#include "estruturaT3.h"
#include "calcOperacoesT3.h"
#include "imprimeT3.h"
#include "calcTaxaT3.h"
#include "selecionaT3.h"
#include "taxaT3.h"

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
		
		contaMunicipios++;
		
	}
	contaMunicipios -= 1;

	Stats *informacoes = new Stats[contaMunicipios];/**<alocacao dinamica para elementos do tipo Stats*/

	int count = 0; /**<variavel de controle para leitura dos dados*/
	string str1; /**<variavel para avaliar entradas dos valores*/

	entrada.clear();
	entrada.seekg(entrada.beg);

	int ii=0; /**<variavel de controle para leitura dos dados*/

	//letuira e armazenamento de dados e QC das linhas
	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	while(count < contaMunicipios) {

		entrada >> informacoes[ii].codigo;		

		getline(entrada, informacoes[ii].nome, ';');

		int somaHorizontal = 0; /**<soma dos valores na linha*/

		for(int i=0; i<21; i++) {
			getline(entrada, str1, ';');
			
			if(str1 == "-") {
				str1 = "0";
			}
			int avaliando = stoi(str1);		
						
			informacoes[ii].nascimentos[i] = avaliando;
								
			somaHorizontal += informacoes[ii].nascimentos[i];			

		}

		int totalLinha = 0; /**<total da soma das iformacoes na linha segundo a tabela*/
		entrada >> totalLinha;//elementos da ultima coluna
		
		if(somaHorizontal != totalLinha) {
			cout << "Inconsistencia entre dados e total no municipio: " << informacoes->nome << endl;
			return 0;

		}
		count++;
		
		ii++;
	}
	
	//QC das colunas
	
	entrada.clear();
	entrada.seekg(entrada.beg);

	getline(entrada, codigoMunicipio);//pula primeira linha do arquivo de dados
	count = 0;
	int somaVertical = 0; /**<soma dos valores na coluna*/
	string str2; /**<variavel para avaliar entradas dos valores*/
	int totalV = 0; /**<total da soma das iformacoes na coluna segundo a tabela*/

	while(count < (contaMunicipios+2)) {		
		
		if(count == contaMunicipios) {
			
			//Pulando elementos iniciais da linha
			getline(entrada, str2, ';');
			
			//Pegando elementos da ultima linha
			for(int i=0; i<21; i++) {
				getline(entrada, str2, ';');
				totalV = stoi(str2);
				
				for(int j=0; j<contaMunicipios; j++) {
					
					somaVertical += informacoes[j].nascimentos[i];
				
				}
				
				if(somaVertical != totalV) {
					cout << "Inconsistencia entre dados e total no municipio: " <<(1994+i) << endl;
					return 0;
				}
			somaVertical = 0;
			
			}
		}
		count++;
		getline(entrada, codigoMunicipio);
	}
	entrada.close();

	int *maior = new int[21];
	int *menor = new int[21];
	double *media = new double[21];
	double *desvio = new double[21];
	int *totalNascido = new int[21];

	maior = calcMaior(informacoes, contaMunicipios, 21);
	menor = calcMenor(informacoes, contaMunicipios, 21);
	media = calcMedia(informacoes, contaMunicipios, 21);
	desvio = calcDesvio(informacoes, contaMunicipios, 21);
	totalNascido = calcTotal(informacoes, contaMunicipios, 21);

	imprimeEstatistica(maior, menor, media, desvio, 21);

	imprimeTotais(totalNascido, 21);

	delete[] maior;
	delete[] menor;
	delete[] media;
	delete[] desvio;
	delete[] totalNascido;

	int ano1, ano2;

	do {
	cout << "Entre com os dois anos que deseja comparar: ";
	cin >> ano1;
	cin >> ano2;

	if(ano1 < 1994 || ano1 > 2014 || ano2 < 1994 || ano2 > 2014 || ano1 == ano2) {
		cout << "Digite valores de anos entre 1994 e 2014. Os dois valores nao podem ser iguais" << endl;
	}

	} while(ano1 < 1994 || ano1 > 2014 || ano2 < 1994 || ano2 > 2014 || ano1 == ano2);

	calcTaxaDown(informacoes, contaMunicipios, ano1, ano2, 21);

	calcTaxaUp(informacoes, contaMunicipios, ano1, ano2, 21);
	
	//Parte extra

	ifstream alvos("../data/alvos.dat");
	if(!alvos) {
		cerr << "O arquivo de alvos nao foi encontrado!" << endl;
		return 0;
	}

	cout <<"... Lendo arquivo alvos.dat" << endl;

	int contaAlvos = 0;
	string codigoAlvos;
	while(getline(alvos, codigoAlvos)) {
		
		contaAlvos++;
		
	}

	cout << "......[" << contaAlvos <<"] " << "municipios definidos como alvo" << endl;

	alvos.clear();
	alvos.seekg(alvos.beg);

	int *coletaAlvos = new int[contaAlvos];

	for(int ii=0; ii<contaAlvos; ii++) {
		alvos >> coletaAlvos[ii];
	}

	Dados *selec = new Dados[contaAlvos]; /**<dados selecionados com base no alvos.dat*/

	selec = selecionaDados(coletaAlvos, informacoes, contaAlvos, contaMunicipios, 21);
	delete[] informacoes;

	Rate *mostra = new Rate[contaAlvos]; /**<taxas para os alvos*/

	mostra = processaTaxa(selec, 21, contaAlvos);
	delete[] selec;

	imprimeDados(mostra, 21-1, contaAlvos);

	delete[] mostra;	
	delete[] coletaAlvos;
	
	
	return 0;		
}