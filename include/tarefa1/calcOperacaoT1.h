/**
*@file		calcOperacoesT1.h
*@brief		Arquivo de cabecalho contendo a definicao de funcoes para 
*			processar os dados do arquivo
*@author	Ygor Almeida(ygorgeifisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/

#ifndef CALCOPERACAOT1_H
#define CALCOPERACAOT1_H

#include "calcOperacoesT1.h"
#include <math.h>

/**
*@brief		Funcao que determinar o maior numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	maior numero de nascimentos em cada ano
*/
int* calcMaior(Stats *info, int &contaMunicipios, int anos);

/**
*@brief		Funcao que determinar o menor numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	menor numero de nascimentos em cada ano
*/
int* calcMenor(int *info, int &contaMunicipios, int anos);

/**
*@brief		Funcao que determinar a media numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	media do numero de nascimentos em cada ano
*/
double* calcMedia(int *info, int &contaMunicipios, int anos);

/**
*@brief		Funcao que determinar o desvio padrao do com relacao a media de
*			nascimentos de cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	desvio padrao de cada ano
*/
double* calcDesvio(int *info, int &contaMunicipios, int anos);

/**
*@brief		Funcao que determinar o total do numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	total do numero de nascimentos em cada ano
*/
int* calcTotal(int *info, int &contaMunicipios, int anos);

#endif