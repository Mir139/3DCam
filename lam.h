#ifndef LAM_H
#define LAM_H

#include <vector>
class LAM
{
public:
    LAM();
    static std::vector<double> ProdMatVec(std::vector<double> M, std::vector<double> v);
    static std::vector<double> Transpose(std::vector<double> M, unsigned int nc, unsigned int nl);
    static std::vector<double> Sum(std::vector<double> a, std::vector<double> b);
    static std::vector<double> Prod(double l, std::vector<double> v);
    static double ProdScal(std::vector<double> a, std::vector<double> b);
};

#endif // LAM_H
