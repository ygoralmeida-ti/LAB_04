/**
*@file		imprimeT3.cpp
*@brief		Arquivo de corpo contendo a implementacao de funcoes que geram
*			arquivos de saida
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <fstream>
using std::ofstream;

#include "imprimeT3.h"
#include "estruturaT3.h"

/**
*@brief		Funcao que imprime dados do arquivo estatisticas.csv
*@param		*big apontador para maior
*@param		*small apontador para menor
*@param		*avg apontador para media
*@param		*standardD apontador para desvio
*@param		anos numero de anos avaliados
*@return	void
*/
void imprimeEstatistica(int *big, int *small, double *avg, double *standardD, int anos) {
	ofstream dadosSaida("../data/estatisticas.csv");
	if(!dadosSaida) {
		cerr << "Arquivo de saída não encontrado." << endl;
		exit(1);
	}
	for(int ii=0; ii<anos; ii++) {
		dadosSaida << (1994 + ii) << ";" << big[ii] << ";" << small[ii] << ";" << avg[ii] << ";" << standardD[ii] << endl;
	}

	cout << "... Arquivo estatisticas.csv gerado" << endl;
	dadosSaida.close();
	
}

/**
*@brief		Funcao que imprime dados do arquivo totais.csv
*@param		*tot apontador para total
*@param		anos numero de anos avaliados
*@return	void
*/
void imprimeTotais(int *tot, int anos){
	ofstream dadosSaida("../data/totais.dat");
	if(!dadosSaida) {
		cerr << "Arquivo de saída não encontrado." << endl;
		exit(1);
	}
	for(int ii=0; ii<anos; ii++) {
		dadosSaida << (1994 + ii) << " " << tot[ii] << endl;
	}

	cout << "... Arquivo totais.dat gerado" << endl;
	dadosSaida.close();
}

/**
*@brief		Funcao que imprime dados do arquivo extra.dat
*@param		selecao aponta para selec
*@param		anos numero de anos avaliados
*@param		contaA	numero de alvos
*@return	void
*/
void imprimeDados(Rate* selecao,int anos, int contaA) {
	
	int count = 0;
	int chk = 0;
	ofstream dadosSaida("../data/extra.dat");
	if(!dadosSaida) {
		cerr << "Arquivo de saída não encontrado." << endl;
		exit(1);
	}
	for(int ii=0; ii<anos; ii++) {
		for(int jj=0; jj<contaA; jj++) {
		

			if(chk == 0) {
				dadosSaida << (1995 + count++) << " ";
				chk = 1;
			}			
			//cout << selecao[jj].quantidades[ii] << endl;
			//getchar();
			dadosSaida << selecao[jj].taxa[ii];

			
			dadosSaida << " ";
			

		}

		dadosSaida << endl;
		chk -= 1;
	}
	dadosSaida.close();
}