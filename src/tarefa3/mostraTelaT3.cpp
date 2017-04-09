/**
*@file		mostraTelaT3.cpp
*@brief		Aquivo contendo a implementacao de funcao que imprime na tela o nome
*			do municipio selecionado
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		08/04/2017
*@date		08/04/2017
*/
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "mostraTelaT3.h"

/**
*@brief		Funcao que imprime na tela o nome do municipio selecionado
*@param     nome string relacionada ao nome do municipio
*@void
*/
void imprimeMunicipio(string nome) {
	cout << "......{ " << nome << " }" << endl;
}