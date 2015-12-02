// Juego Magic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

int vidaJ1;
int vidaJ2;

struct Card {//defino la estructura
	int tipoC;
	int mana;
	string nombre;
	int habilidad;
	int ataque;
	int defensa;
	string color;
	bool disponibilidad;
};






vector<Card> carta(1);
vector<Card> mJ_1(1);
vector<Card> mJ_2(1);
vector<Card> bibJ_1;

int opcion = 0;
size_t pos;
string aux;
Card c;

void Llenando_bibliotecaJ_1(){
	for (int i = 0; i <= 15; i++) {
		int ale = 1 + rand() % 30;
		carta[i].tipoC = carta[ale].tipoC;
		carta[i].mana = carta[ale].mana;
		carta[i].nombre = carta[ale].nombre;
		carta[i].habilidad = carta[ale].habilidad;
		carta[i].ataque = carta[ale].ataque;
		carta[i].defensa = carta[ale].defensa;
		carta[i].color = carta[ale].color;

	}
	for (int j = 16; j <= 30; j++){
		bibJ_1[j] = carta[0];

	}
}




void mostrar_mazo() {
	cout << "==========================" << endl;
	for (unsigned i = 0; i < carta.size(); i++) {
		cout << i + 1 << ".-" << carta[i].nombre << endl;
	}
	cout << "==========================" << endl;
}

void leer_mazo() {
	carta.clear();
	ifstream guardar("mazo.txt");
	while (guardar >> c.tipoC >> c.mana >> c.nombre >> c.habilidad >> c.ataque >> c.defensa >> c.color >> c.disponibilidad)
	{
		carta.push_back(c);
		//cout << "wtf" << c.nombre << endl;
	}
	guardar.close();
}


void ajustar_mazo(string cadena, int fin) {
	int ev = 0;
	cout << fin;
	for (int ini = 0; ini < fin; ++ini) {//es para buscar la carta
		if (carta[ini].nombre.compare(cadena) == false) {
			for (int i = ini; i < fin - 1; i++) {
				carta[i].tipoC = carta[i + 1].tipoC;
				carta[i].mana = carta[i + 1].mana;
				carta[i].nombre = carta[i + 1].nombre;
				carta[i].habilidad = carta[i + 1].habilidad;
				carta[i].ataque = carta[i + 1].ataque;
				carta[i].defensa = carta[i + 1].defensa;
				carta[i].color = carta[i + 1].color;
				carta[i].disponibilidad = carta[i + 1].disponibilidad;
			}
		}
		//else { ev++; }
	}
	//if (ev != 0)cout << "La carta no se encuentra " << endl;
}

void actualizar_mazo(string cadena, int fin) {
	int ev = 0;
	for (int i = 0; i < fin; ++i) {
		if (carta[i].nombre.compare(cadena) == 0) {
			cout << "Dame el NUEVO tipo de carta: " << endl;
			cin >> carta[i].tipoC;
			cout << "Dame NUEVO mana: " << endl;
			cin >> carta[i].mana;
			cout << "Dame el NUEVO nombre " << endl;
			cin >> carta[i].nombre;
			cout << "Dame el NUEVA habilidad en numero " << endl;
			cin >> carta[i].habilidad;
			cout << "Dame el NUEVO ataque " << endl;
			cin >> carta[i].ataque;
			cout << "Dame el NUEVO defensa " << endl;
			cin >> carta[i].defensa;
			cout << "Dame el NUEVO color " << endl;
			cin >> carta[i].color;
			carta[i].disponibilidad = 1;
		}
		//else { ev++; }
	}
	//if (ev != 0) cout << "La carta no se encuentra " << endl;
}



void guardar_mazo(int fin) {
	ofstream salida("mazo.txt");
	if (salida.is_open()) {
		for (int i = 0; i < fin; ++i) {
			salida << carta[i].tipoC << " ";
			salida << carta[i].mana << " ";
			salida << carta[i].nombre << " ";
			salida << carta[i].habilidad << " ";
			salida << carta[i].ataque << " ";
			salida << carta[i].defensa << " ";
			salida << carta[i].color << " ";
			salida << carta[i].disponibilidad << endl;
		}
		cout << "archivo guardado con exito " << endl;
	}
	else
	{
		cout << "No se pudo crear el archivo " << endl;
	}
}

