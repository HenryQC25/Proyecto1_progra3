#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <locale.h>

#define getch() _getch(); 
#define cls system("cls");

using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Declaracion de variables


//declaracion de funciones
void tituloX();
void Menu_Principal();
void Menu_Pila();
void ingresoPila();
void verPila();
void modificarPila();
void buscarPila();
void eliminarPila();
void Menu_Cola();
void ingresoCola();
void verCola();
void modificarCola();
void buscarCola();
void eliminarCola();

/////////Struct para usar
struct pilas
{
	int dato;
	string nom_libro;
	pilas* siguiente;
};
pilas* pila, * pilaux;

struct colas
{
	string cliente;
    colas* siguienteC;
};
colas* primero,*cola ,*ultimo=NULL,*colaux;
/////////////////////////////////////////////////////////////////////
int main() {
	setlocale(LC_ALL, ""); //ayuda a colocar tildes se agrega libreria locale.h
	//tituloX(); 
	Menu_Principal();
	getch();
	return 0;
}

void tituloX() {
	//intro al programa
	int i = 46;
	gotoxy(35, 10); cout << "********************************";
	gotoxy(35, 14); cout << "********************************";
	gotoxy(i++, 12); system("color 01"); cout << "B"; Sleep(300); 
	gotoxy(i++, 12); system("color 02"); cout << "I"; Sleep(300);
	gotoxy(i++, 12); system("color 05"); cout << "E"; Sleep(300);
	gotoxy(i++, 12); system("color 04"); cout << "N"; Sleep(300);
	gotoxy(i++, 12);	system("color 06"); cout << "V"; Sleep(300);
	gotoxy(i++, 12);	system("color 01"); cout << "E"; Sleep(300);
	gotoxy(i++, 12);	system("color 02"); cout << "N"; Sleep(300);
	gotoxy(i++, 12);	system("color 05"); cout << "I"; Sleep(300);
	gotoxy(i++, 12);	system("color 04"); cout << "D"; Sleep(300);
	gotoxy(i, 12);	system("color 06"); cout << "O"; Sleep(300);
	cls;	  		  
}



void Menu_Principal() {
	int op = 0;
	do {
	gotoxy(40, 8); cout << "\t*********************************";
	gotoxy(42, 9); cout << "\tMenú Principal Biblioteca ";
	gotoxy(42, 10); cout << "\tEscoja un opcion: ";
	gotoxy(44, 13); cout << "\t1. Módulo de datos de Pila (libros) ";
	gotoxy(44, 14); cout << "\t2. Módulo de datos de Cola (Clientes)";
	gotoxy(44, 15); cout << "\t3. Salir";
	gotoxy(40, 16); cout << "\t*********************************";
	gotoxy(66, 10); cin >> op;
	//titulo y opciones del menu	
		switch (op) {
		case 1: cls; Menu_Pila(); break;
		case 2: cls ; Menu_Cola(); break;
		  
		}
	} while (op!=3);
	cls;
	gotoxy(42, 9); cout << "saliste del programa...";
}

void Menu_Pila() {
	int opP = 0;
	do {
		gotoxy(40, 8); cout << "\t**********************************";
		gotoxy(42, 9); cout << "\tSub-Menú Pila: ";
		gotoxy(42, 10); cout << "\tEscoja un opcion: ";
		gotoxy(44, 13); cout << "\t1. Ingreso de datos ";
		gotoxy(44, 14); cout << "\t2. Ver datos en forma de PILA ";
		gotoxy(44, 15); cout << "\t3. Modificar un dato";
		gotoxy(44, 16); cout << "\t4. Buscar un dato ";
		gotoxy(44, 17); cout << "\t5. Eliminar un dato";
		gotoxy(44, 18); cout << "\t6. Atrás (MENÚ PRINCIPAL)";
		gotoxy(40, 19); cout << "\t*********************************";
		gotoxy(66, 10); cin >> opP;
		//titulo y opciones del menu
		switch (opP) {
		case 1: cls; ingresoPila(); break;
		case 2: cls; verPila(); break;
		case 3: cls; modificarPila(); break;
		case 4: cls; buscarPila(); break;
		case 5: cls; eliminarPila(); break;
		}
	} while (opP != 6);
	cls;
	gotoxy(42, 9); cout << "Regresaste al menú principal..."; Sleep(1500);
	cls;
}

