#ifndef POINT_H
#define POINT_H

#include <vector>
#include "repere.h"

class Point {
public:
	Point();
	Point(double x, double y, double z);
    Point(std::vector<double> coords);
	~Point();
    double Distance(Point point) const;
    const std::vector<double> Coords() const;
	double Coords(int n) const;
    void SetCoords(std::vector<double> coords);
    void SetRepere(Repere newRepere);
    Repere GetRepere() const;

private:
    std::vector<double> coords;
    Repere repere;
};

#endif
