#include "Point.h"
#include <cmath>

Point::Point() {
}

Point::Point(double x, double y, double z) {
    this->coords = {x, y, z};
}

Point::Point(std::vector<double> coords) {
    if(coords.size() == 3) {
        this->coords = coords;
	}
}

Point::~Point() {
}

double Point::Distance(Point point) const {
	double Dif[3];
	for(int i = 0 ; i < 3 ; i++) {
		Dif[i] = this->coords[i] - point.Coords(i);
	}
	return sqrt(Dif[0] * Dif[0] + Dif[1] * Dif[1] + Dif[2] * Dif[2]);
}

const std::vector<double> Point::Coords() const {
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

void Point::SetCoords(std::vector<double> coords) {
    if(coords.size() == 3) {
        this->coords = coords;
	}
}
