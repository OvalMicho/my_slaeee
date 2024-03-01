#include "Househo_older.hpp"

namespace Ho_ouseholder{

    vector changer(const vector& v, const vector& x){


        auto f = (-2.0) * DenseCSR::operator*(x, v) / DenseCSR::operator*(v, v);

        auto out = vector(x);
        auto out1 = DenseCSR::operator*(f, v);


        return DenseCSR::operator+(out, out1);
    }

    std::pair<DenseCSR::Matrix, DenseCSR::Matrix> qr(const DenseCSR::Matrix& A_input){

        auto A = DenseCSR::Matrix(A_input);
        vector::size_type m = A.get_size().first;
        vector::size_type n = A.get_size().second;

        auto wP = std::vector<vector>(m, vector(m));

        for (auto i = 0u; i < m; i++){wP[i][i] = 1.0;}
        auto P = DenseCSR::Matrix(wP);

        auto v_mas = std::vector<vector>(n);

        for (auto i = 0u; i + 1 < n; i++){
            vector x = A.get_col(i, m, i);
            v_mas[i] = vector(x);
            if (x[0] >= 0.0){v_mas[i][0] += DenseCSR::get_length(x);}

            else{v_mas[i][0] -= DenseCSR::get_length(x);}

            for (auto j = i; j < n; j++){
                vector col_j = A.get_col(i, m, j);
                A.set_col(i, changer(v_mas[i], col_j), j);}
            for (auto j = 0u; j < m; j++){
                vector row_j = P.get_row(i, m, j);
                P.set_row(i, changer(v_mas[i], row_j), j);}

        }


        return std::pair<DenseCSR::Matrix, DenseCSR::Matrix>(P, A);
    }

    vector so_olve(const vector& b, const DenseCSR::Matrix& A){

        auto pair = qr(A);

        auto q = pair.first;
        auto r = pair.second;

        vector::size_type m = r.get_size().first;
        vector::size_type n = r.get_size().second;

        q.transpose();
        auto answer = q * b;

        for (int i = static_cast<int>(b.size()) - 1; i >= 0; i--){ auto row = r.get_row(0, n, i);

            answer[i] *= (1 / row[i]);

            row = DenseCSR::operator*((1 / row[i]), row);
            r.set_row(0, row, i);
            for (int j = static_cast<int>(b.size()) - 1; j > i; j--){answer[i] -= answer[j] * (r(i, j));}

        }


        return answer;
    }

}