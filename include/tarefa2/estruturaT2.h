/**
*@file 		estruturaT2.cpp
*@brief		Definição do struct
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		06/04/2017
*@date		06/04/2017
*/

#ifndef ESTRUTURAT2_H
#define ESTRUTURAT2_H

#include <string>
using std::string;

/**
*@brief		Definindo struct Stats
*/
struct Stats {
	string codigo;
	string nome;
	int nascimentos[21];
};

#endif