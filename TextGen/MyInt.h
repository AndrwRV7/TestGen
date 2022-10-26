#pragma once
#include<iostream>
using namespace std;

class MyInt
{
private:
	int value;
public:
	MyInt(int v = 0);
	MyInt(const MyInt&);
	~MyInt();

	MyInt& operator=(const MyInt&);
	MyInt& operator=(int value);

	MyInt operator+(const MyInt& i)const;
	MyInt operator+(int value)const;
	friend MyInt operator+(int value, const MyInt& i);

	MyInt operator-(const MyInt& i)const;
	MyInt operator-(int value)const;
	friend MyInt operator-(int value, const MyInt& i);

	MyInt operator*(const MyInt& i)const;
	MyInt operator*(int value)const;
	friend MyInt operator*(int value, const MyInt& i);

	MyInt operator/(const MyInt& i)const;
	MyInt operator/(int value)const;
	friend MyInt operator/(int value, const MyInt& i);

	MyInt operator%(const MyInt& i)const;
	MyInt operator%(int value)const;
	friend MyInt operator%(int value, const MyInt& i);


	MyInt absolute()const;
	int getValue()const;
	void setValue(int);

	bool operator==(const MyInt& i)const;
	bool operator==(int value)const;
	friend bool operator==(int value, const MyInt& i);

	bool operator!=(const MyInt& i)const;
	bool operator!=(int value)const;
	friend bool operator!=(int value, const MyInt& i);

	bool operator<=(const MyInt& i)const;
	bool operator<=(int value)const;
	friend bool operator<=(int value, const MyInt& i);

	bool operator>=(const MyInt& i)const;
	bool operator>=(int value)const;
	friend bool operator>=(int value, const MyInt& i);

	bool operator>(const MyInt& i)const;
	bool operator>(int value)const;
	friend bool operator>(int value, const MyInt& i);

	bool operator<(const MyInt& i)const;
	bool operator<(int value)const;
	friend bool operator<(int value, const MyInt& i);

	MyInt operator+=(const MyInt& i);
	MyInt operator+=(int value);
	friend MyInt operator+=(int value, const MyInt& i);

	MyInt operator-=(const MyInt& i);
	MyInt operator-=(int value);
	friend MyInt operator-=(int value, const MyInt& i);

	MyInt operator*=(const MyInt& i);
	MyInt operator*= (int value);
	friend MyInt operator*=(int value, const MyInt& i);

	MyInt operator/=(const MyInt& i);
	MyInt operator/=(int value);
	friend MyInt operator/=(int value, const MyInt& i);

	MyInt operator%=(const MyInt& i);
	MyInt operator%=(int value);
	friend MyInt operator%=(int value, const MyInt& i);

	MyInt operator+()const;
	MyInt operator-()const;

	MyInt& operator++();
	MyInt operator++(int);

	MyInt& operator--();
	MyInt operator--(int);

	operator int() const;

	friend ostream& operator<<(ostream& out, const MyInt& i);
	friend istream& operator>>(istream& in, MyInt& i);
};

