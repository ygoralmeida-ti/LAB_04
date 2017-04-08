/**
*@file		taxaT3.cpp
*@brief		Arquivo contendo a implementacao de funcoes que calculam taxas
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/

#ifndef TAXAT3_H
#define TAXAT3_H

#include "estruturaT3.h"

/**
*@brief		Funcao que determinar a menor taxa de nascimento
*@param		*data ponteiro que aponta para info
*@param     &contaMunicipios passagem por referencia da quantidade de municipios
*@param     &ano1 passagem por referencia do ano1
*@param		&ano2 passagem por referencia do ano2
*@param		&anos passagem por referenca do intervalo analisado
*@return 	Municipio com a menor taxa e menor taxa	
*/
Retorno taxaDown(Stats *data, int &contaMunicipios, int &ano1, int &ano2, int &anos);

/**
*@brief		Funcao que determinar a maior taxa de nascimento
*@param		*data ponteiro que aponta para info
*@param     &contaMunicipios passagem por referencia da quantidade de municipios
*@param     &ano1 passagem por referencia do ano1
*@param		&ano2 passagem por referencia do ano2
*@param		&anos passagem por referenca do intervalo analisado
*@return 	Municipio com a maior taxa e maior taxa	
*/
Retorno taxaUp(Stats *data, int &contaMunicipios, int &ano1, int &ano2, int &anos);

#endif