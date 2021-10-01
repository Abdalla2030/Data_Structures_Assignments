#include "Fraction.h"

Fraction::Fraction() {
    numerator=0;
    denominator=0;
    n=' ';
}
Fraction::Fraction(const Fraction &obj) {
    numerator=obj.numerator;
    denominator=obj.denominator;
    n=obj.n;
}
/*------------------------------------------------------------*/
int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}
/*------------------------------------------------------------*/
bool Fraction::operator<=(const Fraction& obj) const {
    if ((double) numerator/denominator <= (double) obj.numerator/obj.denominator)
        return true;
    return false;
}
bool Fraction::operator>=(const Fraction& obj) const {
    if ((double) numerator/denominator >= (double) obj.numerator/obj.denominator)
        return true;
    return false;
}
bool Fraction::operator==(const Fraction& obj) const {
    if (numerator==obj.numerator && denominator==obj.denominator)
        return true;
    return false;
}
bool Fraction::operator!=(const Fraction& obj) const {
    if (numerator==obj.numerator && denominator==obj.denominator)
        return false;
    return true;
}
/*------------------------------------------------------------*/
void Fraction::reduce(int a,int b) { // 100/1100  50/550     10/110
    for(int i=1;i<=5;i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            numerator=a/i;
            denominator=b/i;
        }
    }
    if (b % a == 0){ // 10/110     1/11
        numerator= 1;
        denominator= b/a;
    }
}
/*------------------------------------------------------------*/
istream &operator>>(istream &input, Fraction &obj) {
    cin>>obj.numerator;
    cin>>obj.n;
    cin>>obj.denominator;
    obj.reduce(obj.numerator,obj.denominator);
    return input;
}
ostream &operator<<(ostream &output, const Fraction& obj) {
    if (obj.numerator==0){
        output<<0;
    }
    else if (obj.denominator==0){
        output<<"It cannot be divided by zero";
    }
    else if (obj.numerator==obj.denominator){
        output<<1;
    }
    else{
        output<<obj.numerator<<'/'<<obj.denominator;
    }
    return output;
}
/*------------------------------------------------------------*/
Fraction Fraction::operator+(const Fraction& obj) const {
    Fraction fr;
    fr.numerator = numerator * obj.denominator + denominator * obj.numerator;
    fr.denominator = denominator * obj.denominator;
    fr.reduce(fr.numerator,fr.denominator);
    return fr;
}
Fraction Fraction::operator-(const Fraction& obj) const {
    Fraction fr;
    fr.numerator = numerator * obj.denominator - denominator * obj.numerator;
    fr.denominator = denominator * obj.denominator;
    fr.reduce(fr.numerator,fr.denominator);
    return fr;
}
Fraction Fraction::operator*(const Fraction& obj) const {
    Fraction fr;
    fr.numerator = numerator * obj.numerator;
    fr.denominator = denominator * obj.denominator;
    fr.reduce(fr.numerator,fr.denominator);
    return fr;
}
Fraction Fraction::operator/(const Fraction& obj) const {
    Fraction fr;
    fr.numerator = numerator * obj.denominator;
    fr.denominator = denominator * obj.numerator;
    fr.reduce(fr.numerator,fr.denominator);
    return fr;
}
