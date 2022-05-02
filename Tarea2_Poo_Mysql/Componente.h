#pragma once
#include <iostream>
using namespace std;
class Componente{
	//atributos
protected: string marca;
	//constructor
protected:
	Componente(){}
	Componente(string mar) {
		marca = mar;
	}
};
