#include "DenseCSR.hpp"

namespace SIMs{
    using vector = std::vector<double>;

    std::pair<vector, unsigned> Simple_iter(const DenseCSR::CSRMatx& A, const vector& Xo, const vector& b,
                                            double Tau,
                                            double deviation,
                                            unsigned viewing_interval,
                                            unsigned Maximum);

    std::pair<vector, unsigned> Jacobi(const DenseCSR::CSRMatx& A, const vector& Xo, const vector& b,
                                            double deviation,
                                            unsigned viewing_interval,
                                            unsigned Maximum);

    std::pair<vector, unsigned> Gauss_Seidel(const DenseCSR::CSRMatx& A, const vector& Xo, const vector& b,
                                                  double deviation,
                                                  unsigned viewing_interval,
                                                  unsigned Maximum);


}