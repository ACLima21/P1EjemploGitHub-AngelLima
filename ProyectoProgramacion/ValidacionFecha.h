#ifndef VALIDACIONFECHA_H_INCLUDED
#define VALIDACIONFECHA_H_INCLUDED
#include <string>
using namespace std;

bool validacionF(string Fechanacimiento1, int &dia, int &anio, int &mes) {
    bool fechavalida = false;
    do {
        if (Fechanacimiento1.size() == 10 &&
            isdigit(Fechanacimiento1[0]) && isdigit(Fechanacimiento1[1]) &&
            Fechanacimiento1[2] == '/' &&
            isdigit(Fechanacimiento1[3]) && isdigit(Fechanacimiento1[4]) &&
            Fechanacimiento1[5] == '/' &&
            isdigit(Fechanacimiento1[6]) && isdigit(Fechanacimiento1[7]) &&
            isdigit(Fechanacimiento1[8]) && isdigit(Fechanacimiento1[9])) {

            dia = stoi(Fechanacimiento1.substr(0, 2));
            mes = stoi(Fechanacimiento1.substr(3, 2));
            anio = stoi(Fechanacimiento1.substr(6, 4));

            if (mes < 1 || mes > 12) {
                cout << "Mes inválido. Ingrese los datos dentro de los parámetros (dd/mm/aaaa): ";
                cin >> Fechanacimiento1;
            } else if (dia < 1 || dia > 31) {
                cout << "Día inválido. Ingrese los datos dentro de los parámetros (dd/mm/aaaa): ";
                cin >> Fechanacimiento1;
            } else if (anio < 1995 || anio > 2024) {
                cout << "Año inválido. Ingrese los datos dentro de los parámetros (dd/mm/aaaa): ";
                cin >> Fechanacimiento1;
            } else {
                fechavalida = true;
                cout << "Fecha válida." << endl;
            }
        } else {
            cout << "Formato de fecha inválido. Ingrese los datos en formato (dd/mm/aaaa): ";
            cin >> Fechanacimiento1;
        }
    } while (!fechavalida);

    return fechavalida;
}


#endif // VALIDACIONFECHA_H_INCLUDED
