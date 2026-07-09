/*
 * ============================================================
 *  LOGICA DE PROGRAMACION
 *  ACTIVIDAD 3 - FLUJO DE CONTROL PART. 2
 *  Prof. Gamalier Reyes del Carmen
 *
 *  Descripcion:
 *  Programa que utiliza bucles para leer el nombre y las 4
 *  calificaciones de "n" estudiantes, calcula el promedio de
 *  cada uno, determina si aprobo o reprobo (nota minima de
 *  aprobacion: 70 puntos), y muestra los resultados en pantalla
 *  en forma de tabla, usando tabulacion para alinear las columnas.
 * ============================================================
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const double NOTA_MINIMA_APROBATORIA = 70.0;

struct Estudiante {
    string nombre;
    double notas[4];
    double promedio;
    string estatus;
};

int main() {
    int cantidadEstudiantes = 0;
    vector<Estudiante> estudiantes;

    cout << "=====================================================\n";
    cout << "   REGISTRO DE CALIFICACIONES - PROMEDIO Y ESTATUS\n";
    cout << "=====================================================\n\n";

    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    cin >> cantidadEstudiantes;

    // Validacion basica de la cantidad ingresada
    if (cin.fail() || cantidadEstudiantes <= 0) {
        cout << "\nError: Debe ingresar un numero valido de estudiantes (mayor a 0).\n";
        return 1;
    }

    // Bucle principal: recorre cada estudiante (for)
    for (int i = 0; i < cantidadEstudiantes; i++) {
        Estudiante est;
        double suma = 0.0;

        cout << "\n--- Estudiante " << (i + 1) << " de " << cantidadEstudiantes << " ---\n";
        cout << "Nombre completo: ";
        cin.ignore();
        getline(cin, est.nombre);

        // Bucle anidado: recorre las 4 calificaciones del estudiante actual (for)
        for (int j = 0; j < 4; j++) {
            cout << "  Nota " << (j + 1) << " (0-100): ";
            cin >> est.notas[j];
            suma += est.notas[j];
        }

        // Calculo del promedio
        est.promedio = suma / 4.0;

        // Flujo de control (if / else) para determinar el estatus
        if (est.promedio >= NOTA_MINIMA_APROBATORIA) {
            est.estatus = "Aprobado";
        }
        else {
            est.estatus = "Reprobado";
        }

        estudiantes.push_back(est);
    }

    // Presentacion de resultados en formato de tabla, usando tabulacion (setw)
    cout << "\n\n=====================================================================\n";
    cout << "                       RESULTADOS FINALES\n";
    cout << "=====================================================================\n";

    cout << left << setw(20) << "Estudiante"
        << right << setw(8) << "Nota 1"
        << setw(8) << "Nota 2"
        << setw(8) << "Nota 3"
        << setw(8) << "Nota 4"
        << setw(10) << "Promedio"
        << setw(12) << "Estatus" << "\n";

    cout << string(74, '-') << "\n";

    cout << fixed << setprecision(2);

    // Bucle que recorre el vector de estudiantes para imprimir la tabla (for)
    for (size_t i = 0; i < estudiantes.size(); i++) {
        cout << left << setw(20) << estudiantes[i].nombre
            << right << setw(8) << estudiantes[i].notas[0]
            << setw(8) << estudiantes[i].notas[1]
            << setw(8) << estudiantes[i].notas[2]
            << setw(8) << estudiantes[i].notas[3]
            << setw(10) << estudiantes[i].promedio
            << setw(12) << estudiantes[i].estatus << "\n";
    }

    cout << string(74, '-') << "\n";

    return 0;
}