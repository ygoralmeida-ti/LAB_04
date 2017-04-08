/**
*@file		imprimeT2.cpp
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

#include "imprimeT2.h"

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