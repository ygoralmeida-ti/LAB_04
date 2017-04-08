/**
*@file		calcOperacoesT2.cpp
*@brief		Arquivo de corpo contendo a implementacao de funcoes para 
*			processar os dados do arquivo
*@author	Ygor Almeida(ygorgeifisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/

#include "estruturaT2.h"
#include "calcOperacoesT2.h"
#include <math.h>

/**
*@brief		Funcao que determinar o maior numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	maior numero de nascimentos em cada ano
*/
int* calcMaior(Stats *info, int &contaMunicipios, int anos) {

	int *max = new int[anos];//utiliando a heap

	int maior = info[0].nascimentos[0];

	for(int jj=0; jj<anos; jj++) {
		for(int ii=1; ii<contaMunicipios; ii++) {
		
			if(maior < info[ii].nascimentos[jj]) {
				maior = info[ii].nascimentos[jj];
			}
	
		}
		max[jj] = maior;
	}

	return max;
}

/**
*@brief		Funcao que determinar o menor numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	menor numero de nascimentos em cada ano
*/
int* calcMenor(Stats *info, int &contaMunicipios, int anos) {

	int *min = new int[anos];//utiliando a heap

	for(int jj=0; jj<anos; jj++) {
		int menor = info[jj].nascimentos[0];
		for(int ii=1; ii<contaMunicipios; ii++) {
		
			if(menor < info[ii].nascimentos[jj]) {
				menor = info[ii].nascimentos[jj];
			}
	
		}
		min[jj] = menor;
	}

	return min;

}

/**
*@brief		Funcao que determinar a media numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	media do numero de nascimentos em cada ano
*/
double* calcMedia(Stats *info, int &contaMunicipios, int anos) {
	double *media = new double[anos];//utiliando a heap

	double soma = 0.0;

	for(int jj=0; jj<anos; jj++) {
		for(int ii=1; ii<contaMunicipios; ii++) {
		
			soma += info[ii].nascimentos[jj];			
	
		}

		media[jj] = soma/contaMunicipios;
		soma = 0.0;

	}

	return media;

}

/**
*@brief		Funcao que determinar o desvio padrao do com relacao a media de
*			nascimentos de cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	desvio padrao de cada ano
*/
double* calcDesvio(Stats *info, int &contaMunicipios, int anos) {

	double *media = new double[anos];

	double soma = 0.0;

	//calculando media para o desvio padrao

	for(int jj=0; jj<anos; jj++) {
		for(int ii=1; ii<contaMunicipios; ii++) {
		
			soma += info[ii].nascimentos[jj];			
	
		}

		media[jj] = soma/contaMunicipios;
		soma = 0.0;

	}

	//desvio padrao

	double *desvio = new double[anos];

	double somatorio = 0.0;

	for(int jj=0; jj<anos; jj++) {
		for(int ii=1; ii<contaMunicipios; ii++) {
			
			somatorio += pow(info[ii].nascimentos[jj]-media[jj], 2);	
	
		}

		desvio[jj] = sqrt(somatorio*(1.0/contaMunicipios));

		somatorio = 0.0;

	}
	delete[] media;
	return desvio;

}

/**
*@brief		Funcao que determinar o total do numero de nascimentos em cada ano
*@param		*info apontador do tipo Stats
*@param		&contaMunicipio passagen referencia do numero de municipios
*@param		anos numero de anos
*@return	total do numero de nascimentos em cada ano
*/
int* calcTotal(Stats *info, int &contaMunicipios, int anos) {
	int *total = new int[anos];
	int soma = 0;
	for(int jj=0; jj<anos; jj++) {
		for(int ii=0; ii<contaMunicipios; ii++) {
			soma += info[ii].nascimentos[jj];
		}
		total[jj] = soma;
		soma = 0;
	}

	return total;
}