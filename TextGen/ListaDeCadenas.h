#pragma once
#include<iostream>
#include "MyString.h"
using namespace std;
const int MAX_STRING = 80;

class ListaDeCadenas
{
private:
	MyString lista[MAX_STRING];
	int cantidad;
public:
	ListaDeCadenas();
	ListaDeCadenas(const ListaDeCadenas&);
	~ListaDeCadenas();
	ListaDeCadenas& operator= (const ListaDeCadenas&);

	int obtenerCantidad()const;
	void vaciar();
	bool estaVacia()const;
	bool agregar(const MyString& obj);

	MyString& operator[](int indice);
	const MyString& operator[](int indice)const;
	ListaDeCadenas& operator+(const MyString& obj);

	friend ostream& operator<< (ostream& out, const ListaDeCadenas& obj);


};
