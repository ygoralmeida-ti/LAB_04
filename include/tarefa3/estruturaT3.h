/**
*@file 		estruturaT3.h
*@brief		Definição dos structs usados
*@author	Ygor Almeida(ygorgeofisico@gmail.com)
*@since		06/04/2017
*@date		08/04/2017
*/

#ifndef ESTRUTURAT3_H
#define ESTRUTURAT3_H

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

/**
*@brief		Define struct de Retorno
*/
struct Retorno {
	string municipio;
	double taxa;
};

/**
*@brief		Define struct para a selecao de dados do caso extra
*/
struct Dados {
	int quantidades[21];
};

/**
*@brief		Define struct para as taxas do caso extra
*/
struct Rate {
	double taxa[20];
};

#endif