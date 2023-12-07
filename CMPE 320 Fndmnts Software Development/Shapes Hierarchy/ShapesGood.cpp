
#include <string>
#include <iostream>
#include "ShapesGood.h"

using namespace std;

Shape::Shape(int len, int wid)
{
    this->Length = len;
    this->Width = wid;
}

Shape::~Shape()
{}

void Shape::draw(){
    cout << "Draw Shape" << endl;
}

int Shape::getLength() const {
    return this->Length;
}

int Shape::getWidth() const {
    return this->Width;
}

Fillable::Fillable(string fColour)
{
    this->fColour = fColour;
}

Fillable::~Fillable()
{}

string Fillable::getFColour() const {
    return this->fColour;
}


Text::Text(string msg)
{
    this->txt = msg;
}

Text::~Text()
{}

string Text::getText() const {
    return this->txt;
}

Square::Square(int len, int wid, string oCol) : Shape(len,wid)
{
    this->oColour = oCol;
}

Square::~Square() {}

string Square::getOColour() const {
    return this->oColour;
}

void Square::draw(){
    cout<< "Drawing a " +getOColour()+ " Square" <<endl;
}

FilledSquare::FilledSquare(int len, int wid, string oCol, string fCol) : Square(len,wid,oCol), Fillable(fCol)
{}

FilledSquare::~FilledSquare(){}

void FilledSquare::draw(){
    cout<< "\nDrawing "+getOColour()+" Square filled with "+getFColour()<<endl;
}

FilledTextSquare::FilledTextSquare(int len, int wid, string oCol, string fCol, string msg) : Square(len,wid,oCol), Fillable(fCol), Text(msg)
{}

FilledTextSquare::~FilledTextSquare()
{}

void FilledTextSquare::draw(){
    cout<<"Drawing "+getOColour()+" Square filled with "+getFColour()+" with text "+getText()<<endl;
}

Circle::Circle(int len, int wid, string oCol) : Shape(len,wid)
{
    this->oColour = oCol;
}

Circle::~Circle()
{}

string Circle::getOColour() const {
    return this->oColour;
}

void Circle::draw(){
    cout<<"\nDrawing "+getOColour()+" Circle"<<endl;
}

FilledCircle::FilledCircle(int len, int wid, string oCol, string fCol) : Circle(len, wid, oCol), Fillable(fCol)
{}

FilledCircle::~FilledCircle()
{}

void FilledCircle::draw(){
    cout<<"\nDrawing "+getOColour()+" Circle filled with "+getFColour()<<endl;
}

Arc::Arc(int len, int wid, string oCol) : Shape(len,wid)
{
    this->oColour = oCol;
}

Arc::~Arc()
{
}

string Arc::getOColour() const {
    return this->oColour;
}

void Arc::draw(){
    cout<<"Drawing "+getOColour()+" Arc"<<endl;
}
