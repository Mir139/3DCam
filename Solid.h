#ifndef SOLID_H
#define SOLID_H

#include <vector>
#include "Face.h"

class Solid {
public:
	Solid();
	Solid(std::vector<Face> faces);
	~Solid();
	std::vector<Face> Faces() const;
	void SetFaces(std::vector<Face> faces);
	void AddFaces(std::vector<Face> faces);
	void SetColor(unsigned char * color);
	void Clear();
private:
	std::vector<Face> faces;
};

#endif
