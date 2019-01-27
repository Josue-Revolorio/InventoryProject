#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

class ProductControl
{
private:
	char id[5];
	char nombre[20];
	char cantidad[5];
	char precio[5];
	ifstream out;      //Salida
	ofstream in;       //Entrada
	string texto;


	/* Metodo que muestra la lista de productos*/
public: void listaProductos() {
	cout << endl;
	cout << "\t\t\t\t ==> Listado de Productos <==" << endl;
	cout << "\t\t\t\t-------------------------------" << endl;
	cout << "\t\t\t\t" << "  id " << " Nombre " << "Cantidad " << "Precio" << endl;
	cout << "\t\t\t\t-------------------------------" << endl;

	out.open("Productos.txt", ios::in);
	if (out.fail())
	{
		cout << "\t\t\t\tNo se pudo abrir el archivo" << endl;
		exit(1);
	}
	while (!out.eof())
	{
		getline(out, texto);
		cout << "\t\t\t\t" << texto << endl;
	}
	out.close();
	cout << "\t\t\t\t";
	system("pause");
	system("cls");
}

		/* Metodo que Registra un nuevo producto*/
public: void registrarProducto()
{
	int resp;
	cout << endl;
	cout << "\t\t\t\tRealizar un registro nuevo" << endl;
	cout << "\t\t\t\t---------------------------------" << endl;
	cout << "\t\t\t\t[1] Si" << endl;
	cout << "\t\t\t\t[2] No" << endl;
	cout << "\t\t\t\t---------------------------------" << endl;
	cout << "\t\t\t\t Ingrese la opcion: "; cin >> resp;
	system("cls");

	if (resp == 1)
	{
		int opc;
		in.open("Productos.txt", ios::out | ios::app);
		if (in.fail())
		{
			cout << "\t\t\t\tNo se Pudo crear el registro" << endl;
		}
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
			cout << "\t\t\t\tIngrese el codigo del producto: "; cin >> id;
			cout << "\t\t\t\tIngrese el nombre del producto: "; cin >> nombre;
			cout << "\t\t\t\tIngrese la cantidad de producto: "; cin >> cantidad;
			cout << "\t\t\t\tIngrese el Precio del producto: "; cin >> precio;
			cout << "\t\t\t\t--------------------------------------------" << endl;
			in << "  " << id << "   " << nombre << "    " << cantidad << "      " << precio << endl;
			cout << "\n\t\t\t\tSe ha registrado con exito" << endl << endl;
			cout << "\t\t\t\t--------------------------------------------" << endl;
			cout << "\t\t\t\tRealizar un registro nuevo" << endl;
			cout << "\t\t\t\t---------------------------------" << endl;
			cout << "\t\t\t\t[1] Si" << endl;
			cout << "\t\t\t\t[2] No" << endl;
			cout << "\t\t\t\t---------------------------------" << endl;
			cout << "\t\t\t\t Ingrese la opcion: "; cin >> opc;
			system("cls");
			if (opc == 2)
			{
				break;
			}
		}

		in.close();
	}

}
		/* Procedimiento que Elimina un producto de la lista*/
public: void eliminarProducto() {

	int resp;
	cout << endl;
	cout << "\t\t\t\tDesea Eliminar un Registro" << endl;
	cout << "\t\t\t\t---------------------------------" << endl;
	cout << "\t\t\t\t[1] Si" << endl;
	cout << "\t\t\t\t[2] No" << endl;
	cout << "\t\t\t\t---------------------------------" << endl;
	cout << "\t\t\t\t Ingrese la opcion: "; cin >> resp;
	system("cls");

	if (resp == 1)
	{
		out.open("Productos.txt", ios::in | ios::out);

		in.open("temp.txt", ios::out);


		if (out.fail())
		{
			cout << "\t\t\t\tNo se pudo abrir el archivo" << endl;
			exit(1);
		}
		else
		{
			char aux[5];
			cout << endl;
			cout << "\t\t\t\Introduzca el codigo: "; cin >> aux;

			while (!out.eof())
			{
				out >> id >> nombre >> cantidad >> precio;

				if (strcmp(aux, id) == 0)
				{
					cout << endl;
					cout << "\t\t\tEl registro se ha elimino" << endl;
					cout << "\n\t\t\t";
					system("pause");
				}
				else
				{
					in << "  " << id << "   " << nombre << "    " << cantidad << "      " << precio << endl;
				}
			}
			out.close();
			in.close();

			remove("Productos.txt");
			rename("temp.txt", "Productos.txt");
		}
		system("cls");

	}
}
		/* Procedimiento que busca en la lista */
public: void buscarProducto() {
	int opc = 1;
	bool buscar = false;
	char aux[5];
	ifstream in;

	in.open("Productos.txt", ios::in | ios::out);

	if (in.fail())
	{
		cout << "\t\t\t\tNo se pudo abrir el archivo" << endl;
		exit(1);
	}
	else
	{
		cout << endl;
		cout << "\t\t\t\tIngresa la clave a Buscar: "; cin >> aux;

		while (!in.eof())
		{
			in >> id >> nombre >> cantidad >> precio;

			if (strcmp(aux, id) == 0)
			{
				cout << endl;
				cout << "\t\t\t\t ==> Producto Encontrado <==" << endl;
				cout << "\t\t\t\t-------------------------------" << endl;
				cout << "\t\t\t\t" << "  id " << " Nombre " << "Cantidad " << "Precio" << endl;
				cout << "\t\t\t\t-------------------------------" << endl;
				cout << "\t\t\t\t" << "  " << id << "   " << nombre << "    " << cantidad << "      " << precio << endl;
				buscar = true;
			}
		}
		if (buscar == false)
		{
			cout << "\n\n\t\t\t\tNo hay registro con esa clave";

		}
	}
	in.close();
	
	cout << "\n\t\t\t\t";
	system("pause");
	system("cls");
}

};

