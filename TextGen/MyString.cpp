#include "MyString.h"

MyString::MyString(const char* s)
{
	*this = s;
}

MyString::MyString(char c)
{
	*this = c;
}

MyString::MyString(const MyString& obj)
{
	*this = obj;
}

MyString::~MyString()
{
}

MyString& MyString::operator=(const MyString& obj)
{
	strcpy_s(this->s, MAX_LEN + 1, obj.s);
	return *this;

}

MyString& MyString::operator=(const char* s)
{
	strcpy_s(this->s, MAX_LEN + 1, s);
	return *(this);
}

MyString& MyString::operator=(char c)
{
	*this = "";
	*this + s;
	return *(this);
}

void MyString::setS(const char* s)
{
	strcpy_s(this->s, MAX_LEN + 1, s);
}

const char* MyString::getS() const
{
	return (this->s);
}

MyString MyString::operator+(const char* s) const
{
	MyString r(*this);
	strcat_s(r.s, MAX_LEN + 1, s);
	return(r);
}

MyString MyString::operator+(char c) const
{
	MyString r(*this);
	if ((this->len() + 1) <= MAX_LEN)
	{
		{
			(r.s)[this->len()] = c;
			(r.s)[this->len() + 1] = '\0';
		}

	}
	return(r);
}

MyString MyString::operator+(const MyString& obj) const
{
	return ((*this) + obj.s);

}

bool MyString::operator==(const char* s) const
{
	return (strcmp(this->s, s) == 0);
}

bool MyString::operator==(const MyString& obj) const
{
	return (strcmp(this->s, obj.s) == 0);
}

bool MyString::operator!=(const char* s) const
{
	return (strcmp(this->s, s) != 0);
}

bool MyString::operator!=(const MyString& obj) const
{
	return (strcmp(this->s, obj.s) != 0);
}

bool MyString::operator>(const char* s) const
{
	return (strcmp(this->s, s) > 0);
}

bool MyString::operator>(const MyString& obj) const
{
	return (strcmp(this->s, obj.s) > 0);
}

bool MyString::operator<(const char* s) const
{
	return (strcmp(this->s, s) < 0);
}

bool MyString::operator<(const MyString& obj) const
{
	return (strcmp(this->s, obj.s) < 0);
}

const char& MyString::operator[](int index) const
{
	// TODO: insert return statement here
	return this->s[index];
}

char& MyString::operator[](int index)
{
	return((this->s)[index]);// TODO: insert return statement here
}

MyString MyString::trimleadingSpaces() const
{
	MyString r;
	int i;
	for (i = 0; (this->s)[i] == '\t' || (this->s)[i] == ' '; i++);
	for (; i < this->len(); i++)
		r = r + this->s[i];
	return(r);
}

MyString MyString::trimEndingSpaces() const
{
	MyString r;
	int i;
	for (i = this->len() - 1; (this->s[i] == 't' || (this->s[i] == ' ')); i--)
		for (int i = this->len(); i >= 0; i--)
			r = (this->s)[i] + r;

	return(r);

}

MyString MyString::trimAllSpaces() const
{
	MyString r;
	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] != '\t' && (this->s)[i] != ' ')
			r = r + (this->s)[i];

	return (r);

}

MyString MyString::toUppercase() const
{
	MyString r(*this);

	for (int i = 0; i < this->len(); i++) {
		if (this->s[i] >= 'a' && this->s[i] <= 'z')
			r.s[i] = this->s[i] - 32;
	}

	return r;
}

MyString MyString::toLowercase() const
{
	MyString r(*this);

	for (int i = 0; i < this->len(); i++) {
		if (this->s[i] >= 'A' && this->s[i] <= 'Z')
			r.s[i] = this->s[i] + 32;
	}

	return r;
}

MyString MyString::createSubstring(int from, int to) const
{
	MyString r;

	if (from >= 0 && to < this->len())
		for (int i = from; i <= to; i++)
			r = r + this->s[i];

	return r;
}

