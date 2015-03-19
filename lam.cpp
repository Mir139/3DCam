#include "lam.h"
#include "assert.h"

LAM::LAM()
{
}

std::vector<double> LAM::ProdMatVec(std::vector<double> M, std::vector<double> v){
    assert(M.size() % v.size() == 0 && "Matrix und Vektor haben unterschiedliche Dimensionen in ProdMatVect");
    std::vector<double> vr(M.size() / v.size());
    for(int i = 0 ; i < vr.size() ; i++) {
        for(int j = 0 ; j < v.size() ; j++) {
            vr[i] += M[i * v.size() + j] * v[j];
        }
    }
    return vr;
}


std::vector<double> LAM::Transpose(std::vector<double> M, unsigned int nc, unsigned int nl) {
    assert(M.size() == nc * nl && "Ungenaue Argumente in Transpose");
    std::vector<double> Mr(M.size());
    for(int i = 0 ; i < nc ; i++) {
        for(int j = 0 ; j < nl ; j++) {
            Mr[j * nl + i] = M[i * nc + j];
        }
    }
    return Mr;
}

std::vector<double> LAM::Sum(std::vector<double> a, std::vector<double> b) {
    assert(a.size() == b.size() && "Vektoren haben unterschiedliche Dimensionen in Difference");
    std::vector<double> vr(a.size());
    for(int i = 0 ; i < a.size() ; i++) {
        vr[i] = a[i] + b[i];
    }
    return vr;
}

std::vector<double> LAM::Prod(double l, std::vector<double> v) {
    std::vector<double> vr(v.size());
    for(int i = 0 ; i < v.size() ; i++) {
        vr[i] = l * v[i];
    }
    return vr;
}

double LAM::ProdScal(std::vector<double> a, std::vector<double> b) {
    assert(a.size() == b.size() && "Vektoren haben unterschiedliche Dimensionen in ProdScal");
    double p;
    for(int i = 0 ; i < a.size() ; i++) {
        p += a[i] * b[i];
    }
    return p;
}
