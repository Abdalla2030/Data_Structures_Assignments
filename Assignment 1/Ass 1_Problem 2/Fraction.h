#ifndef UNTITLED6_FRACTION_H
#define UNTITLED6_FRACTION_H
#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator,denominator;
    char n;
public:
    Fraction();
    Fraction(const Fraction &obj);

    int getNumerator() const;
    int getDenominator() const;

    bool operator <= (const Fraction& obj) const;
    bool operator >= (const Fraction& obj) const;
    bool operator == (const Fraction& obj) const;
    bool operator != (const Fraction& obj) const;

    void reduce(int a,int b);

    friend istream &operator >> (istream & input , Fraction &obj);
    friend ostream &operator << (ostream & output , const Fraction &obj);

    Fraction operator + (const Fraction&  obj) const;
    Fraction operator - (const Fraction&  obj) const;
    Fraction operator * (const Fraction&  obj) const;
    Fraction operator / (const Fraction&  obj) const;
};
#endif //UNTITLED6_FRACTION_H
