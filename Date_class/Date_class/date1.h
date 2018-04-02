#ifndef DATE1_H
#define DATE1_H

#include <iostream>

using std::ostream;

class Date {
	friend ostream &operator<<(ostream&, const Date&);

public:
	//Constructor
	Date(int m = 1, int d = 1, int y = 1900);
	//Date setter
	void setDate(int, int, int);

	//what does this do
	Date &operator++(); //preinc

	//updates object returns copy of da OG
	Date operator++(int); //postincr

	//add specified number of days to the current date!!
	const Date &operator+=(int);

	//determines whether input year is a leap year
	bool leapYear(int) const; //is it a leapy boi

	bool endOfMonth(int) const; //is it the end?

private:
	int month;
	int day;
	int year;

	static const int days[];
	void helpIncrement();

};




#endif