struct ability {
	string nombre;
};

vector<ability>habilidad(1);
ability h;

void mostrar_habilidad() {
	cout << "==========================" << endl;
	for (unsigned i = 0; i < habilidad.size(); i++) {
		cout << i + 1 << ".-" << habilidad[i].nombre << endl;
	}
	cout << "==========================" << endl;
}

void leer_habilidad() {
	habilidad.clear();
	ifstream guardar("habilidad.txt");
	while (guardar >> h.nombre)
	{
		habilidad.push_back(h);
	}
	guardar.close();
}


void ajustar_habilidad(string cadena, int fin) {
	int ev = 0;
	cout << fin;
	for (int ini = 0; ini < fin; ++ini) {//es para buscar la carta
		if (habilidad[ini].nombre.compare(cadena) == false) {
			for (int i = ini; i < fin - 1; i++) {
				habilidad[i].nombre = habilidad[i + 1].nombre;
			}
		}
		//else { ev++; }
	}
	//if (ev != 0)cout << "La carta no se encuentra " << endl;
}

void actualizar_habilidad(string cadena, int fin) {
	int ev = 0;
	for (int i = 0; i < fin; ++i) {
		if (habilidad[i].nombre.compare(cadena) == 0) {
			cout << "Dame el NUEVO nombre: " << endl;
			cin >> habilidad[i].nombre;
		}
		//else { ev++; }
	}
	//if (ev != 0) cout << "La carta no se encuentra " << endl;
}


void guardar_habilidad(int fin) {
	ofstream salida("habilidad.txt");
	if (salida.is_open()) {
		for (int i = 0; i < fin; ++i) {
			salida << habilidad[i].nombre << " ";
		}
		cout << "archivo guardado con exito " << endl;
	}
	else
	{
		cout << "No se pudo crear el archivo " << endl;
	}
}

void jugar() {

	do {
		cout << "<<<<Jugar>>>>" << endl;
		cout << "1.- Jugador 1 " << endl;
		cout << "2.- Jugador 2 " << endl;
		cout << "3.- Empezar el juego" << endl;
		cout << "4.- Salir " << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "<<<<Jugador 1>>>>" << endl;
			system("PAUSE");
			system("cls");
			opcion = 0;
			break;
		case 2:
			cout << "<<<<Jugador 2>>>>" << endl;
			system("PAUSE");
			system("cls");
			opcion = 0;
			break;
		case 3:
			cout << "aqui todavia no hay nada" << endl;
			system("PAUSE");
			system("cls");
			opcion = 0;
			break;
		}
	} while (opcion != 4);
	system("cls");
}

void administrar()
{

	do {//administrar cartas
		leer_mazo();//leo el txt y posteriormente obtengo el tamaño
		mostrar_mazo();

		cout << "<<<<Administrar cartas>>>>" << endl;
		cout << "1.- Insertar carta " << endl;
		cout << "2.- Actualizar carta " << endl;
		cout << "3.- Eliminar carta " << endl;
		cout << "4.- Salir " << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			pos = carta.size();
			carta.resize(pos + 1);
			cout << "<<<<Insertar nueva carta>>>>" << endl;
			cout << "Dame tipo de carta ";
			cin >> carta[pos].tipoC;
			cout << "Dame el mana ";
			cin >> carta[pos].mana;
			cout << "Dame el nombre ";
			cin >> carta[pos].nombre;
			cout << "Dame la habilidad: ";
			cin >> carta[pos].habilidad;
			cout << "Dame ataque ";
			cin >> carta[pos].ataque;
			cout << "Dame defensa ";
			cin >> carta[pos].defensa;
			cout << "Dame el color ";
			cin >> carta[pos].color;
			mostrar_mazo();
			guardar_mazo(carta.size());
			//cout << carta.size() << endl;
			system("PAUSE");
			system("cls");
			break;
		case 2:

			cout << "<<<<Actualizar carta>>>>" << endl;
			cout << "Dame el nombre a remplazar: ";
			cin >> aux;
			actualizar_mazo(aux, carta.size());
			guardar_mazo(carta.size());
			system("PAUSE");
			system("cls");
			break;
		case 3:
			cout << "<<<<Eliminar carta>>>> " << endl;
			cout << "Dame el nombre a eliminar ";
			cin >> aux;
			ajustar_mazo(aux, carta.size());
			guardar_mazo(carta.size() - 1);
			system("PAUSE");
			system("cls");
			break;


		}

	} while (opcion != 4);
	system("cls");
}

