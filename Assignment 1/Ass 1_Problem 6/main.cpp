/**                   Assignment 1 - Problem 6
 *                    Ahmed Essam El-din                   20190050
 *                    Abdalla Fadl Shehata                  20190305
 *                    Ali Mohamed Abdel-Samie         20190342
 */
#include <iostream>
#include <string>
using namespace std;
class StudentName
{
private :
    string names[10];
    int num_of_string ;
public :
    StudentName(string  s)
    {
        int num_of_spaces = 0 ;
        int index_of_space = 0 ;
        for (int i = 0 ; i < s.size() ; i++)
        {
            if (s[i]==' ')
            {
                num_of_spaces++;
                index_of_space = i ;
            }
        }
        if (num_of_spaces==0)
        {
            num_of_string = 3 ;
            names[0] = s ;
            names[1] = s ;
            names[2] = s ;
        }
        else if (num_of_spaces==1)
        {
            string sub_string1 =  s.substr(0,index_of_space);
            string sub_string2 = s.substr(index_of_space+1,s.size()-1);
            num_of_string = 3 ;
            names[0] = sub_string1 ;
            names[1] = sub_string2 ;
            names[2] = sub_string2  ;
        }
        else
        {
            num_of_string = num_of_spaces+1 ;
            string temp  ;
            char ch ;
            int j = 0 ;
            for (int i = 0 ; i < s.size(); i++)
            {
                ch = s[i];
                if (ch !=' '  && i != s.size()-1)
                {
                    temp.push_back(ch);
                }
                else if (ch !=' '  && i == s.size()-1 )
                {
                    temp.push_back(ch);
                    ch = s[i+1];
                    temp.push_back(ch);
                    names[j] = temp ;
                    temp = "";
                    j++;
                }
                else
                {
                    names[j] = temp ;
                    temp = "";
                    j++;
                }
            }
        }
    }
    bool replace(int i, int j)
    {
        if (i>num_of_string || j>num_of_string){
            return false ;
        }
        else {
        string temp ;
        temp = names[i-1];
        names[i-1]=names[j-1];
        names[j-1]=temp ;
        return true ;
        }
    }
    void print () {
        for(int k = 0 ; k < num_of_string  ;k++){
                cout<<'('<<k+1<<')'<<names[k]<<endl;
       }
       }
};
int main()
{
    /////////////////////////////////////////////////////////////
    StudentName test1("Osama Ahmed");
    if(test1.replace(3,1)){
            cout<<"True"<<endl;
             test1.print();
    }
    else {
    cout<<"False"<<endl;
     test1.print();
    }
    /////////////////////////////////////////////////////////////
    StudentName test2("Osama Ahmed");
     if(test2.replace(4,1)){
            cout<<"True"<<endl;
             test2.print();
     }
    else {
    cout<<"False"<<endl;
     test2.print();
    }
     /////////////////////////////////////////////////////////////
     StudentName test3("Khaled" );
     if(test3.replace(5,10)){
            cout<<"True"<<endl;
             test3.print();
     }
    else {
    cout<<"False"<<endl;
     test3.print();
    }
     /////////////////////////////////////////////////////////////
    StudentName test4("aya ali ahmed sayed" );
     if(test4.replace(1,5)){
            cout<<"True"<<endl;
             test4.print();
     }
    else {
    cout<<"False"<<endl;
     test4.print();
    }
     /////////////////////////////////////////////////////////////
    StudentName test5("ahmed hassan ali mohamed mostafa" );
    if(test5.replace(2,4)){
            cout<<"True"<<endl;
             test5.print();
     }
    else {
    cout<<"False"<<endl;
     test5.print();
    }
    /////////////////////////////////////////////////////////////
    return 0;
}
