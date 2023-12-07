#pragma once

#include <string>
using namespace std;

class Shape
{
private:
    int Length;
    int Width;
public:
    Shape(int len, int wid);
    virtual ~Shape();
    virtual void draw();
    int getLength() const;
    int getWidth() const;
};

class Fillable
{
private:
    string fColour;
public:
    Fillable(string fCol);
    virtual ~Fillable();
    string getFColour() const;
};

class Text
{
private:
    string txt;
public:
    Text(string msg);
    ~Text();
    string getText() const;
};

class Square : public Shape
{
private:
    string oColour;
public:
    Square(int len, int wid, string oCol);
    ~Square();
    virtual void draw();
    string getOColour() const;
};

class FilledSquare : public Square, public Fillable
{
public:
    FilledSquare(int len, int wid, string oCol, string fCol);
    ~FilledSquare();
    virtual void draw();
};

class FilledTextSquare : public Square, public Fillable, public Text
{
public:
    FilledTextSquare(int len, int wid, string oCol, string fCol, string msg);
    ~FilledTextSquare();
    virtual void draw();
};

class Circle : public Shape
{
private:
    string oColour;
public:
    Circle(int len, int wid, string oCol);
    ~Circle();
    virtual void draw();
    string getOColour() const;
};

class FilledCircle : public Circle, public Fillable
{
public:
    FilledCircle(int len, int wid, string oCol, string fCol);
    ~FilledCircle();
    virtual void draw();
};

class Arc : public Shape
{
private:
    string oColour;
public:
    Arc(int len, int wid, string oCol);
    ~Arc();
    virtual void draw();
    string getOColour() const;
};