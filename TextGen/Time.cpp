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
	cout << "The time chosen time is: \n" << getHours() << ':' << getMinutes() << ':' << getSeconds() << endl;
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