#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point();
	Point(double x, double y, double z);
	Point(double * coords);
	~Point();
	double distance(Point point) const;
	const double * Coords() const;
	double Coords(int n) const;
	void SetCoords(double * coords);

private:
	double coords[3];
};

#endif
