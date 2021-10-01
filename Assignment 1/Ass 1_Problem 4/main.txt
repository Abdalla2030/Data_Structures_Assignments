#include <iostream>
using namespace std;
int power1(int a,int n);
int power2(int a,int n);
int main() {
    int num,pow;
    cout<<"Enter the base and power:";
    cin>>num>>pow;
    cout<<power1(num,pow)<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Enter the base and power:";
    cin>>num>>pow;
    cout<<power2(num,pow)<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Enter the base and power:";
    cin>>num>>pow;
    cout<<power2(num,pow)<<endl;
    return 0;
}
int power1(int a,int n){
    if (n == 0){
        return 1;
    }
    else{
        return a * power1(a,n-1);
    }
}
int power2(int a,int n){
    if (n %2 ==1)
    {
        return  power1(a,n/2) * power1(a,n/2+1);
    }
    else{
        return   power1(a,n/2) * power1(a,n/2);
    }
}