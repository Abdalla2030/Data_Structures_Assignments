//
// Created by Ahmed Essam Eldin 20190050 on 5/7/2021.
//
#include <iostream>
using namespace std;

#ifndef ASSIGNMENT_1_MATRIX_H
#define ASSIGNMENT_1_MATRIX_H

template <class Generic>
class Matrix{
public:
    Generic** ptr;
    int row , column;  // hold the size of matrix
public:

    Matrix(int row, int column);
    ~Matrix();

    template <class Gener>
    friend ostream& operator << (ostream& os ,const Matrix<Gener> &matrix);
    template <class Gener>
    friend istream& operator >> (istream& is ,  Matrix<Gener>& matrix);
    Matrix<Generic>  operator+(Matrix<Generic>& m1 );
    Matrix<Generic>  operator-(Matrix<Generic>& m1 );
    Matrix<Generic>  operator*(Matrix<Generic>& m1 );
    Matrix<Generic> getTranspose(const Matrix<Generic>& matrix);

};
#endif //ASSIGNMENT_1_MATRIX_H
