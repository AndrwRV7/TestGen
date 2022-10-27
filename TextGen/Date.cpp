#include "Date.h"
#include<iostream>
using namespace::std;

const int Date::days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Date::Date() {
    month = 0;
    day = 0;
    year = 0;
}
Date::Date(int aMonth, int aDay, int aYear) {
    setMonth(aMonth);
    setDay(aDay);
    setYear(aYear);
}
//Copy Constructor
Date::Date(const Date& aDate) {
    setMonth(aDate.getMonth());
    setDay(aDate.getDay());
    setYear(aDate.getYear());
}
Date::~Date() {
}
//Mutators
void Date::setMonth(int aMonth) {
    month = aMonth;
}
void Date::setDay(int aDay) {
    day = aDay;
}
void Date::setYear(int aYear) {
    this->year = aYear;
}
//Accessor
int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}
int Date::getYear() const {
    return year;
}
void Date::displayDate() const {
    cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}
// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay)
{
    if (getMonth() == 2 && leapYear(getYear()))
        return testDay == 29; // last day of Feb. in leap year
    else
        return testDay == days[month];
} // end function endOfMonth
bool Date::leapYear(int testYear)
{
    if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
        return true; // a leap year
    else
        return false; // not a leap year
} // end function leapYear
// function to help increment the date
void Date::helpIncrement()
{
    // day is not end of month
    if (!endOfMonth(day))
        ++day; // increment day
    else
        if (month < 12) // day is end of month and month < 12
        {
            ++month; // increment month
            day = 1; // first day of new month
        } // end if
        else // last day of year
        {
            ++year; // increment year
            month = 1; // first month of new year
            day = 1; // first day of new month
        } // end else
} // end function helpIncrement
Date& Date::operator++()
{
    helpIncrement(); // increment date
    return *this; // reference return to create an lvalue
} // end function operator++
// overloaded postfix increment operator; note that the
// dummy integer parameter does not have a parameter name
Date Date::operator++(int)
{
    Date temp = *this; // hold current state of object
    helpIncrement();
    // return unincremented, saved, temporary object
    return temp; // value return; not a reference return
} // end function operator++
bool Date::operator==(const Date& obj) {
    if (getMonth() == obj.getMonth() && getDay() == obj.getDay() && getYear() ==
        obj.getYear())
        return true;
    else
        return false;
}
ostream& operator << (ostream& strm, const Date& obj)
{
    
    /*strm << "Mes: " << obj.getMonth() << endl;
    strm << "D�a: " << obj.getDay() << endl;
    strm << "A�o: " << obj.getYear() << endl;*/
    
    strm << obj.getMonth()<<"/"<<obj.getDay()<<"/"<<obj.getYear()<<endl;
    return strm;
}
istream& operator >> (istream& strm, Date& obj)
{
    bool pass = false;
    while (!pass) {
        cout << "Month: ";
        strm >> obj.month;
        cout << "Day: ";
        strm >> obj.day;
        cout << "Year: ";
        strm >> obj.year;
        if (obj.month > 12 || obj.day > 31 || obj.day <= 0 || obj.month <= 0) cout << "Error, fecha invalida. Entre fecha denuevo.\n";
        else pass = true;
    }
    
    return strm;
}
