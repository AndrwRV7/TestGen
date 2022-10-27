#include <iostream>
#include "ListaDeCadenas.h"
#include "Time.h"
#include "Date.h"
#include "MyInt.h"
using namespace std;
void displayInfo(ListaDeCadenas,Date,Time,MyString,MyString,MyString,MyString,MyString);

int main() {

	Date fecha;
	Time hora;
	ListaDeCadenas preguntas;
	int p;
	bool pass = false;
	MyString nameLabel, idLabel, dateLabel, timeLabel, timeOfDay;
	cout << "Bienvenidos a TestGen: \n\n";
	cout << "De cuantas preguntas es el examen a generar? " << endl;
	cin >> p;
	while (!pass) {
		if (p <= 0 || p > 80) {
			cout << "Error, porfavor entre un numero mayor que 0 y menos que 80 para el numero de preguntas." << endl;
			cin >> p;
		}
		else pass = true;
	}
	cout << "Inserte el encabezado deseado para el nombre del estudiante: ";
	cin >> nameLabel;
	cout << "Inserte el encabezado deseado para la fecha: ";
	cin >> dateLabel;
	cout << "Inserte el encabezado deseado para el numero de estudiante: ";
	cin >> idLabel;
	cout << "Inserte el encabezado deseado para la hora: ";
	cin >> timeLabel;
	MyString preg;
	for (int i = 0; i < p; i++) {
		cout << "Inserte la pregunta #" << i + 1 << endl;
		cin >> preg;
		preguntas.agregar(preg);
	}
	cout << "Inserte la fecha del examen: " << endl;
	cin >> fecha;
	cout << "Inserte la hora del examen: \n";
	cin >> hora;
	cout << "Es am o pm? ";
	cin >> timeOfDay;
	displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
	/*cout << fecha;
	cout << hora;
	cout << "Preguntas:" << endl;
	for (int i = 0; i < p; i++) {
		cout << "\t" << i + 1 << ".";
		cout << preguntas[i] << endl << endl;
	}*/



	return 0;
}


/*Program Specifications :
Add pregunta
Remover pregunta
Cambiar pregunta
Labels del usuario
Fecha, hora, label de nombre usuario (espacio para poner el nombre)
*/

void displayInfo(ListaDeCadenas preguntas, Date fecha, Time hora, MyString nameL, MyString idL, MyString fechaL, MyString horaL,MyString tOD) {
	cout << "\n\t\tExamen Generado: \n\n";
	cout << nameL << ":_______________________ \t\t" << idL << ":_________________\n";
	cout << fechaL << ": " << fecha << "\t\t\t";
	cout << horaL << ": " << hora << " " << tOD << endl;
	cout << "Preguntas:" << endl;
	for (int i = 0; i < preguntas.obtenerCantidad(); i++) {
		cout << "\t" << i + 1 << ".";
		cout << preguntas[i] << "? " << endl << endl;
	}


}
