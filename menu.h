/* 
 * File:   menu.h
 * Author: jesusmarquez
 *
 * Created on 3 de diciembre de 2015, 09:25 PM
 */

#ifndef MENU_H
#define	MENU_H
#include <iostream>

using namespace std;

int menu_principal(){
    int opcion;
    do{
        cout<<endl<<endl; 
        cout << "<<<<  MAGIC THE GATHERING ++  >>>>" << endl;
		cout << "  ---MENU PRINCIPAL---  " << endl;
		cout << "1.- Jugar " << endl;
		cout << "2.- Administrar cartas " << endl;
		cout << "3.- Administrar habilidades" << endl;
		cout << "4.- Salir " << endl;
		cin >> opcion; 
    }
    while (opcion <= 0 || opcion >= 5); // si es falso while no repite ciclo 
    
    //while (!(opcion > 0 && opcion < 5)); // si es falso while no repite ciclo 
                return opcion;
}

int menu_administrar_carta(){
    return 0;
}

int menu_administrar_habilidad(){
    return 0;
}

int menu_de_juego(){
    return 0;
}
#endif	/* MENU_H */