#include <fstream>
#include <random>
#include <iostream>
#include "../src/slo_oe/DenseCSR.hpp"
#include "../src/slo_oe/SIMs.hpp"

int main(){
    std::cout << "It will take about 3 minutes (on Ryzen 7 5800H)" << std::endl;

    std::fstream out4("res4.txt", std::ios_base::app);
    std::fstream out5("res5.txt", std::ios_base::app);
    std::fstream out6("res6.txt", std::ios_base::app);
    std::random_device Dev;   std::mt19937 Rang(Dev());
    std::uniform_int_distribution<std::mt19937::result_type> range_1(0,10);
    std::uniform_int_distribution<std::mt19937::result_type> range_2(20000,30000);
    std::uniform_int_distribution<std::mt19937::result_type> range_3(1,10);

    for(auto c = 500u; c < 1000u; c+=10){
        auto Massive = std::vector<std::vector<double>>(c, std::vector<double>(c));
        auto Vec = std::vector<double>(c);
        auto b = std::vector<double>(c);

        for (auto i = 0u; i < c; i++){
            for(auto j = 0u; j < c; j++){
                if(i == j){
                    Massive[i][j] = static_cast<double>(range_2(Rang));}
                else{
                    Massive[i][j] = static_cast<double>(range_1(Rang));
                }
            }}

        for (auto i = 0u; i < c; i++){
            Vec[i] = static_cast<double>(range_3(Rang));
            b[i] = static_cast<double>(range_3(Rang));}
        
        auto A = DenseCSR::CSRMatx(Massive);

        auto pair = SIMs::Jacobi(A, Vec, b, 0.0001, 1, 100);            out4 << pair.second << std::endl;
        pair = SIMs::Gauss_Seidel(A, Vec, b, 0.0001, 1, 100);           out5 << pair.second << std::endl;
        pair = SIMs::Simple_iter(A, Vec, b, 0.0001, 0.0001, 1, 100);    out6 << pair.second << std::endl;
    }
    out4.close();  out5.close();  out6.close();
}