#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED
#include "ValidacionFecha.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct Cedula {
string Nombres, Apellidos, FechaNacimiento, Nacionalidad, LugarNacimiento, Sexo, FechadeVencimiento, NUI;
int DiaN, DiaV, MesN, MesV, AnioN, AnioV;
};
struct PapeletaVotacion{
string FechaVotacion, Provincia, Canton, Paroquia, Junta_No;
int Zona, dia, mes, anio;
struct Cedula CeDatos;
}ArregloDatos[10];

//Variables globales
int CantidadPersonas;
string nombre1[10], nombre2[10], apellido1[10], apellido2[10], Usuario[10];
void PapeletaDatos();
void CUsuario(string nombres, string apellidos, string &nombres1, string &nombres2, string &apellidos1, string &apellidos2, string &usuarios);
void GuardarMenu();
void ResultadosTXT();
void VerDatos();
void CedulaDatos(){
    cout<< "Cuantas cedulas va a registrar(1-3): ";
    cin >> CantidadPersonas;
     while (CantidadPersonas<1 || CantidadPersonas>3){
        cout<< "El valor de ingreso de cedulas es superior a lo establecido"<<endl;
        cout<< "Ingrese otro valor(1-3): ";
        cin>>CantidadPersonas;
    }
    cin.ignore();
    for(int i=0 ; i<CantidadPersonas ; i++){
        cout<< "========================"<<endl;
        cout<< "   REGISTRO DE CEDULA"<<endl;
        cout<< "========================"<<endl;
        cout<< "Ingrese sus nombres: ";
        getline(cin, ArregloDatos[i].CeDatos.Nombres);
        cout<< "Ingrese sus apellidos: ";
        getline(cin, ArregloDatos[i].CeDatos.Apellidos);
        cout<< "Ingrese su nacionalidad:";
        cin>> ArregloDatos[i].CeDatos.Nacionalidad;
        cout<< "Ingrese su fecha de nacimiento(dd/mm/anio):";
        cin>> ArregloDatos[i].CeDatos.FechaNacimiento;
        validacionF(ArregloDatos[i].CeDatos.FechaNacimiento, ArregloDatos[i].CeDatos.DiaN, ArregloDatos[i].CeDatos.MesN, ArregloDatos[i].CeDatos.AnioN);
        cout<< "Ingrese su lugar de nacimiento: ";
        cin>> ArregloDatos[i].CeDatos.LugarNacimiento;
        cout<< "Ingrese su sexo: ";
        cin>> ArregloDatos[i].CeDatos.Sexo;
        cout<< "Ingrese su NUI: ";
        cin>> ArregloDatos[i].CeDatos.NUI;
        while (ArregloDatos[i].CeDatos.NUI.size() !=10){
            cout<< "La cedula no puede tener mas o menos de 10 dijitos"<<endl;
            cout<< "Ingrese otros valores: ";
            cin >>  ArregloDatos[i].CeDatos.NUI;
        }
        ArregloDatos[i].CeDatos.AnioV=ArregloDatos[i].CeDatos.AnioN+10;
    }
    PapeletaDatos();

}
void PapeletaDatos(){
    cout<< "========================================="<<endl;
    cout<< "   REGISTRO DE LA PAPELETA DE VOTACION"<<endl;
    cout<< "========================================="<<endl;
    cin.ignore();
    for(int i=0 ; i<CantidadPersonas ; i++){
    cout<< "Ingrese La fecha de votacion: ";
    cin >>ArregloDatos[i].FechaVotacion;
    validacionF(ArregloDatos[i].FechaVotacion, ArregloDatos[i].dia, ArregloDatos[i].mes, ArregloDatos[i].anio);
    cout<< "Ingrese su provincia: ";
    cin>> ArregloDatos[i].Provincia;
    cout<< "Ingrese su canton: ";
    cin>> ArregloDatos[i].Canton;
    cout<< "Ingrese su paroquia: ";
    cin>> ArregloDatos[i].Paroquia;
    cout<< "Ingrese su zona(1-5): ";
    cin>> ArregloDatos[i].Zona;
    while (ArregloDatos[i].Zona<1 ||ArregloDatos[i].Zona>5 ){
        cout<< "La zona que intetnta igresar no existe. Ingrese otra zona: ";
        cin>> ArregloDatos[i].Zona;
    }
    cin.ignore();
    cout<< "Ingrese la junta que le toco: ";
    getline(cin, ArregloDatos[i].Junta_No);
    }
    GuardarMenu();
}

