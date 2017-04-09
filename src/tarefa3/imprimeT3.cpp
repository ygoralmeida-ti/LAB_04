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

#include <fstream>
using std::ofstream;

#include "imprimeT3.h"

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
	for(int ii=0; ii<anos; ii++) {
		dadosSaida << (1994 + ii) << ";" << big[ii] << ";" << small[ii] << ";" << avg[ii] << ";" << standardD[ii] << endl;
	}

	cout << "... Arquivo estatisticas.csv gerado" << endl;
	
}

/**
*@brief		Funcao que imprime dados do arquivo totais.csv
*@param		*tot apontador para total
*@param		anos numero de anos avaliados
*@return	void
*/
void imprimeTotais(int *tot, int anos){
	ofstream dadosSaida("../data/totais.dat"); 
	for(int ii=0; ii<anos; ii++) {
		dadosSaida << (1994 + ii) << " " << tot[ii] << endl;
	}

	cout << "... Arquivo totais.dat gerado" << endl;
	
}

/**
*@brief		Funcao que imprime dados do arquivo extra.dat
*@param		selecao aponta para selec
*@param		anos numero de anos avaliados
*@param		contaA	numero de alvos
*@return	void
*/
void imprimeDados(Dados* selecao,int anos, int contaA) {
	
	int count = 0;
	ofstream dadosSaida("../data/extra.dat");
	
	for(int jj=0; jj<contaA; j++) {
		for(int ii=0; ii<anos; ii++) {

			if(jj == 0) {
				dadosSaida << (1994 + count++);
			}

			if(dadosSaida < conta-1) {
				dadosSaida << " ";
			}

			dadosSaida << selecao[ii].quantidades[jj];

		}

		dadosSaida << endl;
	}
}