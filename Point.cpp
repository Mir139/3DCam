#include "Point.h"
#include <cmath>

Point::Point() {
}

Point::Point(double x, double y, double z) {
	this->coords[0] = x;
	this->coords[1] = y;
	this->coords[2] = z;
}

Point::Point(double * coords) {
	if(sizeof(coords) == 3) {
		this->coords[0] = coords[0];
		this->coords[1] = coords[1];
		this->coords[2] = coords[2];
	}
}

Point::~Point() {
}

double Point::distance(Point point) const {
	double Dif[3];
	for(int i = 0 ; i < 3 ; i++) {
		Dif[i] = this->coords[i] - point.Coords(i);
	}
	return sqrt(Dif[0] * Dif[0] + Dif[1] * Dif[1] + Dif[2] * Dif[2]);
}

const double * Point::Coords() const {
	return this->coords;
}

double Point::Coords(int n) const {
	if(n >= 0 && n <= 2) {
		return this->coords[n];
	}
	else {
		return 0;
	}
}

void Point::SetCoords(double * coords) {
	if(sizeof(coords) == 3) {
		this->coords[0] = coords[0];
		this->coords[1] = coords[1];
		this->coords[2] = coords[2];
	}
}
