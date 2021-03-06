//
// Created by Ahmed Essam Eldin 20190050 on 5/8/2021.
//

#include "MatrixCalculator.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

MatrixCalculator::MatrixCalculator()
{
    cout<<"Welcome to (Ahmed Essam) Matrix Calculator"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1- Perform Matrix Addition\n"
          "2- Perform Matrix Subtraction\n"
          "3- Perform Matrix Multiplication\n"
          "4- Matrix Transpose"<<endl;
}
Matrix<int>  MatrixCalculator::matrixAddition(Matrix<int>& m1 , Matrix<int>& m2)
{
    Matrix<int> m3(m1.row , m1.column);
    m3=m1+m2;
    return m3;
}

Matrix<int>  MatrixCalculator::matrixSubtraction(Matrix<int>& m1 , Matrix<int>& m2)
{
    Matrix<int> m3(m1.row , m1.column);
    m3=m1-m2;
    return m3;
}

Matrix<int>  MatrixCalculator::matrixMultiplication(Matrix<int>& m1 , Matrix<int>& m2)
{
    Matrix<int> m3(m1.row , m2.column);
    m3=m1*m2;
    return m3;
}

Matrix<int>  MatrixCalculator::matrixTranspose(Matrix<int> m1)
{
    Matrix<int> m3(m1.column , m1.row);
    m3=m1.getTranspose(m1);
    return m3;
}
