#include "pch.h"
#include <iostream>
#include "ProductControl.h"

using namespace std;

int main()
{
	ProductControl producto; //se llama a la clase 
	int opc;
	do
	{
		system("color F1");
		cout << endl;
		cout << "\n\t\t\t\t ==> PROGRAMA DE CONTROL DE INVENTARIO <==" << endl;
		cout << "\n\t\t\t\t----------------------------------------- " << endl;
		cout << "\t\t\t\t  [1] Listado de Productos" << endl;
		cout << "\t\t\t\t  [2] Registrar producto" << endl;
		cout << "\t\t\t\t  [3] Eliminar producto " << endl;
		cout << "\t\t\t\t  [4] Buscar Producto por clave" << endl;
		cout << "\t\t\t\t  [0] Salir " << endl;
		cout << "\t\t\t\t  ----------------------------------------- " << endl;
		cout << "\n\t\t\t\t   Ingrese la Opcion : "; cin >> opc;
		system("cls");

		switch (opc)
		{
		case 1: producto.listaProductos(); break;
		case 2: producto.registrarProducto(); break;
		case 3: producto.eliminarProducto(); break;
		case 4: producto.buscarProducto(); break;
		case 0: break;
		}

	} while (opc != 0);

	return 0;
}