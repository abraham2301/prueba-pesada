#pragma once
#include <iostream>
using namespace std;
class Elemento
{
	//atributos
protected: int id_marca, existencia;
		 string producto, fecha_ingreso, descripcion;
		 float precio_costo, precio_venta;
		 //constructor
protected:
	Elemento() {
	}

	Elemento(int idmarca, int exis, string produc, string fechaingreso, string descrip, float preciocosto, float precioventa ) {
		id_marca = idmarca;
		existencia = exis;
		producto = produc;
		fecha_ingreso = fechaingreso;
		descripcion = descrip;
		precio_costo = preciocosto;
		precio_venta = precioventa;

	}

	void mostrar();
};


