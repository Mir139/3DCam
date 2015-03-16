#include "Face.h"

using namespace std;

Face::Face() {
}

Face::Face(vector<Point> points) {
	if(points.size() == 3) {
		this->points = points;
	}
}

Face::~Face() {
}

vector<Point> Face::Points() const {
	return this->points;
}

void Face::SetPoints(vector<Point> points) {
	if(points.size() == 3) {
		this->points = points;
	}
}

void Face::AddPoints(vector<Point> points) {
	if(points.size() + this->points.size() <= 3) {
		copy(points.begin(), points.end(), std::back_inserter(this->points));
	}
}

unsigned char * Face::Color() {
	return this->color;
}

void Face::SetColor(unsigned char * color) {
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}

void Face::Clear() {
	this->points.clear();
}
