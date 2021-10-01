#ifndef BIGDECIMALINT_H_INCLUDED
#define BIGDECIMALINT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class BigDecimalInt
{
private :
    string num;
    int sum, carry;
public:
    BigDecimalInt( );
    BigDecimalInt(string  );
    BigDecimalInt(int  );
    friend ostream& operator<< (ostream& , BigDecimalInt& );
    void addZerosToLift(int , string& , string& );
    BigDecimalInt operator+(BigDecimalInt& );
    bool secondIsBigger(string& , string&);
    BigDecimalInt operator-(BigDecimalInt& );
    BigDecimalInt operator= (BigDecimalInt & );
    int size(string& );
    void ReverseString(string& ) ;

};
#endif // BIGDECIMALINT_H_INCLUDED
