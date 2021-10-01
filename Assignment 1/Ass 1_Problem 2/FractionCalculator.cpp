#include "FractionCalculator.h"

FractionCalculator::FractionCalculator() = default;

void FractionCalculator::menu() {
    cout<<"1- Perform Fraction Addition"<<endl;
    cout<<"2- Perform Fraction Subtraction"<<endl;
    cout<<"3- Perform Fraction Multiplication"<<endl;
    cout<<"4- Exit"<<endl;
}

void FractionCalculator::result() {
    int choice;
    bool y = true;
    while (y)
    {
        cout<<"Welcome to FCI Fraction Calculator"<<endl;
        cout<<"----------------------------------------"<<endl;
        menu();
        cin>>choice;
        static Fraction full;
        switch (choice) {
            case 1:{
                Fraction f1,f2;
                cin>>f1>>f2;
                full=f1+f2;
                full.reduce(full.getNumerator(),full.getDenominator());
                cout<< full <<endl;
            }
                break;
            case 2:{
                Fraction Fr;
                cin>>Fr;
                full = full - Fr;
                full.reduce(full.getNumerator(),full.getDenominator());
                cout<< full <<endl;
            }
                break;
            case 3:{
                Fraction Fr;
                cin>>Fr;
                full = full * Fr;
                full.reduce(full.getNumerator(),full.getDenominator());
                cout<< full <<endl;
            }
                break;
            case 4:{
                y= false;
            }
                break;
            default:
                y= false;
                break;
        }
    }
}
