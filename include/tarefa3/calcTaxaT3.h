/**
*@file 		calcTaxaT3.cpp
*@brief		Arquivo de cabecalho contendo a definicao de funcoes que passam
*			parametros para outras funcoes, e apos o retorno dessas, exibem
*			os resultados na tela
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017		
*/

#ifndef CALCTAXAT3_H
#define CALCTAXAT3_H

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setprecision;

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
void calcTaxaDown(Stats *info, int &contaMunicipios, int &ano1, int &ano2, int anos);

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
void calcTaxaUp(Stats *info, int &contaMunicipios, int &ano1, int &ano2, int anos);

#endif