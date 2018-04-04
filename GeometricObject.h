#pragma once
#include <iostream>
#include <string>

using std::string;

class GeometricObject {
public:
	GeometricObject();
	GeometricObject(const string&, bool);
	string getColor() const;
	void setColor(const string&);
	bool isFilled() const;
	void setFilled(bool);
	string toString() const;

protected:
	string color;
	bool filled;
};

class Circle : public GeometricObject {
private:
	double radius;

public:
	Circle();
	Circle(double);
	Circle(double, string&, bool);

	double getRadius() const;
	void setRadius(double);
	double getArea();
	double getPerimeter() const;
	double getDiameter() const;
	string toString() const;
};

class Rect : public GeometricObject {
private:
	double wid;
	double len;

public:
	Rect();
	Rect(double w, double l);
	Rect(double w, double l, string&, bool);

	double getWid() const;
	void setWid(double);

	double getLen() const;
	void setLen(double);

	double getArea() const;
	double getPerimeter() const;
	string toString() const;
};