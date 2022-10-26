#include <iostream>
#include "ListaDeCadenas.h"
#include "Time.h"
#include "Date.hpp"
#include "MyInt.h"
using namespace std;


int main() {

	cout << "This the TestGen main" << endl;

	MyInt a(5), b, c(a); // a:5, b:0, c:5

	MyInt f = a + b; // 5+0

	cout << "b: " << b++ << endl; //0

	b / c; // 1/5

	cout << "c:" << c << endl; // 5

	cout << "f:" << ++f << endl; //6


	return 0;
}


/*Program Specifications :
Add pregunta
Remover pregunta
Cambiar pregunta
Labels del usuario
Fecha, hora, label de nombre usuario (espacio para poner el nombre)
*/