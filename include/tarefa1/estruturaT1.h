/**
*@file 		estruturaT1.h
*@brief		Definição do struct
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		06/04/2017
*@date		06/04/2017
*/

#ifndef ESTRUTURAT1_H
#define ESTRUTURAT1_H

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