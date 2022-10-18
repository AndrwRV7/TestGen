#pragma once
#include<iostream>
#include<string>
using namespace std;

const int MAX_LEN = 80;

class MyString

{
private:
	char s[MAX_LEN + 1];
public:
	MyString(const char* s = "");
	MyString(char c);
	MyString(const MyString& obj);
	~MyString();

	MyString& operator= (const MyString& obj);
	MyString& operator= (const char* s);
	MyString& operator= (char c);

	void setS(const char* s);
	const char* getS()const;

	MyString operator+(const char* s)const;
	MyString operator+(char c)const;
	MyString operator+(const MyString& obj)const;
	friend MyString operator+(const char* s, const MyString& obj);
	friend MyString operator+(char c, const MyString& obj);

	bool operator== (const char* s)const;
	bool operator== (const MyString& obj)const;
	friend bool operator==(const char* s, const MyString& obj);

	bool operator!= (const char* s)const;
	bool operator!= (const MyString& obj)const;
	friend bool operator!=(const char* s, const MyString& obj);

	bool operator> (const char* s)const;
	bool operator> (const MyString& obj)const;
	friend bool operator>(const char* s, const MyString& obj);

	bool operator< (const char* s)const;
	bool operator< (const MyString& obj)const;
	friend bool operator<(const char* s, const MyString& obj);

	const char& operator[](int index)const;
	char& operator[](int index);

	friend ostream& operator<<(ostream& out, const MyString& obj);
	friend istream& operator>>(istream& in, MyString& obj);

	MyString trimleadingSpaces()const;
	MyString trimEndingSpaces()const;
	MyString trimAllSpaces()const;

	MyString toUppercase()const;
	MyString toLowercase()const;

	MyString createSubstring(int from, int to)const;

	int len()const;
	bool isEmpty()const;

	MyString reverse()const;

	int indexOf(char ch)const;
	int indexOfLast(char ch)const;
	bool include(char ch)const;
	int frequency(char ch)const;

	bool representAnUnsingInteger()const;
	bool representAnInteger()const;
	bool representAReal()const;

	static int MaxLen();

	MyString& operator+=(const MyString& obj);
	MyString& operator+=(const char* s);
	MyString& operator+=(char ch);

	MyString& operator++();
	MyString operator++(int);

	MyString& operator--();
	MyString operator--(int);
};

