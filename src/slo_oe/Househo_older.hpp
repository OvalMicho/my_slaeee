#include "DenseCSR.hpp"
#include <vector>


namespace Ho_ouseholder{

    using vector = std::vector<double>;

    std::pair<DenseCSR::Mat_es, DenseCSR::Mat_es> qr(const DenseCSR::Mat_es& A);

    vector changer(const vector& v, const vector& x);


    vector so_olve(const vector& b, const DenseCSR::Mat_es& A);
}
