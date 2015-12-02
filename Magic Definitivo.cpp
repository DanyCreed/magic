// Magic Definitivo.cpp : Defines the entry point for the console application.
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

struct Carta {//defino la estructura
	int tipoC;
	int mana;
	string nombre;
	int habilidad;
	int ataque;
	int defensa;
	string color;
	bool disponibilidad;
};

vector<Carta> carta(1);
vector<Carta> mJ_1(1);
vector<Carta> mJ_2(1);
vector<Carta> bibJ_1;
vector<Carta> biblioteca(0);

int opcion = 0;
size_t pos;
string aux;
Carta c;

struct Habilidad {
	int id;//numero que id la habilidad
	string nombre;
};

vector<Habilidad> habilidades(0);

void Llenando_bibliotecaJ_1() {
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
	for (int j = 16; j <= 30; j++) {
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

void imprimir_habilidades(){
	for (int i = 0; i < habilidades.size(); i++ ) {
		cout << habilidades[i].id << endl;
		cout << habilidades[i].nombre << endl;
	}
};

void imprimir_biblioteca() {
	for (int i = 0; i < biblioteca.size(); i++) {
		cout<<biblioteca[i].tipoC;
		cout<<biblioteca[i].mana;
		cout<<biblioteca[i].nombre;
		cout<<biblioteca[i].habilidad;
		cout<<biblioteca[i].ataque;
		cout<<biblioteca[i].defensa<<endl;
	}
};

void cargar_biblioteca() {
	Carta registro_de_carta;
	Habilidad registro_habilidad;

	ifstream leer_habilidades("habilidades.txt"); //se leen habilidades del archivo txt.
	while (leer_habilidades >> registro_habilidad.id >> registro_habilidad.nombre) {
		habilidades.push_back(registro_habilidad);
	}
	imprimir_habilidades(); //se imprimen las habilidades que se cargaron en el archivo txt.
	leer_habilidades.close();
	
	ifstream leer_biblioteca("biblioteca.txt"); //se lee la bibliote que contiene las cartas en el archivo txt.
	while (leer_biblioteca >> registro_de_carta.tipoC >> registro_de_carta.mana >> registro_de_carta.nombre >> registro_de_carta.habilidad >> registro_de_carta.ataque >> registro_de_carta.defensa )
	{
		biblioteca.push_back(registro_de_carta);
	}
	imprimir_biblioteca(); //se imprime la biblioteca de cartas que se cargaron en el archivo txt.
	leer_biblioteca.close();
	system("PAUSE");
	exit(0);
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



void leer_archivo_mazo(int fin) {
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
	ifstream leer_archivo("habilidad.txt");
	while (leer_archivo >> h.nombre)
	{
		habilidad.push_back(h);
	}
	leer_archivo.close();
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


void leer_archivo_habilidad(int fin) {
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

void administrar(){
	do {//administrar cartas
		cargar_biblioteca();//leo el txt y posteriormente obtengo el tamaño
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
			leer_archivo_mazo(carta.size());
			//cout << carta.size() << endl;
			system("PAUSE");
			system("cls");
			break;

		case 2:

			cout << "<<<<Actualizar carta>>>>" << endl;
			cout << "Dame el nombre a remplazar: ";
			cin >> aux;
			actualizar_mazo(aux, carta.size());
			leer_archivo_mazo(carta.size());
			system("PAUSE");
			system("cls");
			break;

		case 3:

			cout << "<<<<Eliminar carta>>>> " << endl;
			cout << "Dame el nombre a eliminar ";
			cin >> aux;
			ajustar_mazo(aux, carta.size());
			leer_archivo_mazo(carta.size() - 1);
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
			leer_archivo_habilidad(habilidad.size());
			//cout << carta.size() << endl;
			system("PAUSE");
			system("cls");
			break;
		case 2:

			cout << "<<<<Actualizar Habilidad>>>>" << endl;
			cout << "Dame el nombre a remplazar: ";
			cin >> aux;
			actualizar_habilidad(aux, habilidad.size());
			leer_archivo_habilidad(habilidad.size());
			system("PAUSE");
			system("cls");
			break;
		case 3:

			cout << "<<<<Eliminar habilidad>>>> " << endl;
			cout << "Dame el nombre a eliminar ";
			cin >> aux;
			ajustar_habilidad(aux, habilidad.size());
			leer_archivo_habilidad(habilidad.size() - 1);
			system("PAUSE");
			system("cls");
			break;
		}
	} while (opcion != 4);
	system("cls");
}

vector<int> posiciones_auxiliar;
vector<int> mazo;
int numero_aleatorio = (1 + rand() % mazo.size());
/*<int> biblioteca; //temporal no poner en el codugo general  */

bool buscar_numero(int numero_aleatorio) {
	for (int i = 0; i < posiciones_auxiliar.size(); i++) {
		if (posiciones_auxiliar[i] == numero_aleatorio) {
			return true;
		}
	}
	return false;
}


int llenar_auxiliar(int argc, char** argv) {

	srand(time(NULL));

	do {

		for (int i = 0;i < mazo.size(); i++) {
		}
		while (buscar_numero(numero_aleatorio) == 0) {
			numero_aleatorio = 1 + rand() % mazo.size();
		}
		posiciones_auxiliar.push_back(numero_aleatorio);

	} while (posiciones_auxiliar.size() < biblioteca.size());

	for (int i = 0; i < biblioteca.size(); i++) { // Transfiere las cartas de posiciones_auxiliar al mazo
		mazo.push_back(biblioteca[posiciones_auxiliar[i]]);
	}
	return 0;

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
			system("PAUSE");
			break;
		case 6:
			system("cls");
			cout << "¡COMING SOON!" << endl;
			llenar_auxiliar();
			system("PAUSE");
			break;
		}
	} while (opcion != 4);
}



/*void aleatorio() {
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

}*/
