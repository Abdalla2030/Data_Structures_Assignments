/**                   Assignment 1 - Problem 6
 *                    Ahmed Essam El-din                   20190050
 *                    Abdalla Fadl Shehata                  20190305
 *                    Ali Mohamed Abdel-Samie         20190342
 */
#include <iostream>
#include <string>
#include"BigDecimalInt.h"
using namespace std;
int main()
{
    BigDecimalInt num1("123456789012345678901234567890");
    cout <<" num1 = 123456789012345678901234567890 " <<endl;
    BigDecimalInt num2("113456789011345678901134567890");
    cout<<" num2 = 113456789011345678901134567890 "<<endl;
    BigDecimalInt num3 = num2 + num1;
    cout << " num3 = num2 + num1 = " << num3 << endl;
    //236913578023691357802369135780
    cout<<"**********************************"<<endl;
    BigDecimalInt num4("-2345678901234567890");
     cout <<" num4 = -2345678901234567890 " <<endl;
    BigDecimalInt num5("-56789011345678901134567890");
    cout <<" num5 = -56789011345678901134567890 " <<endl;
    BigDecimalInt num6 = num4 + num5;
    cout << " num6 = num4 + num5 = " << num6 << endl;
    //-56789013691357802369135780
    cout<<"**********************************"<<endl;
    BigDecimalInt num7("1230000000000000001");
     cout <<" num7 = -1230000000000000001 " <<endl;
    BigDecimalInt num8("30000000000000001");
    cout <<" num8 = 30000000000000001 " <<endl;
    BigDecimalInt num9 = num7 - num8;
    cout << " num9 = num7 - num8 = " << num9 << endl;
    //1200000000000000000
    cout<<"**********************************"<<endl;
     BigDecimalInt num10("-1230000000000000001");
     cout <<" num10 = -1230000000000000001 " <<endl;
    BigDecimalInt num11("30000000000000001");
    cout <<" num11 = 30000000000000001" <<endl;
    BigDecimalInt num12 = num10 + num11;
    cout << " num12 = num10 + num11 = " << num12 << endl;
    //-1200000000000000000
    cout<<"**********************************"<<endl;
    BigDecimalInt num13(-20);
     cout <<" num13 = -20 " <<endl;
    BigDecimalInt num14(-30);
    cout <<" num14 = -30" <<endl;
    BigDecimalInt num15 = num13 - num14;
    cout << " num15 = num13 - num14 = " << num15 << endl;
    //10
    return 0;
}
