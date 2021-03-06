//
// Created by Ahmed Essam Eldin 20190050 on 5/14/2021.
//
#include <iostream>
#include <string>
#include <set>

using namespace std;
void ListPermutations(string s);
void RecPermute(string soFar,string rest);
set <string> s1;
set <string>::iterator itr=s1.begin();
int main() {

    string word="ABCA";
    ListPermutations(word);
    return 0;
}

void RecPermute(string soFar,string rest)
{
    if (rest == "") { // No more characters
        int oldSize=s1.size();
        s1.insert(soFar);
        int currentSize=s1.size();
        if (oldSize!=currentSize) {
            cout << soFar << endl;// Print the word
        }
    }
    else // Still more chars
// For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i];// Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
}
// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}