void ingresoPila() {
	if (pila == NULL)
	{
		system("cls");
		pila = new (pilas);
		cout << "                                    INGRESE EL PRIMER LIBRO " << endl << endl;
		cin >> pila->dato;
		cout << "                                    INGRESE EL NOMBRE DEL LIBRO " << endl << endl;
		cin >> pila->nom_libro;
		cout << "                              EL DATO HA SIDO INGRESADO CORRECTAMENTE :) " << endl;
		pila->siguiente = NULL;
		system("cls");
		return;

	}
	else {
		pilaux = new(pilas);
		cout << "                                        INGRESE EL SIGUIENTE LIBRO  " << endl << endl;
		cin >> pilaux->dato;
		cout << "                                    INGRESE EL NOMBRE DEL LIBRO " << endl << endl;
		cin >> pilaux->nom_libro;
		cout << "                                EL EL LIBRO HA SIDO INGRESADO CORRECTAMENTE :) " << endl;
		pilaux->siguiente = pila;
		pila = pilaux;
		
	}
	getch();
	cls;
}

//ver los datos
void verPila() {

	if (pila == NULL)
	{
		cout << "lA PILA ESTA VACIA " << endl;
	}
	else {
		pilaux = pila;
		cout << "LOS LIBROS INGRESADOS  SON  : " << endl;
		while (pilaux != NULL)
		{
			cout << pilaux->dato <<" - "<<pilaux->nom_libro<< endl;

			pilaux = pilaux->siguiente;

		}
	}
		getch();
		cls;
	}

//modificar dato
void modificarPila() {
	if (pila == NULL)
	{
		cout << "LA PILA ESTA VACIA " << endl;
		return;
	}
	else {

		int buscardatos;
		bool datoenc = false;
		pilaux = pila;
		cout << "INGRESE EL NO. LIBRO QUE BUSCA " << endl;
		cin >> buscardatos;
		while (pilaux != NULL)
		{
			if (buscardatos == pilaux->dato)
			{
				cout << "LIBRO ENCONTRADO EL NO. ES :" << pilaux->dato<<" - "<<pilaux->nom_libro << endl;
				datoenc = (true);
				cout << "nombre nuevo ";
				cin >> pilaux->nom_libro;
				cout << "Titulo modificado";
			}
			pilaux = pilaux->siguiente;
		}
		if (datoenc == false) {
			cout << "NO SE ENCONTRO EL NO. DE LIBRO INGRESADO" << endl;

		}
	}
		getch();
		cls;
	}



//BUSCAR DATOS
void buscarPila() {
	if (pila == NULL)
	{
		cout << "LA PILA ESTA VACIA " << endl;
		return;
	}
	else {
		int buscardatos;
		bool datoenc = false;
		pilaux = pila;
		cout << "INGRESE EL NO. LIBRO QUE BUSCA " << endl;
		cin >> buscardatos;
		while (pilaux != NULL)
		{
			if (buscardatos == pilaux->dato)
			{
				cout << "LIBRO ENCONTRADO EL NO. ES : " << pilaux->dato <<" - "<<pilaux->nom_libro<< endl;
				datoenc = (true);

			}
			pilaux = pilaux->siguiente;
		}
		if (datoenc == false) {
			cout << "NO SE ENCONTRO EL NO. DE LIBRO INGRESADO" << endl;

		}
	}
		getch();
		cls;
	}


//eliminar datos
void eliminarPila() {
	if (pila == NULL)
	{
		cout << "NO HAY LIBROS PARA ELIMINAR " << endl;
		return;
	}
	else {
		pilaux = new(pilas);
		pilaux = pila;
		cout << "EL LIBRO ELIMINADO ES " << pila->dato<<" - "<<pilaux->nom_libro << endl;
		pila = pilaux->siguiente;
		delete(pilaux);
	}
		getch();
		cls;
	}
	

 

