/* 
 * File:   main.cpp
 * Author: jesus marquez
 *
 * Created on 24 de noviembre de 2015, 04:08 PM
 */
// Juego Magic.cpp : Defines the entry point for the console application.
//

// Magic Definitivo.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include "menu.h"
#include "procesos.h"

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

vector<Carta> carta(0);
vector<Carta> mJ_1(0);
vector<Carta> mJ_2(0);
vector<Carta> bibJ_1;
vector<Carta> biblioteca(0);

vector<Carta> mazo(0);

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

void imprimir_mazo() {
	cout << "==========================" << endl;
	for (unsigned i = 0; i < mazo.size(); i++) {
		cout << i + 1 << ".-" << mazo[i].nombre << endl;
	}
	cout << "==========================" << endl;
}

void imprimir_habilidades() {
	for (unsigned i = 0; i < habilidades.size(); i++) {
		cout << habilidades[i].id << endl;
		cout << habilidades[i].nombre << endl;
	}
};

void imprimir_biblioteca() {
	cout << "Imprimiendo..." << endl;
	for (unsigned i = 0; i < biblioteca.size(); i++) {
		cout << biblioteca[i].tipoC;
		cout << biblioteca[i].mana;
		cout << biblioteca[i].nombre;
		cout << biblioteca[i].habilidad;
		cout << biblioteca[i].ataque;
		cout << biblioteca[i].defensa << endl;
	}
};

void cargar_biblioteca() {
    
	Carta registro_de_carta;
	Habilidad registro_habilidad;
	ifstream leer_habilidades("habilidades.txt"); //se leen habilidades del archivo txt.
	while (leer_habilidades >> registro_habilidad.id >> registro_habilidad.nombre) {
		habilidades.push_back(registro_habilidad);
	}
	//imprimir_habilidades(); //se imprimen las habilidades que se cargaron en el archivo txt.
	leer_habilidades.close();

	ifstream leer_biblioteca("biblioteca.txt"); //se lee la bibliote que contiene las cartas en el archivo txt.
	while (leer_biblioteca >> registro_de_carta.tipoC >> registro_de_carta.mana >> registro_de_carta.nombre >> registro_de_carta.habilidad >> registro_de_carta.ataque >> registro_de_carta.defensa)
	{
		biblioteca.push_back(registro_de_carta);
	}
	//imprimir_biblioteca(); //se imprime la biblioteca de cartas que se cargaron en el archivo txt.
	leer_biblioteca.close();
	//system("PAUSE");
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
	ofstream cout("mazo.txt");
	if (cout.is_open()) {
		for (int i = 0; i < fin; ++i) {
			cout << carta[i].tipoC << " ";
			cout << carta[i].mana << " ";
			cout << carta[i].nombre << " ";
			cout << carta[i].habilidad << " ";
			cout << carta[i].ataque << " ";
			cout << carta[i].defensa << " ";
			cout << carta[i].color << " ";
			cout << carta[i].disponibilidad << endl;
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
	ifstream leer_archivo("habilidades.txt");
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
	ofstream cout("habilidad.txt");
	if (cout.is_open()) {
		for (int i = 0; i < fin; ++i) {
			cout << habilidad[i].nombre << " ";
		}
		cout << "archivo guardado con exito " << endl;
	}
	else
	{
		cout << "No se pudo crear el archivo " << endl;
	}
}

//void jugar() {
//	do {
//		cout << "<<<<Jugar>>>>" << endl;
//		cout << "1.- Jugador 1 " << endl;
//		cout << "2.- Jugador 2 " << endl;
//		cout << "3.- Empezar el juego" << endl;
//		cout << "4.- Salir " << endl;
//		cin >> opcion;
//		switch (opcion) {
//		case 1:
//			cout << "<<<<Jugador 1>>>>" << endl;
//			system("PAUSE");
//			system("cls");
//			opcion = 0;
//			break;
//		case 2:
//			cout << "<<<<Jugador 2>>>>" << endl;
//			system("PAUSE");
//			system("cls");
//			opcion = 0;
//			break;
//		case 3:
//			cout << "aqui todavia no hay nada" << endl;
//			system("PAUSE");
//			system("cls");
//			opcion = 0;
//			break;
//		}
//	} while (opcion != 4);
//	system("cls");
//}

//

void administracion_de_las_cartas() {
	do {//administrar cartas
		cargar_biblioteca();//leo el txt y posteriormente obtengo el tamaÒo
		imprimir_biblioteca();
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
			imprimir_biblioteca();
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

void gestion_de_habilidades() {
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

bool buscar_numero(int numero_aleatorio, vector<int> posiciones_auxiliar) {
    for (unsigned i = 0; i < posiciones_auxiliar.size(); i++) {
		if (posiciones_auxiliar[i] == numero_aleatorio) {
			return true;
		}
	}
	return false;
}

void llenar_auxiliar() {
        vector<int> posiciones_auxiliar(0);
	srand(time(NULL));
	 //cout << numero_aleatorio << endl;
	do {
        	int numero_aleatorio = rand() % biblioteca.size();
		for (unsigned i = 0; i < biblioteca.size(); i++) {
			while (buscar_numero(numero_aleatorio, posiciones_auxiliar) == true) {
                                //cout << "Repetido: " << numero_aleatorio << endl;
				numero_aleatorio = rand() % biblioteca.size();	
			}
			posiciones_auxiliar.push_back(numero_aleatorio);
			//cout << numero_aleatorio << endl;
		}
	} while (posiciones_auxiliar.size() < biblioteca.size());

	for (unsigned i = 0; i < biblioteca.size(); i++) { // Transfiere las cartas de posiciones_auxiliar al mazo
		mazo.push_back(biblioteca[posiciones_auxiliar[i]]);
	}	
        for(unsigned i = 0; i < mazo.size() / 2; i++){
                        cout << mazo[i].tipoC << " ";
			cout << mazo[i].mana << " ";
			cout << mazo[i].nombre << " ";
			cout << mazo[i].habilidad << " ";
			cout << mazo[i].ataque << " ";
			cout << mazo[i].defensa << " ";
			cout << mazo[i].color << " ";
			cout << mazo[i].disponibilidad << endl;
        }
        
}

int main() {
    bool fin = false;
    int opcion;
	do {
                opcion = menu_principal();
		
                switch (opcion) {
		case 1:
			//system("cls");
			proceso_para_iniciar_el_juego();
                        //cargar_biblioteca();
                        //llenar_auxiliar();
			break;
		case 2:
			//system("cls");
                        //proceso_administrar_carta();
                        administracion_de_las_cartas();
			break;
		case 3:
			//system("cls");
			//proceso_administrar_habilidad();
                        gestion_de_habilidades();
			break;
                    case 4:
                        fin = true;
                        break;
                default:
                    cout << "Opcion pendiente: " << opcion;
                        
		}
                      
	} while (!fin);
}