#include "fraction_19ajp17.h"

#include <iostream>

using namespace std;

//recursive gcd function as supplied in assignmnet description
int Fraction::gcd(int n,int m){
    if((abs(m)<=abs(n))&&(n%m==0)){
        return m;
    }
    else if (n<m)
    {
        return gcd(m,n);
    }
    else{
        return gcd(m,n % m);
    }
}

Fraction::Fraction() : num(0), den(1){}

Fraction::Fraction(int n) : num(n), den(1){}

Fraction::Fraction(int n, int m){
    if(m==0){
        throw FractionException("Denominator cannot be 0!");
    }
    int d = gcd(n,m);
    if(m<0){ //if denominator is negative, reverse sign of numerator and denominator
        num = ((n*(-1))/d);
        den = ((m*(-1))/d);
    }
    else{
        num = n/abs(d);
        den = m/abs(d);
    }
}

int Fraction::numerator() const {
    return num;
}

int Fraction::denominator() const {
    return den;
}

Fraction Fraction::operator-(){
    return Fraction(-num,den);
}

Fraction& Fraction::operator++(){
    num+=den;
    return *this;
}

Fraction Fraction::operator++(int a){
    Fraction f(num,den);
    num+=(den);
    return f;
}

Fraction operator+(const Fraction& a, const Fraction& b){
    if(a.denominator()==b.denominator()){//if denominators are the same just add numerators
        return Fraction(a.numerator()+b.numerator(),a.denominator());
    } else { //multiply num by other fraction's den and constructor will simplify
        return Fraction((a.numerator()*b.denominator())+a.denominator()*b.numerator(),a.denominator()*b.denominator());
    }
    
}

Fraction operator-(const Fraction& a, const Fraction& b){
    if(a.denominator()==b.denominator()){ //if denominators are the same just subtract numerators
        return Fraction(a.numerator()-b.numerator(),a.denominator());
    } else { //multiply num by other fraction's den and constructor will simplify
        return Fraction((a.numerator()*b.denominator())-(a.denominator()*b.numerator()),a.denominator()*b.denominator());
    }
}

Fraction operator*(const Fraction& a, const Fraction& b){
    return Fraction(a.numerator()*b.numerator(),a.denominator()*b.denominator());
}

Fraction operator/(const Fraction& a, const Fraction& b){ //flip fraction and multiply
    return Fraction(a.numerator()*b.denominator(),a.denominator()*b.numerator());
}

Fraction& Fraction::operator+=(const Fraction& a){
    if(den==a.denominator()){//if den==a.den numerator can be added to
        num += a.numerator();
    } else {//f will create a temp fraction to simplify in constructor
        Fraction f = Fraction(num*a.denominator()+den*a.numerator(),den*a.denominator());
        num = f.num; 
        den = f.den;
    }
	return *this;
}

bool operator<(const Fraction& a, const Fraction& b){
    return(a.numerator()*b.denominator() < b.numerator()*a.denominator());
}

bool operator<=(const Fraction& a, const Fraction& b){
    return(a.numerator()*b.denominator() <= b.numerator()*a.denominator());
}

bool operator == (const Fraction& a, const Fraction& b){
    return((a.numerator()==b.numerator()) && (a.denominator()==b.denominator()));
}

bool operator != (const Fraction& a, const Fraction& b){//inverse of == overload
    return !((a.numerator()==b.numerator()) && (a.denominator()==b.denominator()));
}

bool operator>=(const Fraction& a, const Fraction& b){
    return(a.numerator()*b.denominator() >= b.numerator()*a.denominator());
}

bool operator>(const Fraction& a, const Fraction& b){
    return(a.numerator()*b.denominator() > b.numerator()*a.denominator());
}

ostream& operator<<(ostream& os, const Fraction& a){
    os << a.numerator() << "/" << a.denominator();
    return os;
}

istream& operator>>(istream& is, Fraction& ret){
    int top, bot;
    is >> top; //puts first character in numerator
if (is.peek() != 0x0A) { //checks if next key isn't the enter key, 0x0A in hexdecimal
	   char nextChar;
	   is >> nextChar;
	   if (nextChar == '/')
		  is >> bot;//denominator
	   else
		   bot = 1;
	   ret = Fraction(top, bot);
   } else //if no fraction given, create one with 1 as denominator
	   ret = Fraction(top);
   return is;
}

FractionException :: FractionException(const string& msg) : error(msg) {
}
string FractionException :: what() {
	return error;
}