/* 
 * File:   procesos.h
 * Author: jesusmarquez
 *
 * Created on 3 de diciembre de 2015, 09:39 PM
 */

#ifndef PROCESOS_H
#define	PROCESOS_H
#include <iostream>

using namespace std;

void proceso_administrar_carta(){
    
    int opcion;
	
                opcion = menu_administrar_carta();
		
                    do {//administrar cartas
		cout << "  Administrar cartas  " << endl;
		cout << "1.- Insertar carta " << endl;
		cout << "2.- Actualizar carta " << endl;
		cout << "3.- Eliminar carta " << endl;
		cout << "4.- Salir " << endl;
		cin >> opcion;
                
		switch (opcion) {
		case 1:
			cout << "<<<<Insertar nueva carta>>>>" << endl;
			//system("PAUSE");
			//system("cls");
			break;
		case 2:
			cout << "<<<<Actualizar carta>>>>" << endl;
			cout << "Dame el nombre a remplazar: ";
			//system("PAUSE");
			//system("cls");
			break;
		case 3:
			cout << "<<<<Eliminar carta>>>> " << endl;
			cout << "Dame el nombre a eliminar ";
			//system("PAUSE");
			//system("cls");
			break;
		}
	} while (opcion != 4);
                         
}


void proceso_administrar_habilidad(){
    
        int opcion;
    
            opcion = menu_administrar_habilidad();
    
    
            do {//gestion
		cout << "   Gestion de Habilidades   " << endl;
		cout << "1.- Insertar Habilidad " << endl;
		cout << "2.- Actualizar Habilidad " << endl;
		cout << "3.- Eliminar Habilidad " << endl;
		cout << "4.- Salir " << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			
			cout << "<<<<Insertar nueva Habilidad>>>>" << endl;
			cout << "Dame la nueva habilidad " << endl;
                        cout<<endl<<endl<<endl;
			//cout << carta.size() << endl;
			//system("PAUSE");
			//system("cls");
			break;
		case 2:
			cout << "<<<<Actualizar Habilidad>>>>" << endl;
			cout << "Dame el nombre a remplazar: " << endl;
                        cout<<endl<<endl<<endl;
			//system("PAUSE");
			//system("cls");
			break;
		case 3:
			cout << "<<<<Eliminar habilidad>>>> " << endl;
			cout << "Dame el nombre a eliminar " << endl;
                        cout<<endl<<endl<<endl;
			//system("PAUSE");
			//system("cls");
			break;
		}
	} while (opcion != 4); 
}


void proceso_para_iniciar_el_juego(){
    
    string nombre_jugador_1;
    string nombre_jugador_2;
    
    int opcion;
    
            opcion = menu_de_juego();
    
	do {
		cout << "   Jugar   " << endl;
		cout << "1.- Jugador 1 " << endl;
		cout << "2.- Jugador 2 " << endl;
		cout << "3.- Empezar el juego" << endl;
		cout << "4.- Salir " << endl;
		cin >> opcion;
                
		switch (opcion) {
		case 1:
			cout << "<<<<Jugador 1>>>>" << endl;
                        cout<<"Nombre del juagador 1"<<endl;
                        cin>>nombre_jugador_1;                      
			//system("PAUSE");
			//system("cls");
                        cout<<endl<<endl;
			opcion = 0;
			break;
		case 2:
			cout << "<<<<Jugador 2>>>>" << endl;
                        cout<<"Nombre del juagador 2"<<endl;
                        cin>>nombre_jugador_2;                        
			//system("PAUSE");
			//system("cls");
                        cout<<endl<<endl;
			opcion = 0;
			break;
		case 3:
			cout <<" ¡¡¡¡ "<< nombre_jugador_1<< " VS "<< nombre_jugador_2 <<" !!!! "<< endl;
			//system("PAUSE");
			//system("cls");
                        cout<<endl<<endl;
			opcion = 0;
			break;
		}
	} while (opcion != 4); 
	//system("cls");
}
#endif	/* PROCESOS_H */