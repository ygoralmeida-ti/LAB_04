/**
*@file		selecionaT3.cpp
*@brief		Arquivo de corpo contando a implementacao de funcao que seleciona dados
*			a partir do codigo dos municipios
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date      08/04/2017	
*/
#include <cstdlib>
using std::atoi;

#include "selecionaT3.h"
#include "estruturaT3.h"
#include "mostraTelaT3.h"

/**
*@brief		Funcao que seleciona dados a partir do codigo dos municipios
*@param     coletaA ponteiro do tipo inteiro que aponta para coletaAlvos
*@param		info ponteiro do tipo Stats que aponta para informacao
*@param     &contaAlvos passagem por referencia de contaAlvos
*@param     &contaMunicipios passagem por referencia de contaMunicipios
*@param     anos intervalo de tempo no qual a analise e feita
*@return	dados selecionados a partir dos codigos dos municipios
*/
Dados* selecionaDados(int* coletaA, Stats* info, int &contaAlvos, int &contaMunicipios, int anos) {
	Dados *data = new Dados[contaAlvos];
	for(int ii=0; ii<contaAlvos; ii++) {
		for(int jj=0; jj<contaMunicipios; jj++) {
			int valor = atoi(info[jj].codigo);
			if(coletaA[ii] == valor) {
				imprimeMunicipio(info[jj].nome);
				for(int kk=0; kk<anos; kk++) {
					data[ii].quantidades[kk] = info[jj].nascimentos[kk];
				}
				break;
			}
			
		}
	}
	return data;
}