#ifndef TIPOSTDA_H_INCLUDED
#define TIPOSTDA_H_INCLUDED

#include<iostream>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

string verificar;
int paso;

void Introduccion();
int VerificarString(string verificar,int paso);
void PilaEjemplo();
void ColaEjemplo();
void ListaEjemplo();

void Introduccion(){
    string opcTDA;
    int opcTDAN;

    setlocale(LC_ALL,"Spanish");
    cout<<"Los TDA son formas de estructurar datos en programación. Se refiere a las operaciones que se realizan\ncon/en estas estructuras sin detallar en particular que ocurre internamente.\nEstos TDA se dividen principalmente en 3, pila, cola y lista, escoja una para acceder a un ejercicio práctico, si quiere salir \nescriba \"Salir\":"<<endl;
    fflush(stdin);
    getline(cin,opcTDA);
    switch(VerificarString(opcTDA,1)){
        case 1:PilaEjemplo();Introduccion();break;
        case 2:ColaEjemplo();Introduccion();break;
        case 3:ListaEjemplo();Introduccion();break;
        case 4:cout<<"Volviendo al menú principal"<<endl;break;
    }
}

void PilaEjemplo(){
    string canLibros,librosApilar,librosRegistro[6],librosBuscar;
    stack<string> pila;//declaración para la pila
    int canLibrosI,pos;
    bool pasoLibroEncontrado;

    // Implementación de una pila (stack)
    cout<<"Ingresó al ejemplo de pila, la estructura pila trata de que los datos que usted agregue a dicha \nestructura se apilarán uno encima de otro. Las pilas siguen la regla LIFO, es decir, el último que se ingresa \nserá el primero en salir."<<endl<<endl;
    cout<<"Ejemplo práctico: Se va a apilar una serie de libros, ingrese cuántos libros va a apilar:"<<endl;
    fflush(stdin);
    getline(cin,canLibros);
    canLibrosI=VerificarString(canLibros,2);

    for(int i=0;i<canLibrosI;i++){
        cout<<"Ingrese el libro "<<i+1<<endl;
        getline(cin,librosApilar);
        pila.push(librosApilar);
        librosRegistro[i]=librosApilar;
    }

    cout << "La pila de libros fue creada, el libro en la cima es:\n";
    cout << pila.top() <<endl; // Imprime el elemento en la cima

    pasoLibroEncontrado=false;
    do{
        cout<<endl<<"Ingrese el libro que desea obtener: "<<endl;
        fflush(stdin);
        getline(cin,librosBuscar);
        int j=0;
        for(int i=canLibrosI;i>0;i--){
            if(librosBuscar==librosRegistro[i]){
                pasoLibroEncontrado=true;
                pos=j;

            }
            j++;
        }
        if(!pasoLibroEncontrado){
            cout<<"Error, ese libro no fue ingresado a la pila. ";
        }
    }while(!pasoLibroEncontrado);

    if(paso=0){
        //Si paso es igual a 0, el libro requerido es el último que se añadió
        cout<<"El libro deseado fue el último en añadirse:\n";
        cout << pila.top() << " "; // Imprime el elemento en la cima
        pila.pop();
    }else{
        cout<<"Se retiran los siguientes libros para llegar al deseado:"<<endl;
        for(int i=1;i<pos && !pila.empty();i++){
            cout << pila.top() << " "; // Imprime el elemento en la cima
            pila.pop();
        }
        cout<<endl<<"Al retirar los libros anteriores, se accede al libro deseado:\n";
        cout << pila.top() << " "; // Imprime el elemento en la cima
        pila.pop();
    }
    cout<<endl<<endl<<endl;
}

