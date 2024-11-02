#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

#include<iostream>
#include"Menu.h"
#include"TiposTDA.h"

using namespace std;//Espacio del trabajo

//DECLARACIÓN DE SUBPROGRAMAS
void Encabezado();
void MenuPrincipal();

void Encabezado(){//Inicio del procedimiento
    int tamaCabecera=9;

    string cabecera[tamaCabecera][1]={"=======================================================================================","UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE SEDE SANTO DOMINGO","ITIN","Asignatura: FUNDAMENTOS DE PROGRAMACION","EstudianteS: Jimez Diego, Angel Lima","Nivel: 1ERO. A","Fecha: 18-08-2024","Tema: Proyecto de la Unidad 3","======================================================================================="};
    for(int i=0;i<tamaCabecera;i++){
        cout<<cabecera[i][0]<<endl;
    }
    MenuPrincipal();
 }//Fin del procedimiento

void MenuPrincipal(){//Inicio del procedimiento
    int opcMenuPrincipal;

    setlocale(LC_ALL,"Spanish");
    cout<<endl<<endl<<"En este programa encontrará un generador de un archivo de como se vería su cédula y papeleta de votación tras añadir sus datos."<<endl;
    string menuPrincipal[4]={"Escoja la opcion por favor:","1: Ingreso de datos","2: Consulta de Pilas, Colas, y Listas","3: Salida"};
    for(int i=0;i<4;i++){
        cout<<menuPrincipal[i]<<endl;
    }
    cin>>opcMenuPrincipal;
    switch (opcMenuPrincipal){
    case 1:
        Menu();
        MenuPrincipal();
        break;
    case 2:
        Introduccion();
        MenuPrincipal();
        break;
    case 3:
        cout<<"Gracias por usar el programa, tenga buen día"<<endl;
        break;
    default: cout<<"Entrada no válida, inténte de nuevo por favor."<<endl;
        MenuPrincipal();
    }
}//Fin del procedimiento

#endif // ESTRUCTURA_H_INCLUDED
