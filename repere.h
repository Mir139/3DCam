#ifndef REPERE_H
#define REPERE_H

#include <vector>

class Repere
{
public:
    Repere();
    ~Repere();
    std::vector<double> Origin() const;
    double Origin(int n) const;
    void SetOrigin(std::vector<double> origin);
    void SetOrigin(double x, double y, double z);
    void SetMatrix(double y, double q, double j);
    std::vector<double> Matrix() const;
    std::vector<double> Matrix(int vect) const;
    const double Matrix(int i, int j) const;
    std::vector<double> Orientation() const;
    const double Orientation(int n) const;
    void SetOrientation(std::vector<double> orientation);
    void SetOrientation(double y, double q, double j);

private:
    std::vector<double> origin;
    std::vector<double> angles;
    std::vector<double> matrix;
};

#endif // REPERE_H
