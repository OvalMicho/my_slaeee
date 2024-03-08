#include <chrono>
#include <fstream>
#include <random>
#include <iostream>
#include "../src/slo_oe/DenseCSR.hpp"
#include "../src/slo_oe/SIMs.hpp"

using steady_clock = std::chrono::steady_clock;

class Timer {
public:
    Timer(std::fstream& w) : start(steady_clock::now()), writer(w) {}
    ~Timer() {
        writer << std::chrono::duration_cast<std::chrono::microseconds>(steady_clock::now()- start).count()
            << std::endl;}
private:
    steady_clock::time_point start;
    std::fstream& writer;};

int main(){
    std::cout << "It will take about 3 minutes (on Ryzen 7 5800H)" << std::endl;

    std::fstream out1("res1.txt", std::ios_base::app);
    std::fstream out2("res2.txt", std::ios_base::app);
    std::fstream out3("res3.txt", std::ios_base::app);
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

        {
            Timer t(out1);
            SIMs::Jacobi(A, Vec, b, 0.01, 3, 100);}
        {
            Timer t(out2);
            SIMs::Gauss_Seidel(A, Vec, b, 0.01, 3, 100);}
        {
            Timer t(out3);
            SIMs::Simple_iter(A, Vec, b, 0.12, 0.01, 3, 100);}
    }
    out1.close();  out2.close();  out3.close();
}