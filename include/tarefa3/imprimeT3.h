/**
*@file		imprimeT3.h
*@brief		Arquivo de cabecalho contendo a definicao de funcoes que geram
*			arquivos de saida
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/

#ifndef IMPRIMET3_H
#define IMPRIMET3_H

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <fstream>
using std::ofstream;

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
void imprimeEstatistica(int *big, int *small, double *avg, double *standardD, int anos);
/**
*@brief		Funcao que imprime dados do arquivo totais.csv
*@param		*tot apontador para total
*@param		anos numero de anos avaliados
*@return	void
*/

void imprimeTotais(int *tot, int anos);

/**
*@brief		Funcao que imprime dados do arquivo extra.dat
*@param		selecao aponta para selec
*@param		anos numero de anos avaliados
*@param		contaA	numero de alvos
*@return	void
*/
void imprimeDados(Rate* selecao,int anos, int contaA);

#endif