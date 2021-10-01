//
// Created by Ahmed Essam Eldin 20190050 on 5/8/2021.
//
#include "Matrix.h"
#include "Matrix.cpp"
#include <iostream>
using namespace std;

#ifndef ASSIGNMENT_1_MATRIXCALCULATOR_H
#define ASSIGNMENT_1_MATRIXCALCULATOR_H


class MatrixCalculator {
public:
    MatrixCalculator();
    Matrix<int> matrixAddition(Matrix<int>& m1 , Matrix<int>& m2);
    Matrix<int> matrixSubtraction(Matrix<int>& m1 , Matrix<int>& m2);
    Matrix<int> matrixMultiplication(Matrix<int>& m1 , Matrix<int>& m2);
    Matrix<int> matrixTranspose(Matrix<int> m1);
};


#endif //ASSIGNMENT_1_MATRIXCALCULATOR_H
