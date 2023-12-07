#include <iostream>
#include <string>

using namespace std;

class Fraction {
    private:
        int num; //Fraction's numerator
        int den; //Fraction's denominator
        int gcd(int,int); //function to find greatest common denominator
    public:
        Fraction(); //base constructor: 0/1
        Fraction(int); //creates a fraction with variable as numerator and denominator of 1
        Fraction(int,int); //creates fraction with given numerator and denominator
        int numerator() const; //returns numerator as int
        int denominator() const; //returns denominator as int

        //unary operators
        Fraction operator-(); //inverses sign
        Fraction& operator++(); //post increment
        Fraction operator++(int); //pre increment

        //binary operators
        friend Fraction operator+(const Fraction& a, const Fraction& b);
        friend Fraction operator-(const Fraction& a, const Fraction& b);
        friend Fraction operator*(const Fraction& a, const Fraction& b);
        friend Fraction operator/(const Fraction& a, const Fraction& b);
        Fraction& operator+=(const Fraction& a);    

        //comparison operators
        friend bool operator<(const Fraction& a, const Fraction& b);
        friend bool operator<=(const Fraction& a, const Fraction& b);
        friend bool operator==(const Fraction& a, const Fraction& b);
        friend bool operator!=(const Fraction& a, const Fraction& b);
        friend bool operator>=(const Fraction& a, const Fraction& b);
        friend bool operator>(const Fraction& a, const Fraction& b);

        //input and output
        friend ostream& operator << (ostream& os, const Fraction &a);
        friend istream& operator >> (istream& is, Fraction& ret);     
};

//exception for denominator of 0
class FractionException {
private:
	string error; 
public:
	FractionException(const string& msg); 
	string what(); 
};