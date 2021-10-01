//
// Created by Ahmed Essam Eldin 20190050 on 5/14/2021.
//
#include <iostream>
#include "MatrixCalculator.h"
#include <string>

using namespace std;

int main() {
    MatrixCalculator calc;
    int choice;
    cin>>choice;
    int row , col;
    cin>>row>>col;
    Matrix<int> m1(row,col);
    cin>>m1;
    cin>>row>>col;
    Matrix<int> m2(row,col);
    if (choice) cin>>m2;
    if (choice==1)
    {
        cout<<calc.matrixAddition(m1,m2);
    }
    if (choice==2)
    {
        cout<<calc.matrixSubtraction(m1,m2);
    }
    if (choice==3)
    {
        cout<<calc.matrixMultiplication(m1,m2);
    }
    if (choice==4)
    {
        cout<<calc.matrixTranspose(m1);
    }

    return 0;
}
