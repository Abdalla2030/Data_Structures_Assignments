#include"BigDecimalInt.h"
void BigDecimalInt::ReverseString(string& s)
{
   int n = s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
}
///////////////////////////////////////////////
BigDecimalInt::BigDecimalInt(){
num="";
}
///////////////////////////////////////////////
BigDecimalInt::BigDecimalInt(string dec_str){
num=dec_str;
}
///////////////////////////////////////////////
BigDecimalInt :: BigDecimalInt(int dec_int){
if (dec_int >0 ){
     while ( dec_int!=0)
    {
        num+=(dec_int%10)+'0';
        dec_int-= dec_int%10;
        dec_int/=10;
    }
}
else if (dec_int<0){
 dec_int*=-1;

        while ( dec_int!=0)
    {

        num+=(dec_int%10)+'0';
        dec_int-= dec_int%10;
        dec_int/=10;

    }
    num+='-';
}
else {
    num="0";
}
    ReverseString(num);
}
///////////////////////////////////////////////
ostream& operator<< (ostream& output, BigDecimalInt&  obj){
output<<obj.num;
return output;
}
///////////////////////////////////////////////
void BigDecimalInt::addZerosToLift(int maxSize, string& str1, string& str2)
{
	int Num_Of_Zeros;
	if (str1.length() > str2.length())
	{
		Num_Of_Zeros = maxSize - str2.length();
		for (int i = 0; i < Num_Of_Zeros; i++)
			str2 = '0' + str2;
	}
	else if (str1.length() < str2.length())
	{
		Num_Of_Zeros = maxSize - str1.length();
		for (int i = 0; i < Num_Of_Zeros; i++)
			str1 = '0' + str1;
	}
}
///////////////////////////////////////////////
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt& anotherDec){
string first = num;
string second = anotherDec.num;
bool Two_Num_Negative = false ;
if (first[0] == '-' && second[0] == '-')
{
		Two_Num_Negative = true;
		first = first.substr(1);
		second = second.substr(1);
}
else if (first[0] == '-')
{
    BigDecimalInt temp(first.substr(1));
    first = first.substr(1); ////////////////////////////////////////////////
    return anotherDec - temp;  // *****call operator -
}
else if (second[0] == '-')
{
        BigDecimalInt temp(second.substr(1));
        second = second.substr(1);////////////////////////////////////
        BigDecimalInt CurrentString(first);
		return CurrentString - temp;  // *****call operator -
}
int maxSize =  0;
if (size(num)>size(anotherDec.num)){
    maxSize = size(num);
}
else {
    maxSize = size(anotherDec.num);
}
	addZerosToLift(maxSize, first, second);
	string result = "";
	carry = 0 ;
	for (int i = maxSize - 1; i >= 0; i--)
	{
      sum = ((first[i]-'0')+(second[i]-'0')+carry);
      result += sum%10 + '0';
      carry = sum/10;
	}
	if (carry==1){
		result = result+'1';//
	}
	if (Two_Num_Negative){
		result = result+'-';
	}
    ReverseString(result);
	BigDecimalInt BigDecimalInt_Sum(result);
	return BigDecimalInt_Sum;
}
///////////////////////////////////////////////
bool BigDecimalInt::secondIsBigger(string& s1, string& s2){
for (int i = 0; i < size(s1); i++){
    if (s2[i] > s1[i]){
        return true ;
    }
    else {
        return false ;
    }
}
 return false;
}
///////////////////////////////////////////////
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt& anotherDec){
string first = num;
string second = anotherDec.num;
if (first[0] == '-' && second[0] == '-')
{
        //if both are negative, we convert to positive and swap between two numbers
		first = first.substr(1);
		second = second.substr(1);
		string temp = first;
		first = second;
		second = temp;
}
else if (first[0] == '-')
	{
		//if the first is negative and second is positive
		// we call operator+ and add negative sign to result
		first = first.substr(1);
		BigDecimalInt temp(first);
		BigDecimalInt BigDecimalInt_Sum = temp+anotherDec;
		BigDecimalInt_Sum.num = '-' + BigDecimalInt_Sum.num;
		return BigDecimalInt_Sum;
	}
	else if (second[0] == '-')
	{
		//if the first is positive and second is negative
		// we convert second to positive and call operator+
		// first - (-second) = first + second
		BigDecimalInt temp(second.substr(1));
		BigDecimalInt CurrentString(first);
		return CurrentString + temp;//
	}
    int maxSize =  0;
    if (size(num)>size(anotherDec.num)){
        maxSize = size(num);
    }
    else {
        maxSize = size(anotherDec.num);
    }
        addZerosToLift(maxSize, first, second);
        string result = "";
        carry = 0 ;
        bool b = secondIsBigger(first,second);
        if (b){
        string temp = first;
		first = second;
		second = temp;
        }
       string res = "";
	   carry = 0 ;
       for (int i = maxSize - 1; i >= 0; i--)
        {
          sum = ((first[i]-'0')-(second[i]-'0')-carry);
          if (sum < 0) {
            sum = sum + 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        res += sum+'0';
        }
        if (b){//////////////////////////////////
            res = res+'-';
        }
        ReverseString(res);
        BigDecimalInt BigDecimalInt_Subtract(res);
        return BigDecimalInt_Subtract;
}
///////////////////////////////////////////////
BigDecimalInt BigDecimalInt::operator= (BigDecimalInt & anotherDec ){
num = anotherDec.num;
return anotherDec;
}
///////////////////////////////////////////////
int BigDecimalInt ::size(string&  ss)
{
    if (ss[0]=='-'){
    return ss.length()-1;
    }
    else {
       return ss.length();
    }
}
