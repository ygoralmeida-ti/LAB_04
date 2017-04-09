/**
*@file 		calcTaxaT3.cpp
*@brief		Arquivo de corpo contendo a implementacao de funcoes que passam
*			parametros para outras funcoes, e apos o retorno dessas, exibem
*			os resultados na tela
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017		
*/

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;

#include "calcTaxaT3.h"
#include "estruturaT3.h"
#include "taxaT3.h"

#include <string>

/**
*@brief		Funcao que passa parametros para outra funcao realizar os processos
*			de avaliacao de taxas de crescimento. Apos o retorno dessa funcao,
*			os resultados de menor taxa sao exibidos na tela
*@param     *info ponteiro que aponta para informacao
*@param     &contaMunicipios passagem por referencia de contaMunicipios
*@param     &ano1 passagem por referencia de ano1
*@param     &ano2 passagem por referencia de ano2
*@param     anos intervalo dos anos analisados
*@return 	void
*/
void calcTaxaDown(Stats *info, int &contaMunicipios, int &ano1, int &ano2, int anos) {
	Retorno retornoMenor = taxaDown(info, contaMunicipios, ano1, ano2, anos);
	int tamanho = retornoMenor.municipio.size();
	retornoMenor.municipio.erase(retornoMenor.municipio.begin()+(tamanho-1));
	if(retornoMenor.taxa>0) {
		cout << "Municipio com maior taxa de queda " << ano1 << "-" << ano2 << ": " << retornoMenor.municipio << " " << "(+" << setprecision(4) << retornoMenor.taxa <<"%)"<< endl;
	} else {
		cout << "Municipio com maior taxa de queda " << ano1 << "-" << ano2 << ": " << retornoMenor.municipio << " " << "(" << setprecision(4) << retornoMenor.taxa <<"%)"<< endl;
	}	
}

/**
*@brief		Funcao que passa parametros para outra funcao realizar os processos
*			de avaliacao de taxas de crescimento. Apos o retorno dessa funcao,
*			os resultados de maior taxa sao exibidos na tela
*@param     *info ponteiro que aponta para informacao
*@param     &contaMunicipios passagem por referencia de contaMunicipios
*@param     &ano1 passagem por referencia de ano1
*@param     &ano2 passagem por referencia de ano2
*@param     anos intervalo dos anos analisados
*@return 	void
*/
void calcTaxaUp(Stats *info, int &contaMunicipios, int &ano1, int &ano2, int anos) {
	Retorno retornoMaior = taxaUp(info, contaMunicipios, ano1, ano2, anos);
	int tamanho = retornoMaior.municipio.size();
	retornoMaior.municipio.erase(retornoMaior.municipio.begin()+(tamanho-1));
	if(retornoMaior.taxa > 0) {
		cout << "Municipio com maior taxa de crescimento " << ano1 << "-" << ano2 << ": " << retornoMaior.municipio << " " << "(+" << setprecision(5) << retornoMaior.taxa <<"%)"<< endl;
	} else {
		cout << "Municipio com maior taxa de crescimento " << ano1 << "-" << ano2 << ": " << retornoMaior.municipio << " " << "(" << setprecision(5) << retornoMaior.taxa <<"%)"<< endl;
	}
}