#include "MyInt.h"

MyInt::MyInt(int v)
{
	this->value = v;
}

MyInt::MyInt(const MyInt& i)
{
	*this = i;
}

MyInt::~MyInt()
{
}

MyInt& MyInt::operator=(const MyInt& i)
{
	this->value = i.getValue();
	return *this;
}

MyInt& MyInt::operator=(int value)
{
	this->value = value;
	return *this;
}

MyInt MyInt::operator+(const MyInt& i) const
{
	return MyInt(this->getValue() + i.getValue());
}

MyInt MyInt::operator+(int value) const
{
	return MyInt(this->getValue() + value);
}

MyInt MyInt::operator-(const MyInt& i) const
{
	return MyInt(this->getValue() - i.getValue());
}

MyInt MyInt::operator-(int value) const
{
	return MyInt(this->getValue() - value);
}

MyInt MyInt::operator*(const MyInt& i) const
{
	return MyInt(this->getValue() * i.getValue());
}

MyInt MyInt::operator*(int value) const
{
	return MyInt(this->getValue() * value);
}

MyInt MyInt::operator/(const MyInt& i) const
{
	return MyInt(this->getValue() / i.getValue());
}

MyInt MyInt::operator/(int value) const
{
	return MyInt(this->getValue() / value);
}

MyInt MyInt::absolute() const
{
	return ((*this > 0) ? MyInt(this->getValue()) : MyInt(-(this->getValue())));
}

int MyInt::getValue() const
{
	return this->value;
}

void MyInt::setValue(int v)
{
	this->value = v;
}

bool MyInt::operator==(const MyInt& i) const
{
	return (this->getValue() == i.getValue());
}

bool MyInt::operator==(int value) const
{
	return (this->getValue() == value);
}

bool MyInt::operator!=(const MyInt& i) const
{
	return (this->getValue() != i.getValue());
}

bool MyInt::operator!=(int value) const
{
	return (this->getValue() != value);
}

bool MyInt::operator<=(const MyInt& i) const
{
	return (this->getValue() <= i.getValue());
}

bool MyInt::operator<=(int value) const
{
	return (this->getValue() <= value);
}

bool MyInt::operator>=(const MyInt& i) const
{
	return (this->getValue() >= i.getValue());
}

bool MyInt::operator>=(int value) const
{
	return (this->getValue() >= value);
}

bool MyInt::operator>(const MyInt& i) const
{
	return (this->getValue() > i.getValue());
}

bool MyInt::operator>(int value) const
{
	return (this->getValue() > value);
}

bool MyInt::operator<(const MyInt& i) const
{
	return (this->getValue() < i.getValue());
}

bool MyInt::operator<(int value) const
{
	return (this->getValue() < value);
}

MyInt MyInt::operator+=(const MyInt& i)
{
	*this = *this + i.getValue();
	return *this;
}

MyInt MyInt::operator+=(int value)
{
	*this = *this + value;
	return *this;
}

MyInt MyInt::operator-=(const MyInt& i)
{
	*this = *this - i.getValue();
	return *this;
}

MyInt MyInt::operator-=(int value)
{
	*this = *this - value;
	return *this;
}

MyInt MyInt::operator*=(const MyInt& i)
{
	*this = *this * i.getValue();
	return *this;
}

MyInt MyInt::operator*=(int value)
{
	*this = *this * value;
	return *this;
}

MyInt MyInt::operator/=(const MyInt& i)
{
	*this = *this / i.getValue();
	return *this;
}

MyInt MyInt::operator/=(int value)
{
	*this = *this / value;
	return *this;
}

MyInt MyInt::operator%=(const MyInt& i)
{
	*this = *this % i.getValue();
	return *this;
}

MyInt MyInt::operator%=(int value)
{
	*this = *this % value;
	return *this;
}

MyInt MyInt::operator+() const
{
	return MyInt(*this);
}

MyInt MyInt::operator-() const
{
	return MyInt(-(this->getValue()));
}

MyInt& MyInt::operator++()
{
	*this += 1;
	return *this;
}

MyInt MyInt::operator++(int)
{
	*this += 1;
	return MyInt(*this - 1);
}

MyInt& MyInt::operator--()
{
	*this -= 1;
	return *this;
}

MyInt MyInt::operator--(int)
{
	*this -= 1;
	return MyInt(*this + 1);
}

MyInt::operator int() const
{
	return this->value;
}

MyInt MyInt::operator%(const MyInt& i) const
{
	return MyInt((this->getValue() % i.getValue()));
}

MyInt MyInt::operator%(int value) const
{
	return MyInt(this->getValue() % value);
}

MyInt operator+(int value, const MyInt& i)
{
	return MyInt(i.getValue() + value);
}

MyInt operator-(int value, const MyInt& i)
{
	return MyInt(i.getValue() - value);
}

MyInt operator*(int value, const MyInt& i)
{
	return MyInt(i.getValue() * value);
}

MyInt operator/(int value, const MyInt& i)
{
	return MyInt(i.getValue() / value);
}

bool operator==(int value, const MyInt& i)
{
	return (i.getValue() == value);
}

bool operator!=(int value, const MyInt& i)
{
	return (i.getValue() != value);
}

bool operator<=(int value, const MyInt& i)
{
	return (i.getValue() <= value);
}

bool operator>=(int value, const MyInt& i)
{
	return (i.getValue() >= value);
}

bool operator>(int value, const MyInt& i)
{
	return (i.getValue() > value);
}

bool operator<(int value, const MyInt& i)
{
	return (i.getValue() < value);
}

MyInt operator+=(int value, MyInt& i)
{
	i = i + value;
	return i;
}

MyInt operator-=(int value, MyInt& i)
{
	i = i - value;
	return i;
}

MyInt operator*=(int value, MyInt& i)
{
	i = i * value;
	return i;
}

MyInt operator/=(int value, MyInt& i)
{
	i = i / value;
	return i;
}

MyInt operator%=(int value, MyInt& i)
{
	i = i % value;
	return i;
}

MyInt operator%(int value, const MyInt& i)
{
	return MyInt(i.getValue() % value);
}

ostream& operator<<(ostream& out, const MyInt& i)
{
	out << i.getValue();
	return out;
}

istream& operator>>(istream& in, MyInt& i)
{

	in >> i.value;


	return in;
}