void Resultados(){
    for(int i=0 ; i<CantidadPersonas ; i++){
    cout<< "======================================"<<endl;
    cout<< "              Usurio: "<<i+1<<endl;
    cout<< "======================================"<<endl;
    cout<< "------------------------"<<endl;
    cout<< "        CEDULA"<<endl;
    cout<< "------------------------"<<endl;
    cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<< "               REPUCBLICA DEL ECUADOR"<<endl;
    cout<< "APELLIDOS: "<<ArregloDatos[i].CeDatos.Apellidos<<endl;
    cout<< "NOMBRES: "<<ArregloDatos[i].CeDatos.Nombres<<endl;
    cout<< "NACIONALIDAD: "<<ArregloDatos[i].CeDatos.Nacionalidad<<endl;
    cout<< "FECHA DE NACIMIENTO: "<<ArregloDatos[i].CeDatos.FechaNacimiento<<endl;
    cout<< "LUGAR DE NACIMIENTO: "<<ArregloDatos[i].CeDatos.LugarNacimiento<<endl;
    cout<< "NUI: "<<ArregloDatos[i].CeDatos.NUI<<"  SEXO: "<<ArregloDatos[i].CeDatos.Sexo<<endl;
    cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<< "--------------------------"<<endl;
    cout<< "   PAPELETA DE VOTACIOM"<<endl;
    cout<< "--------------------------"<<endl;
    cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<< "               CERTIFICADO DE VOTACION"<<endl;
    cout<< "                "<< ArregloDatos[i].FechaVotacion<<endl;
    cout<< ArregloDatos[i].CeDatos.Apellidos<<" "<<ArregloDatos[i].CeDatos.Nombres<<endl;
    cout<< "PROVINCIA: "<<ArregloDatos[i].Provincia<<endl;
    cout<< "CANTON: "<<ArregloDatos[i].Canton<<endl;
    cout<< "PAROQUIA: "<<ArregloDatos[i].Paroquia<<endl;
    cout<< "ZONA: "<<ArregloDatos[i].Zona<<endl;
    cout<< "JUNTA NO: "<<ArregloDatos[i].Junta_No<<"           CC N:"<< ArregloDatos[i].CeDatos.NUI<<endl;
    cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    }
}
void GuardarTXT(){
    ofstream archivo;
    for(int i=0 ; i<CantidadPersonas ; i++){
        CUsuario(ArregloDatos[i].CeDatos.Nombres, ArregloDatos[i].CeDatos.Apellidos, nombre1[i], nombre2[i], apellido1[i], apellido2[i], Usuario[i]);
        archivo.open(Usuario[i],ios::out);
        if (archivo.fail()) {
            cout << "No se pudo abrir este archivo" << endl;
            return;
        }
        archivo<< "======================================"<<endl;
        archivo<< "              Usurio: "<<i+1<<endl;
        archivo<< "======================================"<<endl;
        archivo<< "------------------------"<<endl;
        archivo<< "        CEDULA"<<endl;
        archivo<< "------------------------"<<endl;
        archivo<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        archivo<< "               REPUCBLICA DEL ECUADOR"<<endl;
        archivo<< "APELLIDOS: "<<ArregloDatos[i].CeDatos.Apellidos<<endl;
        archivo<< "NOMBRES: "<<ArregloDatos[i].CeDatos.Nombres<<endl;
        archivo<< "NACIONALIDAD: "<<ArregloDatos[i].CeDatos.Nacionalidad<<endl;
        archivo<< "FECHA DE NACIMIENTO: "<<ArregloDatos[i].CeDatos.FechaNacimiento<<endl;
        archivo<< "LUGAR DE NACIMIENTO: "<<ArregloDatos[i].CeDatos.LugarNacimiento<<endl;
        archivo<< "NUI: "<<ArregloDatos[i].CeDatos.NUI<<"  SEXO: "<<ArregloDatos[i].CeDatos.Sexo<<endl;
        archivo<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        archivo<< "--------------------------"<<endl;
        archivo<< "   PAPELETA DE VOTACIOM"<<endl;
        archivo<< "--------------------------"<<endl;
        archivo<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        archivo<< "               CERTIFICADO DE VOTACION"<<endl;
        archivo<< "                "<< ArregloDatos[i].FechaVotacion<<endl;
        archivo<< ArregloDatos[i].CeDatos.Apellidos<<" "<<ArregloDatos[i].CeDatos.Nombres<<endl;
        archivo<< "PROVINCIA: "<<ArregloDatos[i].Provincia<<endl;
        archivo<< "CANTON: "<<ArregloDatos[i].Canton<<endl;
        archivo<< "PAROQUIA: "<<ArregloDatos[i].Paroquia<<endl;
        archivo<< "ZONA: "<<ArregloDatos[i].Zona<<endl;
        archivo<< "JUNTA NO: "<<ArregloDatos[i].Junta_No<<"           CC N:"<< ArregloDatos[i].CeDatos.NUI<<endl;
        archivo<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;


        archivo.close();
    }
}
void leerTXT(){
    ifstream archivo;
    string texto, nombre;
    cin.ignore();
    cout<< "Ingrese el primer nombre y el primer apellido de la persona que busca sus documentos: ";
    getline(cin, nombre);
    archivo.open(nombre, ios::in);
    if (archivo.fail()) {
        cout << "No se encuentra el esta persona " << endl;
        VerDatos();
    }
    while (!archivo.fail()){
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    archivo.close();
}
void GuardarBin(){
    ofstream archivo;
    string Usuarios[10];
    for(int i=0 ; i<CantidadPersonas ; i++){
        CUsuario(ArregloDatos[i].CeDatos.Nombres, ArregloDatos[i].CeDatos.Apellidos, nombre1[i], nombre2[i], apellido1[i], apellido2[i], Usuario[i]);
        Usuarios[i]=Usuario[i]+".bin";
        archivo.open(Usuarios[i],ios::binary);
        if (archivo.fail()) {
            cout << "No se pudo abrir este archivo" << endl;
            return;
        }
    archivo.write(reinterpret_cast<char*>(&ArregloDatos[i]), sizeof(PapeletaVotacion));
    archivo.close();
}
}
void LeerBin(){
    string nombre, nombreC;
    cin.ignore();
    cout<< "Ingrese el primer nombre y el primer apellido de la persona que busca sus documentos: ";
    getline(cin, nombre);
    nombreC=nombre+".bin";
    ifstream archivo(nombreC, ios::binary);
    if (archivo.fail()) {
        cout << "No se encuentra el esta persona " << endl;
    }
    for (int i = 0; i < CantidadPersonas; ++i) {
        while (archivo.read((char*)&ArregloDatos[i], sizeof(PapeletaVotacion))){
            cout<< "======================================"<<endl;
            cout<< "              Usurio: "<<i+1<<endl;
            cout<< "======================================"<<endl;
            cout<< "------------------------"<<endl;
            cout<< "        CEDULA"<<endl;
            cout<< "------------------------"<<endl;
            cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
            cout<< "               REPUCBLICA DEL ECUADOR"<<endl;
            cout<< "APELLIDOS: "<<ArregloDatos[i].CeDatos.Apellidos<<endl;
            cout<< "NOMBRES: "<<ArregloDatos[i].CeDatos.Nombres<<endl;
            cout<< "NACIONALIDAD: "<<ArregloDatos[i].CeDatos.Nacionalidad<<endl;
            cout<< "FECHA DE NACIMIENTO: "<<ArregloDatos[i].CeDatos.FechaNacimiento<<endl;
            cout<< "LUGAR DE NACIMIENTO: "<<ArregloDatos[i].CeDatos.LugarNacimiento<<endl;
            cout<< "NUI: "<<ArregloDatos[i].CeDatos.NUI<<"  SEXO: "<<ArregloDatos[i].CeDatos.Sexo<<endl;
            cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
            cout<< "--------------------------"<<endl;
            cout<< "   PAPELETA DE VOTACIOM"<<endl;
            cout<< "--------------------------"<<endl;
            cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
            cout<< "               CERTIFICADO DE VOTACION"<<endl;
            cout<< "                "<< ArregloDatos[i].FechaVotacion<<endl;
            cout<< ArregloDatos[i].CeDatos.Apellidos<<" "<<ArregloDatos[i].CeDatos.Nombres<<endl;
            cout<< "PROVINCIA: "<<ArregloDatos[i].Provincia<<endl;
            cout<< "CANTON: "<<ArregloDatos[i].Canton<<endl;
            cout<< "PAROQUIA: "<<ArregloDatos[i].Paroquia<<endl;
            cout<< "ZONA: "<<ArregloDatos[i].Zona<<endl;
            cout<< "JUNTA NO: "<<ArregloDatos[i].Junta_No<<"           CC N:"<< ArregloDatos[i].CeDatos.NUI<<endl;
            cout<< "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
        }

    }
    archivo.close();


}
void EliminarBin(string nombres){
    if (remove(nombres.c_str()) == 0) {
    cout << "ARCHIVO ELIMINADO" <<endl;
    } else {
    cout << "ERROR AL ELIMINAR ARCHIVO"<<endl;
    }

}
void EliminarTXT(){
    string nombre, nombreC;
    cin.ignore();
    cout<< "Ingrese el primer nombre y el primer apellido para eliminar el documento: ";
    getline(cin, nombre);
    nombreC=nombre+".bin";
    if (remove(nombreC.c_str()) == 0) {
    cout << "ARCHIVO ELIMINADO" <<endl;
    } else {
    cout << "ERROR AL ELIMINAR ARCHIVO"<<endl;
    }
    EliminarBin(nombreC);
}

void CUsuario(string nombres, string apellidos, string &nombres1, string &nombres2, string &apellidos1, string &apellidos2, string &usuarios) {
        size_t espacio1, espacio2;
        espacio1= nombres.find(' ');
        nombres1 = nombres.substr(0, espacio1);
        nombres2 = nombres.substr(espacio1 + 1);

        espacio2= apellidos.find(' ');
        apellidos1 = apellidos.substr(0, espacio2);
        apellidos2 = apellidos.substr(espacio2 + 1);
        usuarios =nombres1+" "+apellidos1;
}
#endif // DATOS_H_INCLUDED
