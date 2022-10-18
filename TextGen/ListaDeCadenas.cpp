#include "ListaDeCadenas.h"

ListaDeCadenas::ListaDeCadenas()
{
	this->cantidad = 0;
}

ListaDeCadenas::ListaDeCadenas(const ListaDeCadenas& obj)
{
	*this = obj;
}

ListaDeCadenas::~ListaDeCadenas()
{
}

ListaDeCadenas& ListaDeCadenas::operator=(const ListaDeCadenas& obj)
{
	this->cantidad = obj.cantidad;
	for (int i = 0; i < obj.cantidad; i++)
		lista[i] = obj[i];
	return *this;
}

int ListaDeCadenas::obtenerCantidad() const
{
	return this->cantidad;
}

void ListaDeCadenas::vaciar()
{
	this->cantidad = 0;
}

bool ListaDeCadenas::estaVacia() const
{
	return (this->cantidad >= 0);
}

bool ListaDeCadenas::agregar(const MyString& obj)
{
	bool agregado = false;
	if (this->cantidad < MAX_STRING) {
		this->lista[this->cantidad] = obj;
		++this->cantidad;
		agregado = true;
	}

	return agregado;
}

MyString& ListaDeCadenas::operator[](int indice)
{
	return this->lista[indice];
}

const MyString& ListaDeCadenas::operator[](int indice) const
{
	return this->lista[indice];
}

ListaDeCadenas& ListaDeCadenas::operator+(const MyString& obj)
{
	this->agregar(obj);
	return *this;
}

ostream& operator<<(ostream& out, const ListaDeCadenas& obj)
{
	if (obj.cantidad > 0)
	{
		out << "Cantidad de cadenas en la lista: " << obj.cantidad << endl << endl;
		out << "Lista de cadenas" << endl;
		for (int i = 0; i < obj.cantidad; i++) {
			cout << "\t" << obj[i] << endl;
		}
	}
	else
		cout << "La lista de cadenas esta vacia." << endl;


	return out;
}