void ColaEjemplo(){
    queue<string> cola;
    string colaPersonas[4]={"Ana","Pedro","Sofia","Ashly"},personaDespachar;

    cout<<"Ingresó al ejemplo de cola, la estructura cola trata de que los datos que usted agregue a dicha \nestructura se formarán uno detrás del otro. Las colas siguen la regla FIFO, es decir, el primero que se ingresa \nserá el primero en salir."<<endl<<endl;
    cout<<"Ejemplo práctico: Se va a formar una cola de personas y como despachador de comida deberá entregar el pedido \na la persona correspondiente:"<<endl;

    cout<<"================================================================"<<endl;
    cout<<"                           KFC"<<endl;
    cout<<"================================================================"<<endl;

    cout<<"La cola de clientes en espera de su comida es la siguiente:"<<endl;
    cola.push("Ana");
    cola.push("Pedro");
    cola.push("Sofia");
    cola.push("Ashly");
    for(int i=0;i<4;i++){
        cout<<colaPersonas[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<4 && !cola.empty();i++){
        cout<<"Pedido "<<i+1<<", listo para entregar, ingrese el nombre de la persona por entregar el pedido:"<<endl;
        fflush(stdin);
        getline(cin,personaDespachar);
        while(personaDespachar!=cola.front()){
            cout<<"Error, la persona ingresada no es la primera formada, ingrese el mismo nombre a cómo fue \npresentada por favor:"<<endl;
            fflush(stdin);
            getline(cin,personaDespachar);
        }
        cout<<cola.front()<<", agradece la comida y se retira de la cola, continúe despachando los clientes"<<endl;
        cola.pop();
        cout<<"================================================================"<<endl;
    }
    cout << "Todos los clientes fueron despachados, la cola se ha vaciado, gracias por probar el programa"<<endl;
}

void ListaEjemplo(){
    int canTareasI;
    string canTareas,tareaEnlistada;
    list<string> lista;

    cout<<"Ingresó al ejemplo de lista, la estructura lista trata de que los datos que usted agregue a dicha \nestructura se enlazarán el uno al otro. Las listas permiten acceder a cualquier elemeno que se haya ingresado \nen ellas."<<endl<<endl;
    cout<<"Ejemplo práctico: Se va a enlistar una serie de tareas por hacer.\nIngrese la cantidad de tareas a enlistar:"<<endl;
    fflush(stdin);
    getline(cin,canTareas);
    canTareasI=VerificarString(canTareas,2);

    cout<<endl;
    for(int i=0;i<canTareasI;i++){
        cout<<"Ingrese tarea "<<i+1<<endl;
        getline(cin,tareaEnlistada);
        lista.push_back(tareaEnlistada);
    }

    cout << "Lista de tareas: ";
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " "; // Imprime los elementos de la lista
    }
    cout << endl;
}

int VerificarString(string verificar, int paso){
    int numDevuelto;

    if(paso==1){
        transform(verificar.begin(),verificar.end(),verificar.begin(),::tolower);
        while(verificar.find("cola")!=0 && verificar.find("lista")!=0 && verificar.find("pila")!=0 && verificar.find("salir")!=0){
            cout<<"Error, ingrese cola, lista o pila por favor:"<<endl;
            fflush(stdin);
            getline(cin,verificar);
        }
        if(verificar=="pila"){
            numDevuelto=1;
        }else if(verificar=="cola"){
            numDevuelto=2;
        }else if(verificar=="lista"){
            numDevuelto=3;
        }else if(verificar=="salir"){
            numDevuelto=4;
        }
        return numDevuelto;
    }else if(paso==2){
        while(!all_of(verificar.begin(),verificar.end(),::isdigit) || stoi(verificar)<1 || stoi(verificar)>5){
            cout<<"Error, ingrese un valor válido por favor, entre 1 y 5:"<<endl;
            fflush(stdin);
            getline(cin,verificar);
        }
        numDevuelto=stoi(verificar);
        return numDevuelto;
    }
    cout<<"FALLO EN LA VALIDACION CONTACTE CON EL ADMIN"<<endl;
    exit(1);
}

#endif // TIPOSTDA_H_INCLUDED