void Menu_Cola() {
	int opC = 0;
	do {
		gotoxy(40, 8); cout << "\t**********************************";
		gotoxy(42, 9); cout << "\tSub-Menú Cola: ";
		gotoxy(42, 10); cout << "\tEscoja un opcion: ";
		gotoxy(44, 13); cout << "\t1. Ingreso de datos ";
		gotoxy(44, 14); cout << "\t2. Ver datos en forma de COLA ";
		gotoxy(44, 15); cout << "\t3. Modificar un dato";
		gotoxy(44, 16); cout << "\t4. Buscar un dato ";
		gotoxy(44, 17); cout << "\t5. Eliminar un dato";
		gotoxy(44, 18); cout << "\t6. Atrás (MENÚ PRINCIPAL)";
		gotoxy(40, 19); cout << "\t*********************************";
		gotoxy(66, 10); cin >> opC;
		//titulo y opciones del menu
		switch (opC) {
		case 1: cls; ingresoCola(); break;
		case 2: cls; verCola(); break;
		case 3: cls; modificarCola(); break;
		case 4: cls; buscarCola(); break;
		case 5: cls; eliminarCola(); break;
		}
	} while (opC != 6);
	cls;
	gotoxy(42, 9); cout << "Regresaste al menú principal..."; Sleep(1500);
	cls;

}

void ingresoCola() {
	cola = new(colas);
	cout << "Ingrese nombre del cliente\n";
	cin >> cola->cliente;
	cola->siguienteC = NULL;
	if (primero == NULL) {
		primero = cola;
		cout << " cliente ingresado: \n";
		cout << cola->cliente;
	}
	else {
		cout << " cliente ingresado: \n";
		cout << cola->cliente;
		ultimo->siguienteC = cola;		
		cola->siguienteC = NULL;
	}ultimo = cola;
	getch();
	cls;
}

void verCola() {
	if (ultimo == NULL) {
		cout << "La cola está vacía";
	}
	else {
	colaux = primero;
		cout << "los clientes en cola son: \n";
		while (colaux != NULL) {
		
			cout << colaux->cliente<<" " << colaux->siguienteC << " - " << endl;
			
			colaux = colaux->siguienteC;
		}

	}
	getch();
	cls;
}

void modificarCola() {
		if (cola == NULL)
		{
			cls;
			cout << "LA COLA ESTA VACIA " << endl;
			return;
		}
		else {
			string buscardatos;
			bool datoenc = false;
			colaux = cola;
			cout << "INGRESE EL NOMRE DL CLIENTE QUE BUSCA " << endl;
			cin >> buscardatos;
			while (colaux != NULL)
			{
				if (buscardatos == colaux->cliente)
				{
					cout << "CLIENTE ENCONTRADO ES : " << colaux->cliente << endl;
					datoenc = (true);
					cout << "NOMBRE NUEVO DEL CLIENTE  ";
					cin>>colaux->cliente;
				}
				colaux = colaux->siguienteC;
			}
			if (datoenc == false) {
				cout << "NO SE ENCONTRO EL CLIENTE" << endl;

			}
		}
		getch();
		cls;
}

void buscarCola() {
	if (cola == NULL)
	{
		cls;
		cout << "LA COLA ESTA VACIA " << endl;
		return;
	}
	else {
		string buscardatos;
		bool datoenc = false;
		colaux = cola;
		cout << "INGRESE EL NOMRE DL CLIENTE QUE BUSCA " << endl;
		cin >> buscardatos;
		while (colaux != NULL)
		{
			if (buscardatos == colaux->cliente)
			{
				cout << "CLIENTE ENCONTRADO ES : " << colaux->cliente << endl;
				datoenc = (true);

			}
			colaux = colaux->siguienteC;
		}
		if (datoenc == false) {
			cout << "NO SE ENCONTRO EL CLIENTE" << endl;

		}
	}
	getch();
	cls;

}

void eliminarCola(){
	if (primero == NULL)
	{
		cls;
		cout << "NO HAY CLIENTES PARA ELIMINAR " << endl;
		return;
	}
	else {
		colaux = new(colas);
		colaux = primero;
		cout << "EL CLIENTE ELIMINADO ES " << colaux->cliente<<" siguente en salir "<< primero->siguienteC->cliente << endl;
		primero= primero->siguienteC;
		
		delete(colaux);
	}
	getch();
	cls;
}