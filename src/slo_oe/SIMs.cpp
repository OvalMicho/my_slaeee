#include "SIMs.hpp"

namespace SIMs{
    using DenseCSR::operator+;  using DenseCSR::operator*;  using DenseCSR::operator-;


    std::pair<vector, unsigned> Simple_iter(const DenseCSR::CSRMatx& A, const vector& Xo, const vector& b,
                                            double Tau,
                                            double deviation=5.0,
                                            unsigned viewing_interval=5u,
                                            unsigned Maximum=100u)
    {
        auto result = vector(Xo);
        for (auto i = 0u; i < Maximum;
             i+=viewing_interval)
        {
            if(DenseCSR ::use_l(A * result - b) <
               deviation)
            {
                return std :: pair<vector,unsigned>
                        (result,i);
            }
            else
            {
                for(auto j = 0u;
                    j<viewing_interval;j++)
                {
                    result=result-Tau*(A*result-b);
                }
            }
        }
        return std :: pair<vector,unsigned>
                (result,Maximum);
    }


    std::pair<vector, unsigned> Jacobi(const DenseCSR::CSRMatx& A, const vector& Xo, const vector& b,
                                            double deviation=5.0,
                                            unsigned viewing_interval=5u,
                                            unsigned Maximum=100u)
                                            {
        auto result = vector(Xo);
        for (auto i = 0u; i < Maximum; i+=viewing_interval){
            if(DenseCSR::use_l(A * result - b) < deviation){
                return std::pair<vector, unsigned>(result, i);
            }
            else{
                for(auto j = 0u; j < viewing_interval; j++){
                    result = A.backer(b - A.changer(result));
                }
            }
        }
        return std::pair<vector, unsigned>(result, Maximum);
    }

    std::pair<vector, unsigned> Gauss_Seidel(const DenseCSR::CSRMatx& A, const vector& Xo, const vector& b,
                                                  double deviation=5.0,
                                                  unsigned viewing_interval=5u,
                                                  unsigned Maximum=100u){
        auto result = vector(Xo);
        for (auto i = 0u; i < Maximum; i+=viewing_interval){
            if(DenseCSR::use_l(A * result - b) < deviation){
                return std::pair<vector, unsigned>(result, i);
            }
            else{
                for(auto j = 0u; j < viewing_interval; j++){
                    result = A.Gauss(result, b);
                }
            }
        }
        return std::pair<vector, unsigned>(result, Maximum);
    }


}