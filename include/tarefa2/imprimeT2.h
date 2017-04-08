/**
*@file		imprimeT2.cpp
*@brief		Arquivo de cabecalho contendo a definicao de funcoes que geram
*			arquivos de saida
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/

#ifndef IMPRIMET2_H
#define IMPRIMET2_H

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

/**
*@brief		Funcao que imprime dados do arquivo estatisticas.csv
*@param		*big apontador para maior
*@param		*small apontador para menor
*@param		*avg apontador para media
*@param		*standardD apontador para desvio
*@param		anos numero de anos avaliados
*@return	void
*/
void imprimeEstatistica(int *big, int *small, double *avg, double *standardD, int anos);
/**
*@brief		Funcao que imprime dados do arquivo totais.csv
*@param		*tot apontador para total
*@param		anos numero de anos avaliados
*@return	void
*/
void imprimeTotais(int *tot, int anos);

#endif