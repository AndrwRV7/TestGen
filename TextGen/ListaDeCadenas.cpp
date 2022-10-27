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

bool ListaDeCadenas::estaLleno() const
{
	return (this->cantidad >= MAX_STRING);
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

bool ListaDeCadenas::insertar(int indice, const MyString& obj)
{
	bool inserted = false;
	if (indice >= 0 && indice <= this->cantidad && !this->estaLleno()) {
		for (int i = this->cantidad; i > indice; i--) {
			(*this)[i] = (*this)[i - 1];
		}

		(*this)[indice] = obj;
		inserted = true;
		++this->cantidad;
	}
	return inserted;
}

bool ListaDeCadenas::insertarAlComienzo(const MyString& obj)
{
	return insertar(0,obj);
}

bool ListaDeCadenas::removerElUltimo()
{
	bool removido = false;
	if (!this->estaVacia()) {
		--(this->cantidad);
		removido = true;
	}
	return removido;	
}

bool ListaDeCadenas::remover(int indice)
{
	bool removido = false;
	if (indice >= 0 && indice < cantidad && !this->estaVacia()) {
		for (int i = indice; i < this->cantidad - 1; i++) {
			(*this)[i] = (*this)[i + 1];
		}
		--(this->cantidad);
		removido = true;
	}
	return removido;
}

bool ListaDeCadenas::removerElPrimero()
{
	return this->remover(0);
}

ostream& operator<<(ostream& out, const ListaDeCadenas& obj)
{
	if (obj.cantidad > 0)
	{
		for (int i = 0; i < obj.cantidad; i++) {
			cout << obj[i] << endl;
		}
	}
	else
		cout << "La lista de cadenas esta vacia." << endl;


	return out;
}
