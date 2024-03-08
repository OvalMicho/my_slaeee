#include "DenseCSR.hpp"

namespace DenseCSR{

    Mat_es::Mat_es(const std::vector<vector>& input): m{input.size()}, n{input[0].size()},
                                                      data{vector(input.size() * input[0].size())}{
        for(auto i = 0u; i < m; i++){
            for(auto j = 0u; j < n; j++){
                data[n * i + j] = input[i][j];}}}

    Mat_es::Mat_es(const Mat_es& input): m{input.scale().first}, n{input.scale().second},
                                         data{input.info_use()} {}

    double Mat_es::operator()(unsigned i, unsigned j) const{return data[n * i + j];}

    void Mat_es::inode(unsigned i, unsigned j, double value){   data[n * i + j] = value;
    }

    void Mat_es::pillset(unsigned start_point, vector col, unsigned num_col){

        for(auto i = 0u; i < col.size(); i++){data[n * (i + start_point) + num_col] = col[i];}}

    void Mat_es::line_set(unsigned start_point, vector row, unsigned num_row){
        for(auto i = 0; i < row.size(); i++){data[n * num_row + (i + start_point)] = row[i];
        }}

    vector Mat_es::pillare(unsigned start_point, unsigned stop_point, unsigned num_col) const{
        int size = static_cast<int>(stop_point) - static_cast<int>(start_point);

        auto out = vector(size);
        for(auto i = 0; i < size; i++){
            out[i] = data[n * (i + static_cast<int>(start_point)) + num_col];
        }return out;}

    vector Mat_es::line(unsigned start_point, unsigned stop_point, unsigned num_row) const{
        int size = static_cast<int>(stop_point) - static_cast<int>(start_point);
        auto out = vector(size);
        for(auto i = 0; i < size; i++){
            out[i] = data[n * num_row + (i + static_cast<int>(start_point))];
        }
        return out;
    }

    std::pair<vector::size_type, vector::size_type> Mat_es::scale() const{
        return std::pair<vector::size_type, vector::size_type>({m, n});
    }

    vector Mat_es::operator*(const vector &v) const{
        vector res(v.size());
        for (auto i = 0u; i < m; i++) {
            for(auto j = 0u; j < n; j++){
                res[i] += data[n * i + j] * v[j];
            }
        }
        return res;
    }

    vector Mat_es::info_use() const{
        return vector(data);
    }

    void Mat_es::redeploy(){
        for (auto i = 0u; i < m; i++){
            for(auto j = i + 1; j < n; j++){
                double temp = data[n * i + j];
                data[n * i + j] = data[n * j + i];
                data[n * j + i] = temp;
            }
        }auto temp = n; n = m; m = temp;}

    CSRMatx::CSRMatx(const std::vector<vector>& input): m{input.size()}, n{input[0].size()},
                                                              values{vector()}, cols{std::vector<unsigned>()}, rows{std::vector<unsigned>({0u})}{
        auto counter_elems = 0u;
        for(auto i = 0u; i < m; i++){
            for(auto j = 0u; j < n; j++){
                if(input[i][j] != 0){ values.push_back(input[i][j]); cols.push_back(j); counter_elems++;}
            }
            rows.push_back(counter_elems);}}

    double CSRMatx::operator()(int i, int j) const{
        for (unsigned k = rows[i]; k < rows[i + 1]; ++k) {
            if (cols[k] == j) {
                return values[k];
            }
        }
        return 0;}

    std::pair<vector::size_type, vector::size_type> CSRMatx::scale() const{
        return std::pair<vector::size_type, vector::size_type>({m, n});
    }

    vector CSRMatx::operator*(const vector& v) const {vector res(v.size());
        for (int i = 0; i < v.size(); ++i) {
            for (int k = this->rows[i]; k < this->rows[i + 1]; ++k) {
                res[i] += this->values[k] * v[this->cols[k]];
            }}return res;}

    vector CSRMatx::backer(const vector& v) const{auto res = vector(v.size());
        for (auto i = 0u; i < v.size(); i++){res[i] = 1.0 / this->operator()(i, i) * v[i];}
        return res;}

    vector CSRMatx::changer(const vector& v) const{vector res(v.size());

        for (auto i = 0u; i < v.size(); ++i) {
            for (auto k = rows[i]; k < rows[i + 1]; ++k) {
                if(i != cols[k]){res[i] += values[k] * v[cols[k]];}}
        }return res;}

    vector CSRMatx::Gauss(const vector& v, const vector& b) const{auto res = vector(v);

        for(auto i = 0u; i < n; i++){res[i] = b[i];
            auto divider = 0.0;for (auto k = rows[i]; k < rows[i + 1]; ++k) {
                if(cols[k] != i){
                    res[i] -= values[k] * res[cols[k]];}
                else{
                    divider = values[k];}
            }res[i] /= divider;}
        return res;}



    double use_l(const vector& v){double out = 0;

        for (auto i = 0u; i < v.size(); i++){out += (v[i] * v[i]);
        }
        return std::sqrt(out);}


    void bring_out(const vector& input){

        for (auto i = 0u; i < input.size(); i++){std::cout << input[i] << " ";
        }std::cout << std::endl;}

    vector operator*(double rhs, const vector& lhs){
        vector out = vector(lhs.size());
        for (auto i = 0u; i < lhs.size(); i++){
            out[i] = rhs * lhs[i];
        }
        return out;
    }

    vector operator+(const vector& lhs, const vector& rhs){auto res = vector(lhs.size());
        for (auto i = 0u; i < lhs.size(); i++){res[i] = lhs[i] + rhs[i];}

        return res;}

    vector operator-(const vector& lhs, const vector& rhs){auto res = vector(lhs.size());
        for (auto i = 0u; i < lhs.size(); i++){res[i] = lhs[i] - rhs[i];}
        return res;}

    double operator*(const vector& lhs, const vector& rhs){double res = 0;
        for (auto i = 0u; i < lhs.size(); i++){res += lhs[i] * rhs[i];}
        return res;}
}