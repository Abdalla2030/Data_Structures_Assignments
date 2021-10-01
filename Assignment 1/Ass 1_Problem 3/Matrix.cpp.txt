//
// Created by Ahmed Essam Eldin 20190050 on 5/7/2021.
//
#include "Matrix.h"
#include <iostream>
using namespace std;

template<class Generic>
Matrix<Generic>::Matrix(int row , int column): row(row) , column(column)
{
    Matrix<Generic>::ptr=new Generic*[row];
    for(int i=0; i<row; i++)
    {
        Matrix<Generic>::ptr[i]=new Generic[column];
    }

}
template<class Generic>
Matrix<Generic>::~Matrix()
{
    delete [] ptr;
}

template<class Generic>
ostream& operator<<(ostream& os , const Matrix<Generic>& matrix)
{
    for(int i=0; i<matrix.row ; i++) {
        for (int j = 0; j < matrix.column; j++)
        {
            os << matrix.ptr[i][j] << " ";
        }
        os<<endl;
    }
    return os;
}
template<class Generic>
istream& operator>>(istream& is ,  Matrix<Generic>& matrix)
{
    for(int i=0; i<matrix.row ; i++)
    {
        for(int j=0 ; j<matrix.column ; j++)
        {
            cout<<"Enter element ["<<i<<"] ["<<j<<"] of matrix: ";
            is>>matrix.ptr[i][j];
            cout<<endl;
        }
    }
    return is;
}

template<class Generic>
Matrix<Generic> Matrix<Generic>::operator+(Matrix<Generic>& m1 )
{
    Matrix<Generic> m3(m1.row , m1.column);
    for(int i=0; i<m3.row ; i++)
    {
        for(int j=0 ; j<m3.column ; j++)
        {
            m3.ptr[i][j]=ptr[i][j]+m1.ptr[i][j];
        }
    }
    return m3;
}

template<class Generic>
Matrix<Generic> Matrix<Generic>::operator-(Matrix<Generic>& m1)
{
    Matrix<Generic> m3(m1.row , m1.column);
    for(int i=0; i<m3.row ; i++)
    {
        for(int j=0 ; j<m3.column ; j++)
        {
            m3.ptr[i][j]=ptr[i][j]-m1.ptr[i][j];
        }
    }
    return m3;
}
template<class Generic>
Matrix<Generic> Matrix<Generic>::operator*(Matrix<Generic>& m1 )
{
    Matrix<Generic> m3(row , m1.column);
    if(column==m1.row){
        for(int i=0; i<m3.row ; i++)
        {
            for(int j=0 ; j<m3.column ; j++)
            {
                for(int k=0; k<column ; k++) {
                    m3.ptr[i][j] +=ptr[i][k] * m1.ptr[k][i];
                }
            }

        }
        return m3;
    }
    else
    {
        cout<<"can't resolve this operation"<<endl;
        return m3;
    }
}


template<class Generic>
Matrix<Generic> Matrix<Generic>::getTranspose(const Matrix<Generic> &matrix)
{
    Matrix<Generic> m2(matrix.column , matrix.row);
    for(int i=0; i<m2.row ; i++)
    {
        for(int j=0 ; j<m2.column ; j++)
        {
            m2.ptr[i][j]=matrix.ptr[j][i];
        }
    }
    return m2;
}
