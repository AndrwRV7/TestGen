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
	cout << "Inserte el encabezado deseado para el numero de estudiante: ";
	cin >> idLabel;
	cout << "Inserte el encabezado deseado para la fecha: ";
	cin >> dateLabel;
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


	int choice;
	int i;
	do {
		cout << "Menu de opciones: \n";
		cout << "Oprima 1 para agregar una pregunta. \n";
		cout << "Oprima 2 para remover una pregunta. \n";
		cout << "Oprima 3 para cambiar una pregunta. \n";
		cout << "Oprima 4 para cambiar los encabezados. \n";
		cout << "Oprima 5 para cambiar la fecha. \n";
		cout << "Oprima 6 para cambiar la hora. \n";
		cout << "Oprima 7 para imprimir su examen en pantalla. \n";
		cout << "Oprima 8 para imprimir una pregunta en especifico. \n";
		cout << "Oprima 9 para agregar una pregunta en un lugar en especifico. \n";
		cout << "Oprima 10 para salir del programa. \n";
		cin >> choice;

		switch (choice) {
		default:
			cout << "Error, opcion invalida.";
			break;
		case(1):
			cout << "Inserte su pregunta: ";
			cin >> preg;
			if(preguntas.agregar(preg))cout << "Pregunta agregada.\n";
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case (2):
			cout << "Inserte el numero de la pregunta a remover: ";
			cin >> i;
			if (preguntas.remover(i - 1)) cout << "Pregunta removida\n";
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case(3):
			cout << "Inserte el numero de la pregunta a cambia: ";
			cin >> i;
			cout << "Inserte la pregunta nueva: ";
			cin >> preg;
			if (preguntas.remover(i - 1) && preguntas.insertar(i - 1, preg))cout << "Pregunta cambiada.\n";		
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case(4):
			cout << "Inserte el encabezado deseado para el nombre del estudiante: ";
			cin >> nameLabel;
			cout << "Inserte el encabezado deseado para el numero de estudiante: ";
			cin >> idLabel;
			cout << "Inserte el encabezado deseado para la fecha: ";
			cin >> dateLabel;
			cout << "Inserte el encabezado deseado para la hora: ";
			cin >> timeLabel;
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case(5):
			cout << "Inserte la fecha nueva del examen: " << endl;
			cin >> fecha;
			cout << "Fecha insertada: " << fecha << endl;
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case(6):
			cout << "Inserte la hora nueva del examen: \n";
			cin >> hora;
			cout << "Es am o pm? ";
			cin >> timeOfDay;
			cout << "Hora insertada: " << hora << " " << timeOfDay <<  endl;
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case(7):
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case(8):
			cout << "Que pregunta quieres imprimir? ";
			cin >> i;
			cout << endl << preguntas[i-1] << endl << endl;
			system("pause");
			break;
		case(9):
			cout << "Que numero deseas que sea la pregunta nueva? ";
			cin >> i;
			cout << "Cual es la pregunta al insertar? ";
			cin >> preg;
			if(preguntas.insertar(i-1, preg)) cout << "Pregunta agregada.\n";
			displayInfo(preguntas, fecha, hora, nameLabel, idLabel, dateLabel, timeLabel, timeOfDay);
			system("pause");
			break;
		case (10):
			break;
		}
		

	} while (choice != 10);






	return 0;
}

void displayInfo(ListaDeCadenas preguntas, Date fecha, Time hora, MyString nameL, MyString idL, MyString fechaL, MyString horaL,MyString tOD) {
	cout << "\n\t\tExamen Generado: \n\n";
	cout << nameL << ":_______________________ \t\t" << idL << ":_________________\n";
	cout << fechaL << ": " << fecha << "\t\t\t";
	cout << horaL << ": " << hora << " " << tOD << endl;
	cout << "\nPreguntas:" << endl;
	for (int i = 0; i < preguntas.obtenerCantidad(); i++) {
		cout << "\t" << i + 1 << ".";
		cout << preguntas[i] << "? " << endl << endl;
	}
}
