#include "Solid.h"
#include <algorithm>

using namespace std;

Solid::Solid() {
}

Solid::Solid(vector<Face> faces) {
	this->faces = faces;
}

Solid::~Solid() {
}

vector<Face> Solid::Faces() const {
	return this->faces;
}

Face Solid::Faces(int n) const {
    if(n >= 0 && n < this->faces.size()) {
        return this->faces[n];
    }
    else {
        Face voidFace;
        return voidFace;
    }
}

void Solid::SetFaces(vector<Face> faces) {
	this->faces = faces;
}

void Solid::AddFaces(vector<Face> faces) {
	copy(faces.begin(), faces.end(), std::back_inserter(this->faces));
}

void Solid::SetColor(unsigned char * color) {
	//for_each f in this->faces {
	//	f.SetColor(color);
	//}
}

void Solid::Clear() {
	this->faces.clear();
}
