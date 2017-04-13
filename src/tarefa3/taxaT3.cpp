/**
*@file		taxaT3.cpp
*@brief		Arquivo contendo a implementacao de funcoes que calculam taxas
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/

#include "taxaT3.h"
#include "estruturaT3.h"
#include <iostream>
using std::cout;
using std::endl;

/**
*@brief		Funcao que determinar a menor taxa de nascimento
*@param		*data ponteiro que aponta para info
*@param     &contaMunicipios passagem por referencia da quantidade de municipios
*@param     &ano1 passagem por referencia do ano1
*@param		&ano2 passagem por referencia do ano2
*@param		&anos passagem por referenca do intervalo analisado
*@return 	Municipio com a menor taxa e menor taxa	
*/
Retorno taxaDown(Stats *data, int &contaMunicipios, int &ano1, int &ano2, int &anos) {
	Retorno voltando;
	int escolhendoAno1 = ano1 - 1994;
	int escolhendoAno2 = ano2 - 1994;
	double taxaMenor = (data[0].nascimentos[escolhendoAno2]*(1.0)/data[0].nascimentos[escolhendoAno1]);
	for(int ii=1; ii< contaMunicipios; ii++) {
		
		double taxa = (data[ii].nascimentos[escolhendoAno2]*(1.0)/data[ii].nascimentos[escolhendoAno1]);
		if(taxaMenor > taxa) {
			taxaMenor = taxa;
			voltando.municipio = data[ii].nome;
			voltando.taxa = 100 * (taxaMenor - 1);
		}
	}

	return voltando;

}

/**
*@brief		Funcao que determinar a maior taxa de nascimento
*@param		*data ponteiro que aponta para info
*@param     &contaMunicipios passagem por referencia da quantidade de municipios
*@param     &ano1 passagem por referencia do ano1
*@param		&ano2 passagem por referencia do ano2
*@param		&anos passagem por referenca do intervalo analisado
*@return 	Municipio com a maior taxa e maior taxa	
*/
Retorno taxaUp(Stats *data, int &contaMunicipios, int &ano1, int &ano2, int &anos) {
	Retorno voltando;
	int escolhendoAno1 = ano1 - 1994;
	int escolhendoAno2 = ano2 - 1994;
	double taxaMaior = (data[0].nascimentos[escolhendoAno2]*(1.0)/data[0].nascimentos[escolhendoAno1]);
	for(int ii=1; ii< contaMunicipios; ii++) {
		
		double taxa = (data[ii].nascimentos[escolhendoAno2]*(1.0)/data[ii].nascimentos[escolhendoAno1]);
		if(taxaMaior < taxa) {
			taxaMaior = taxa;
			voltando.municipio = data[ii].nome;
			voltando.taxa = 100 * (taxaMaior - 1);
		}
	}

	return voltando;

}

/**
*@brief		Funcao que determinar taxas de crescimento populacional
*@param		*selection ponteiro que aponta para selec
*@param		&anos passagem por referenca do intervalo analisado
*@param     &contaAlvos passagem por referencia do numero de municipios
*@return 	taxas de crescimento	
*/
Rate* processaTaxa(Dados* selection, int anos, int &contaAlvos) {
	
	Rate *valores = new Rate[contaAlvos];
	for(int jj = 0; jj<contaAlvos; jj++) {
		//cout << "JJ: " << jj << endl;
		for(int ii=0; ii<anos-1; ii++) {
			//cout << selection[jj].quantidades[ii+1] << "/" << selection[jj].quantidades[ii] << " = " <<  selection[jj].quantidades[ii+1]*(1.0)/selection[jj].quantidades[ii] << endl;
			valores[jj].taxa[ii] = 100*((selection[jj].quantidades[ii+1]*(1.0)/selection[jj].quantidades[ii])-1);
			//cout << ii << endl;
		}
	}

	return valores;

}