int MyString::len() const
{
	return (strlen(this->s));
}

bool MyString::isEmpty() const
{
	return (this->len() == 0);
}

MyString MyString::reverse() const
{
	MyString r(*this);
	char ch;
	for (int i = 0, j = this->len() - 1; i < j; i++, j--) {
		ch = r.s[i];
		r.s[i] = r.s[j];
		r.s[j] = ch;
	}


	return r;
}

int MyString::indexOf(char ch) const
{
	int index = -1;

	for (int i = 0; (i < this->len()) && index == -1; i++) {
		if (this->s[i] == ch)index = i;

	}

	return index;
}

int MyString::indexOfLast(char ch) const
{
	int index = -1;

	for (int i = this->len() - 1; (i >= 0) && index == -1; i++) {
		if (this->s[i] == ch)index = i;

	}

	return index;
}

bool MyString::include(char ch) const
{
	bool found = false;

	for (int i = 0; i < this->len() && !found; i++)
		if (this->s[i] == ch)
			found = true;

	return found;
}

int MyString::frequency(char ch) const
{
	int f = 0;

	for (int i = 0; i < this->len(); i++)
		if (this->s[i] == ch)
			++f;
	return f;
}

bool MyString::representAnUnsingInteger() const
{
	bool represent = true;

	for (int i = 0; i < this->len() && represent; i++)
		if (this->s[i] < '0' || this->s[i] > '9')
			represent = false;
	return (represent && this->len() > 0);
}

bool MyString::representAnInteger() const
{
	MyString r(*this);
	if (this->s[0] == '+' || this->s[0] == '-')
		r = this->createSubstring(1, this->len() - 1);

	return (r.representAnUnsingInteger());
}

bool MyString::representAReal() const
{
	int point = this->indexOf('.');
	MyString prefix, sufix;
	bool valid;

	if (point != -1) {
		prefix = this->createSubstring(0, point - 1);
		sufix = this->createSubstring(point + 1, this->len() - 1);
		valid = prefix.representAnInteger() && sufix.representAnUnsingInteger();

	}
	else valid = this->representAnInteger();
	return valid;
}

int MyString::MaxLen()
{
	return MAX_LEN;
}

MyString& MyString::operator+=(const MyString& obj)
{
	return (*this = *this + obj);
}

MyString& MyString::operator+=(const char* s)
{
	return *this = *this + s;
}

MyString& MyString::operator+=(char ch)
{
	// TODO: insert return statement here
	return *this = *this + ch;
}

MyString& MyString::operator++()
{
	// TODO: insert return statement here
	return *this = this->toUppercase();
}

MyString MyString::operator++(int)
{
	MyString r(*this);

	*this = this->toUppercase();

	return r;
}

MyString& MyString::operator--()
{
	return *this = this->toLowercase();
}

MyString MyString::operator--(int)
{
	MyString r(*this);

	*this = this->toLowercase();

	return r;
}

MyString operator+(const char* s, const MyString& obj)
{
	return MyString(s) + obj;
}

MyString operator+(char c, const MyString& obj)
{
	return MyString(c) + obj;
}

bool operator==(const char* s, const MyString& obj)
{
	return strcmp(s, obj.s) == 0;
}

bool operator!=(const char* s, const MyString& obj)
{
	return strcmp(s, obj.s) != 0;
}

bool operator>(const char* s, const MyString& obj)
{
	return strcmp(s, obj.s) > 0;
}

bool operator<(const char* s, const MyString& obj)
{
	return strcmp(s, obj.s) < 0;
}

ostream& operator<<(ostream& out, const MyString& obj)
{
	out << obj.s;
	return out;
}

istream& operator>>(istream& in, MyString& obj)
{
	char ch;
	obj = "";
	ch = in.get();
	while (ch == '\n')
		ch = in.get();

	while (ch != '\n') {
		obj = obj + ch;
		ch = in.get();
	}
	return in;
}
