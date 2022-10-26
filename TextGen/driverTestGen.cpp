#include <iostream>
#include "ListaDeCadenas.h"
#include "Time.h"
#include "Date.h"
#include "MyInt.h"
using namespace std;


int main() {

	Date fecha;
	Time hora;
	ListaDeCadenas preguntas;
	int p;
	bool pass = false;
	cout << "Bienvenidos a TestGen: \n\n";
	cout << "De cuantas preguntas es el examen a generar? " << endl;
	cin >> p;
	while (!pass) {
		if (p <= 0 || p == 80) {
			cout << "Error, porfavor entre un numero mayor que 0 y menos que 80 para el numero de preguntas." << endl;
			cin >> p;
		}
		else pass = true;
	}


	return 0;
}


/*Program Specifications :
Add pregunta
Remover pregunta
Cambiar pregunta
Labels del usuario
Fecha, hora, label de nombre usuario (espacio para poner el nombre)
*/