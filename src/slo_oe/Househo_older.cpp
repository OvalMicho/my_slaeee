#include "Househo_older.hpp"

namespace Ho_ouseholder{

    vector changer(const vector& v, const vector& x){


        auto f = (-2.0) * DenseCSR::operator*(x, v) / DenseCSR::operator*(v, v);

        auto out = vector(x);
        auto out1 = DenseCSR::operator*(f, v);


        return DenseCSR::operator+(out, out1);
    }

    std::pair<DenseCSR::Mat_es, DenseCSR::Mat_es> qr(const DenseCSR::Mat_es& A_input){

        auto A = DenseCSR::Mat_es(A_input);
        vector::size_type m = A.scale().first;
        vector::size_type n = A.scale().second;

        auto wP = std::vector<vector>(m, vector(m));

        for (auto i = 0u; i < m; i++){wP[i][i] = 1.0;}
        auto P = DenseCSR::Mat_es(wP);

        auto v_mas = std::vector<vector>(n);

        for (auto i = 0u; i + 1 < n; i++){
            vector x = A.pillare(i, m, i);
            v_mas[i] = vector(x);
            if (x[0] >= 0.0){v_mas[i][0] += DenseCSR::use_l(x);}

            else{v_mas[i][0] -= DenseCSR::use_l(x);}

            for (auto j = i; j < n; j++){
                vector col_j = A.pillare(i, m, j);
                A.pillset(i, changer(v_mas[i], col_j), j);}
            for (auto j = 0u; j < m; j++){
                vector row_j = P.line(i, m, j);
                P.line_set(i, changer(v_mas[i], row_j), j);}

        }


        return std::pair<DenseCSR::Mat_es, DenseCSR::Mat_es>(P, A);
    }

    vector so_olve(const vector& b, const DenseCSR::Mat_es& A){

        auto pair = qr(A);

        auto q = pair.first;
        auto r = pair.second;

        vector::size_type m = r.scale().first;
        vector::size_type n = r.scale().second;

        q.redeploy();
        auto answer = q * b;

        for (int i = static_cast<int>(b.size()) - 1; i >= 0; i--){ auto row = r.line(0, n, i);

            answer[i] *= (1 / row[i]);

            row = DenseCSR::operator*((1 / row[i]), row);
            r.line_set(0, row, i);
            for (int j = static_cast<int>(b.size()) - 1; j > i; j--){answer[i] -= answer[j] * (r(i, j));}

        }


        return answer;
    }

}