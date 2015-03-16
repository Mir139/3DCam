#ifndef FACE_H
#define FACE_H

#include "Point.h"
#include <vector>

class Face {
public:
	Face();
	Face(std::vector<Point> points);
	~Face();
	std::vector<Point> Points() const;
	void SetPoints(std::vector<Point> points);
	void AddPoints(std::vector<Point> points);
	unsigned char * Color();
	void SetColor(unsigned char * color);
	void Clear();

private:
	std::vector<Point> points;
	unsigned char color[3];
};

#endif
