#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
class Time
{
private:
	int seconds;
	int minutes;
	int hours;
public:
	Time();
	Time(const Time& obj);
	Time(int, int, int);
	~Time();
	void setSeconds(int);
	void setMinutes(int);
	void setHours(int);
	void setTime(int, int, int);
	int getSeconds()const;
	int getMinutes()const;
	int getHours()const;
	int getTime()const;
	int toseconds()const;
	void display()const;
	bool operator==(const Time& obj)const;
	bool operator!=(const Time& obj)const;
	bool operator>(const Time& obj)const;
	bool operator<(const Time& obj)const;
	friend ostream& operator<< (ostream&, const Time&);
	friend istream& operator>> (istream&, Time&);

};