#include <iostream>//Librer�a est�ndar de C++
#include <fstream>//Librer�a para trabajar con archivos tipo txt y bin

using namespace std;//Espacio de trabajo

//VARIABLES GLOBALES
string Lima_nom;
int Lima_tot;
bool Lima_checkRegister=false,Lima_checkAverage=false;
double Lima_promedio,Lima_grade1,Lima_grade2,Lima_grade3;

void Lima_Menu();//declaraci�n de subproceso

double Lima_ValidarNotas(){//Funci�n para validar que el ingreso de notas est� en el rango correcto
    setlocale(LC_ALL,"Spanish");//Para los caracteres en espa�ol
    double Lima_nota;
    cin>>Lima_nota;

    while(Lima_nota<0 || Lima_nota>20){//bucle que valida el rango de la nota
        cout<<"Error del rango num�rico, la nota est� entre 0-20"<<endl;
        cin>>Lima_nota;
    }

    return Lima_nota;//se retorna la nota
}

void Lima_RegistroNotas(){//Procedimiento para Registrar las notas del estudiante
    setlocale(LC_ALL,"Spanish");

    Lima_checkRegister=true;//bandera que valida que se ingres� las notas del estudiante
    cout<<"Ingrese el nombre del estudiante: ";
    fflush(stdin);//Limpia el b�fer de entrada
    getline(cin,Lima_nom);
    cout<<"Ingrese la nota 1: ";
    Lima_grade1=Lima_ValidarNotas();
    cout<<"Ingrese la nota 2: ";
    Lima_grade2=Lima_ValidarNotas();
    cout<<"Ingrese la nota 3: ";
    Lima_grade3=Lima_ValidarNotas();
}

void Lima_Promedio(string Lima_nom,double Lima_grade1, double Lima_grade2, double Lima_grade3,bool Lima_checkRegister){//Procedimiento para calcular el promedio
    setlocale(LC_ALL,"Spanish");
    Lima_checkAverage=true;//bandera para confirmar que se realiz� el promedio del estudiante

    if(!Lima_checkRegister){//comprobador de que las notas se han ingresado
        cout<<"No se encontraron notas disponibles para ser promediadas, ingrese a la primera opci�n del men� para poder ingresarlas"<<endl;
        Lima_Menu();
    }

    Lima_promedio=(Lima_grade1+Lima_grade2+Lima_grade3)/3;//c�lculo del promedio

    cout<<"El promedio del estudiante "<<Lima_nom<<" es de: "<<Lima_promedio<<endl;
}

void Lima_GuardarArchivo(string Lima_nom, double Lima_grade1, double Lima_grade2, double Lima_grade3,double Lima_promedio,bool Lima_checkAverage,bool Lima_checkRegister){//Procedimiento para guardar la informaci�n del estiante en un archivo txt
    setlocale(LC_ALL,"Spanish");

    if(!Lima_checkAverage && !Lima_checkRegister){//Validaci�n de que se registr� y promedi� las notas del estudiante
        cout<<"No se encontraron datos para guardar en el archivo, por favor, registre las notas, promedie y luego puede guardar"<<endl;
        cout<<endl;
        cout<<endl;
        Lima_Menu();
    }

    ofstream Lima_file("Lima_file.txt",ios::app);//Se crea el archivo con la modificaci�n de que se puede sobrescribir la informaci�n de cada estudiante

    if(Lima_file.is_open()){//Abrir el archivo para realizar la escritura en el mismo
        Lima_file<<"-------------------------------------------------------------"<<endl;
        Lima_file<<"Estudiante: "<<Lima_nom<<endl;
        Lima_file<<"Nota 1: "<<Lima_grade1<<endl;
        Lima_file<<"Nota 2: "<<Lima_grade2<<endl;
        Lima_file<<"Nota 3: "<<Lima_grade3<<endl;
        Lima_file<<" "<<endl;
        if(Lima_promedio>=14){//Se verifica si el estudiante aprob� o no
            Lima_file<<"Promedio: "<<Lima_promedio<<", El estudiante aprueba"<<endl;
        }else{
            Lima_file<<"Promedio: "<<Lima_promedio<<", El estudiante reprueba"<<endl;
        }
        Lima_file<<"-------------------------------------------------------------"<<endl;
        Lima_file<<" "<<endl;
    }else{
        cout<<"Error al abrir el archivo, intente de nuevo por favor"<<endl;
        cout<<endl;
        cout<<endl;
        Lima_Menu();
    }
    cout<<"El archivo se guard� correctamente"<<endl;

    Lima_checkAverage=false;Lima_checkRegister=false;//reinicio de banderas
}

void Lima_Menu(){//Procedimiento del men� principal del programa
    setlocale(LC_ALL,"Spanish");
    int Lima_opcMenu;

    cout<<"Escoja una opci�n:"<<endl;
    cout<<"1: Registrar nota de estudiante"<<endl;
    cout<<"2: Realizar promedio"<<endl;
    cout<<"3: Guadar en archivo txt"<<endl;
    cout<<"4: Salir"<<endl;
    cin>>Lima_opcMenu;
    switch(Lima_opcMenu){//Estructura switch para manejar las opciones del men�
        case 1:Lima_RegistroNotas();Lima_Menu();break;
        case 2:Lima_Promedio(Lima_nom,Lima_grade1, Lima_grade2, Lima_grade3,Lima_checkRegister);Lima_Menu();break;
        case 3:Lima_GuardarArchivo(Lima_nom, Lima_grade1, Lima_grade2, Lima_grade3,Lima_promedio,Lima_checkAverage,Lima_checkRegister);Lima_Menu();break;
        case 4:cout<<"Gracias por usar el programa, adi�s c:"<<endl;break;
        default:cout<<"N�mero incorrecto, intente de nuevo por favor"<<endl;Lima_Menu();
    }
}

int main(){//Funci�n principal del programa
    Lima_Menu();
    return 0;
}
