#include <iostream>
#include <vector>
using namespace std;

vector<double> FuncThreeD(int N, vector<vector<double>>& matA, vector<double>& matD)
{
    int N1 = N-1;
    matA.resize(N, vector<double>(N));
    double y;
    vector<double> a(N), B(N), matRes(N);

    y = matA[0][0];
    a[0] = -matA[0][1] / y;
    B[0] = matD[0] / y  ;

    for (int i = 1; i < N1; i++) { //Коэфициенты - прямой ход
        y = matA[i][i] + matA[i][i - 1] * a[i - 1];
        a[i] = -matA[i][i + 1] / y;
        B[i] = (matD[i] - matA[i][i - 1] * B[i - 1]) / y;
    }

    matRes[N1] = (matD[N1] - matA[N1][N1 - 1] * B[N1 - 1]) / (matA[N1][N1] + matA[N1][N1 - 1] * a[N1 - 1]);
    for (int i = N1 - 1; i >= 0; i--) { //корни - обратный ход
        matRes[i] = a[i] * matRes[i + 1] + B[i];
    }

    return matRes;
}
