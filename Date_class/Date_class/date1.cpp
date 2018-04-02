#include <iostream>
#include "date1.h"

const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int m, int d, int y) {
	setDate(m, d, y);
}

void Date::setDate(int mm, int dd, int yy) {
	month = (mm >= 1 && mm <= 12) ? mm : 1;
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else 
		day = (dd >= 1 && dd <= 28) ? dd : 1;
}

Date &Date::operator++() {
	helpIncrement();
	return *this;
}

Date Date::operator++(int) {
	Date temp = *this;
	helpIncrement();

	return temp;
}

const Date &Date::operator+=(int addDays) {
	for (int i = 0; i < addDays; i++) {
		helpIncrement();
	}

	return *this;
}

bool Date::leapYear(int testYear) const {
	if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
		return true; // it a leapy boi
	else
		return false;

}