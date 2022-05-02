#pragma once
#include "Elemento.h"
#include <mysql.h>
#include "ConexionBD.h"
#include "Componente.h"
#include <iostream>
#include <string>
#include "Prueba.h"
#include "Felicidades.h"
using namespace std;
class Menu :Componente,Elemento, Prueba, Felicidades{

	//constructor
public:
	Menu(){
	}

	Menu(int idmarca, int exis, string produc, string fechaingreso, string descrip, float preciocosto, float precioventa): Elemento(id_marca, exis, produc, fechaingreso, descrip, preciocosto, precioventa) {
	}
	Menu(string mar) :Componente(mar) {
	}
	Menu(int idproducto1) :Prueba(idproducto1) {
	}

	//metodos
	//set (modificar)
	void setID_marca(int idmarca) { id_marca = idmarca; }
	void setExistencia(int exis) { existencia = exis; }
	void setProducto(string produc) { producto = produc; }
	void setFecha_ingreso(string fechaingreso) { fecha_ingreso=fechaingreso; }
	void setDescripcion(string descrip) { descripcion=descrip; }
	void setPrecio_costo(float preciocosto) { precio_costo=preciocosto; }
	void setPrecio_venta(float precioventa) { precio_venta=precioventa; }
	void setMarca(string mar) { marca=mar; }
	void setidproducto(int idproducto1) { idproductos = idproducto1; }
	//get (mostrar)
	int getID_marca() { return id_marca; }
	int getExistencia() { return existencia; }
	string getProducto() { return producto; }
	string getFecha_ingreso() { return fecha_ingreso; }
	string getDescripcion() { return descripcion; }
	float getPrecio_costo() { return precio_costo; }
	float getPrecio_venta() { return precio_venta; }
	string getMarca() { return marca; }
	int getidproducto() { return idproductos; }

	void leerprodudtos() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "Informacion de productos" << endl;
					cout <<endl<< "(ID producto) = "<< fila[0] <<endl<<"Producto = " << fila[1] <<endl<<"Id marca = " << fila[2] <<endl<<"Descripcion = " << fila[3] <<endl<<"Precio costo($) = " << fila[4] <<endl<<"Precio venta($) = " << fila[5] <<endl<<"Existencia = " << fila[6] <<endl<<"Fecha de ingreso = " << fila[7] << endl;
				}
			}else{
				cout << "Error al ingresar la informacion" << endl;
			}
		}else{
			cout << "----------Error de conexion----------"<<endl;
		}
		cn.cerrar_conexion();
	}

	void leermarcas() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "Informacion de marcas" << endl;
					cout << endl << "ID marca = " << fila[0] << endl << "Marca = " << fila[1] << endl;
				}
			}
			else {
				cout << "Error al ingresar la informacion" << endl;
			}
		}
		else {
			cout << "---------Error de la conexion----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void crearmarcas() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "insert into marcas(marca) values('"+marca+"')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso!" << endl;
			}
			else {
				cout << "Error al ingresar comprueba mas tarde" << endl;
			}
		}
		else {
			cout << "---------Error de la conexion----------" << endl;
		}
		cn.cerrar_conexion();
	}
	void crearproductos() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string p_venta = to_string(precio_venta);
			string existencias = to_string(existencia);
			string idemarca = to_string(id_marca);
			string p_costo = to_string(precio_costo);
			string insert = "INSERT INTO productos(producto,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso)VALUES('" + producto + "'," + idemarca + ",'" + descripcion + "'," + p_costo + "," + p_venta + "," + existencias + ",'" + fecha_ingreso + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso";
			}
			else {
				cout << "-----Error al ingresar la informacion----" << endl;
			}
		}
		else {
			cout << "---------Error de la conexion----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminarproducto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idproductos);
			string insert = "DELETE FROM productos WHERE id_producto = " + borrar + " ;";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion exitosa";
			}
			else {
				cout << "Error al eliminar comprueba tu conexion";
			}
		}
		else {
			cout << "-----Error en la conexion-----" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminarmarca() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idproductos);
			string insert = "DELETE FROM marcas WHERE id_marca = " + borrar + " ;";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion exitosa" << endl;
			}
			else {
				cout << "Error al eliminar comprueba tu conexion" << endl;
			}
		}
		else {
			cout << "-----Error en la conexion-----" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizarproducto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idproductos);
			string p_venta = to_string(precio_venta);
			string existencias = to_string(existencia);
			string idemarca = to_string(id_marca);
			string p_costo = to_string(precio_costo);
			string insert = "UPDATE productos SET producto = '" + producto + "',descripcion = '" + descripcion + "',precio_costo = " + p_costo + ",precio_venta = " + p_venta + ",existencia = " + existencias + ",fecha_ingreso = '" + fecha_ingreso + "' WHERE id_producto = " + borrar + ";";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso" << endl;
			}
			else {
				cout << "-----Error al actualizar la informacion-----" << endl;
			}
		}
		else {
			cout << "-----Error de la conexion-----" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizarmarcas() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Ajuses exitoso" << endl;
		}
		else {
			cout << "-----Error la conexion-----" << endl;
		}
		cn.cerrar_conexion();
	}
};

