#pragma once
#include <vector>
#include <iostream>
#include <cmath>

namespace DenseCSR{ using vector = std::vector<double>;

    class Mat_es{
    public:
        Mat_es(const std::vector<vector>& input);
        Mat_es(const Mat_es& input);

        void inode(unsigned i, unsigned j, double value);

        double operator()(unsigned i, unsigned j) const;
        void line_set(unsigned start_point, vector row, unsigned num_row);
        void pillset(unsigned start_point, vector col, unsigned num_col);
        vector pillare(unsigned start_point, unsigned stop_point, unsigned num_col) const;

        std::pair<vector::size_type, vector::size_type> scale() const;
        vector line(unsigned start_point, unsigned stop_point, unsigned num_row) const;


        vector operator*(const vector &v) const;
        void redeploy();
        vector info_use() const;
    private:
        vector data;
        vector::size_type m;
        vector::size_type n;};

    class CSRMatx{
    public:
        CSRMatx(const std::vector<vector>& input);
        double operator()(int i, int j) const; std::pair<vector::size_type, vector::size_type> scale() const;


        vector backer(const vector& v) const;
        vector operator*(const vector& v) const;


        vector Gauss(const vector& v, const vector& b) const;
        vector changer(const vector& v) const;
    private:
        vector values;
        std::vector<unsigned> cols;
        std::vector<unsigned> rows;
        vector::size_type m;
        vector::size_type n;};

    template <typename T>
    void bring_out_Mat(T Mat_es){ std::pair<unsigned, unsigned> size_Mat_es = Mat_es.scale();
        for(auto i = 0u; i < size_Mat_es.first; i++){
            for(auto j = 0u; j < size_Mat_es.second; j++){
                std::cout << Mat_es(i, j) << " ";} std::cout << std::endl;}}
    
    vector operator+(const vector& lhs, const vector& rhs);
    vector operator-(const vector& lhs, const vector& rhs);

    double operator*(const vector& lhs, const vector& rhs);
    vector operator*(double rhs, const vector& lhs);

    double use_l(const vector& v);
    void bring_out(const vector& input);
}