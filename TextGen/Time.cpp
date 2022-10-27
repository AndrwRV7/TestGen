#include "Time.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

Time::Time()
{
	setSeconds(0);
	setMinutes(0);
	setHours(0);
}

Time::Time(const Time& obj)
{
	setSeconds(obj.getSeconds());
	setMinutes(obj.getMinutes());
	setHours(obj.getHours());
}

Time::Time(int s, int m, int h)
{
	setSeconds(s);
	setMinutes(m);
	setHours(h);
}

Time::~Time()
{

}

void Time::setSeconds(int s)
{
	this->seconds = s;

}

void Time::setMinutes(int m)
{
	this->minutes = m;
}

void Time::setHours(int h)
{
	this->hours = h;
}

void Time::setTime(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

int Time::getSeconds() const
{
	return this->seconds;
}

int Time::getMinutes() const
{
	return this->minutes;
}

int Time::getHours() const
{
	return this->hours;
}

int Time::getTime() const
{
	return (3600 * getHours()) + (60 * getMinutes()) + seconds;
}

int Time::toseconds() const
{
	return (getHours()) + ':' + (getMinutes()) + ':' + (getSeconds());
}

void Time::display()const
{
	cout << getHours() << ':' << getMinutes() << ':' << getSeconds();
}

bool Time::operator==(const Time& obj) const
{

	return(this->getTime() == obj.getTime());
}

bool Time::operator!=(const Time& obj) const
{
	return (this->getTime() != obj.getTime());
}

bool Time::operator>(const Time& obj) const
{
	return(this->getTime() > obj.getTime());
}

bool Time::operator<(const Time& obj) const
{
	return(this->getTime() < obj.getTime());
}

ostream& operator<<(ostream& out, const Time& obj)
{
	obj.display();
	return out;
	// TODO: insert return statement here
}

istream& operator>>(istream& in, Time& obj)
{
	bool pass = false;
	while (!pass) {
		cout << "Hora: ";
		cin >> obj.hours;
		cout << "Minutos: ";
		cin >> obj.minutes;
		cout << "Segundos: ";
		cin >> obj.seconds;

		if (obj.seconds < 0 || obj.minutes < 0 || obj.hours < 0 || obj.minutes > 59 || obj.hours > 12 || obj.seconds > 59)cout << "Hora invalida. Inserte denuevo.\n";
		else pass = true;

	}
	return in;
}
