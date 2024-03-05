#include "DenseCSR.hpp"
#include <vector>


namespace Ho_ouseholder{

    using vector = std::vector<double>;

    std::pair<DenseCSR::Matrix, DenseCSR::Matrix> qr(const DenseCSR::Matrix& A);

    vector changer(const vector& v, const vector& x);


    vector so_olve(const vector& b, const DenseCSR::Matrix& A);
}
