#include <mysql.h>
#include <iostream>
#include "Menu.h"
using namespace std;
int main()
{


	
	int id_marca=0, existencia=0,respuesta,ideproducto,idemarca;
	string producto, fecha_ingreso, descripcion, marca;
	float precio_costo=0, precio_venta=0;

	cout << "Bienvenido que quieres realizar " << endl;
	cout << "1 = Ingresar nuevo producto " << endl;
	cout << "2 = Ver todos los productos" << endl;
	cout << "3 = Eliminar producto" << endl;
	cout << "4 = Modificar producto" << endl;
	cout << "5 = Ingresar nueva marca" << endl;
	cout << "6 = Ver todos los registros de marcas" << endl;
	cout << "7 = Eliminar marca" << endl;
	cout << "8 = Modificar marca" << endl;
	cout << "Respuesta = ";
	cin >> respuesta;

	if (respuesta == 1) {
		cout << "Ingresa el nombre del producto: ";
		cin >> producto;
		cout << "Ingresa el id de la marca: ";
		cin >> id_marca;
		cin.ignore();
		cout << "Ingresa la descripcion del producto: ";
		getline(cin, descripcion);
		cout << "Ingresa el precio costo del producto: ";
		cin >> precio_costo;
		cout << "Ingresa el precio para la venta del producto: ";
		cin >> precio_venta;
		cout << "Ingresa la existencia del producto: ";
		cin >> existencia;
		cin.ignore();
		cout << "Ingresa la fecha de ingreso del producto: ";
		cin >> fecha_ingreso;
		Menu c = Menu(id_marca, existencia, producto, fecha_ingreso, descripcion, precio_costo, precio_venta);
		c.crearproductos();
	}
	else {
		if (respuesta==2)
		{
			Menu c = Menu();
			c.leerprodudtos();
		}
		else {
			if (respuesta == 3) {
				cout << "Ingresa el ID del producto a eliminar: ";
				cin >> ideproducto;
				Menu c = Menu(ideproducto);
				c.eliminarproducto();
			}
			else {
				if (respuesta == 4) {
					cout << "ingresa el id del producto a modificar: ";
					cin >> ideproducto;
					cout << "Ingresa el nombre del producto: ";
					cin >> producto;
					cin.ignore();
					cout << "Ingresa la descripcion del producto: ";
					getline(cin, descripcion);
					cout << "Ingresa el precio costo del producto: ";
					cin >> precio_costo;
					cout << "Ingresa el precio para la venta del producto: ";
					cin >> precio_venta;
					cout << "Ingresa la existencia del producto: ";
					cin >> existencia;
					cin.ignore();
					cout << "Ingresa la fecha de ingreso del producto: ";
					cin >> fecha_ingreso;
					Menu c = Menu(ideproducto, existencia, producto, fecha_ingreso, descripcion, precio_costo, precio_venta);
					c.actualizarproducto();

				}
				else {
					if (respuesta == 5) {
						cout << "Ingresa la marca del producto:";
						getline(cin, marca);
						Menu c = Menu();
						c.crearmarcas();
					}
					else {
						if (respuesta == 6) {
							Menu c = Menu();
							c.leermarcas();
						}
						else {
							if (respuesta == 7) {
								cout << "Ingresa el ID de la marca a eliminar: ";
								cin >> idemarca;
								Menu c = Menu(idemarca);
								c.eliminarmarca();
							}
							else {
								if (respuesta == 8) {
									cout << "ingresa el ID de la marca a modificar: ";
									cin >> idemarca;
									cout << "Ingresa la marca a modicar: ";
									cin >> marca;
									Menu c = Menu(idemarca);
									c.actualizarmarcas();
								}
								else {
									cout << "Respuesta incorrecta ingresa otra"<<endl;
								}
							}
						}
					}
				}
			}
		}
	}


	return 0;
}