void gestion() {

	do {//gestion
		leer_habilidad();//leo el txt y posteriormente obtengo el tamaño
		mostrar_habilidad();

		cout << "<<<Gestion de Habilidades>>>>" << endl;
		cout << "1.- Insertar Habilidad " << endl;
		cout << "2.- Actualizar Habilidad " << endl;
		cout << "3.- Eliminar Habilidad " << endl;
		cout << "4.- Salir " << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			pos = habilidad.size();
			habilidad.resize(pos + 1);
			cout << "<<<<Insertar nueva Habilidad>>>>" << endl;
			cout << "Dame la nueva habilidad ";
			cin >> habilidad[pos].nombre;

			mostrar_habilidad();
			guardar_habilidad(habilidad.size());
			//cout << carta.size() << endl;
			system("PAUSE");
			system("cls");
			break;
		case 2:

			cout << "<<<<Actualizar Habilidad>>>>" << endl;
			cout << "Dame el nombre a remplazar: ";
			cin >> aux;
			actualizar_habilidad(aux, habilidad.size());
			guardar_habilidad(habilidad.size());
			system("PAUSE");
			system("cls");
			break;
		case 3:
			cout << "<<<<Eliminar habilidad>>>> " << endl;
			cout << "Dame el nombre a eliminar ";
			cin >> aux;
			ajustar_habilidad(aux, habilidad.size());
			guardar_habilidad(habilidad.size() - 1);
			system("PAUSE");
			system("cls");
			break;


		}

	} while (opcion != 4);
	system("cls");
}

int main() {

	do {
		cout << "<<<<JUEGO MAGIC V1.0>>>>" << endl;
		cout << "  ---MENU PRINCIPAL---  " << endl;
		cout << "1.- Jugar " << endl;
		cout << "2.- Administrar carta " << endl;
		cout << "3.- gestionar habilidades" << endl;
		cout << "4.- Salir " << endl;
		cout << "5.- Combate ON-LINE" << endl;
		cout << "6.- Tienda; Expanciones; Season PASS" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			jugar();
			opcion = 0;
			break;
		case 2:
			system("cls");
			administrar();
			opcion = 0;
			break;
		case 3:
			system("cls");
			gestion();
			opcion = 0;
			break;
		case 5:
			system("cls");
			cout << "¡COMING SOON!" << endl;
			system ("PAUSE");
			break;
		case 6:
			system("cls");
			cout << "¡COMING SOON!" << endl;
			system ("PAUSE");
			break;

		}

	} while (opcion != 4);

}

/*
void aleatorio() {
	srand(time(NULL));
	int bandera = 1;
	int ale;
	for (int i = 0;i < 10;i++) {
		if (vidaJ1 == 0 || vidaJ2 == 0) {
			if (vidaJ1 == 0) {
				cout << "Jugador 2 WIN" << endl;
			}
			else {
				cout << "Jugador 1 WIN" << endl;
			}
		}
		else {
			if (bandera == 1) {
				ale = 1 + rand() % 20;
				cout << "jugador 1, Carta: " << carta[ale].nombre << endl;
				cout << "vida Jugador 1: " << (vidaJ1 = vidaJ1 - carta[ale].ataque) << endl;
				bandera = bandera * -1;
			}
			else {
				ale = 1 + rand() % 20;
				cout << "jugador 2, Carta: " << carta[ale].nombre << endl;
				cout << "vida Jugador 1: " << (vidaJ2 = vidaJ2 - carta[ale].ataque) << endl;
				bandera = bandera * -1;
			}
		}
		
	}
	*/