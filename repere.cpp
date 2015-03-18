#include "repere.h"
#include <cmath>

Repere::Repere() {
    this->origin.resize(3);
    this->angles.resize(3);
    this->matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
}

Repere::~Repere() {
}

void Repere::SetMatrix(double y, double q, double j) {
    angles[0] = y;
    angles[1] = q;
    angles[2] = j;

    matrix[0] = cos(j) * cos(y) - sin(j) * cos(q) * sin(y);
    matrix[1] = sin(q) * sin(y);
    matrix[2] = -sin(j) * cos(y) - cos(j) * cos(q) * sin(y);
    matrix[3] = sin(j) * sin(q);
    matrix[4] = cos(q);
    matrix[5] = cos(j) * sin(q);
    matrix[6] = cos(j) * sin(y) + sin(j) * cos(q) * cos(y);
    matrix[7] = -sin(q) * cos(y);
    matrix[8] = -sin(j) * sin(y) + cos(j) * cos(q) * cos(y);
}

std::vector<double> Repere::Matrix(int vect) const {
    if(vect >= 0 && vect < 3) {
        std::vector<double> returnVect = {this->matrix[3 * vect], this->matrix[3 * vect + 1], this->matrix[3 * vect + 2]};
        return returnVect;
    }
}

const double Repere::Matrix(int i, int j) const {
    if(i >= 0 && i < 3 && j >= 0 && j < 3) {
        return this->matrix[i * 3 + j];
    }
    else {
        return 0;
    }
}

std::vector<double> Repere::Orientation() const {
    return this->angles;
}

const double Repere::Orientation(int n) const {
    if(n >= 0 && n < 3) {
        return this->angles[n];
    }
    else {
        return 0;
    }
}

void Repere::SetOrientation(std::vector<double> orientation) {
    if(orientation.size() == 3) {
        this->SetMatrix(orientation[0] * M_PI / 180, orientation[1] * M_PI / 180, orientation[2] * M_PI / 180);
    }
}

void Repere::SetOrientation(double y, double q, double j) {
    this->SetMatrix(y * M_PI / 180, q * M_PI / 180, j * M_PI / 180);
}
