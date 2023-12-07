#include "Assn4_19ajp17.h"
#include <string.h>
#include <ctime>
#include <iostream>

using namespace std;

JumblePuzzle::JumblePuzzle(){
    len = 0;
    dir = 0;
    row = 0;
    col = 0;
    charArrayPtr* A = nullptr; 
};

JumblePuzzle::JumblePuzzle(string word, string diff){
    len = 0;
    dir = 0;
    row = 0;
    col = 0;
    A = nullptr;
    if(diff.compare("easy")==0){
        len = 2*word.length();
        A = new char* [len];
        for (int i = 0; i < len; i++) {
			A[i] = new char[len]; //using heap

		}
    }
    if(diff.compare("medium")==0){
        len = 3*word.length();
        A = new char* [len];
        for (int i = 0; i < len; i++) {
			A[i] = new char[len]; //using heap

		}
    }
    if(diff.compare("hard")==0){
        len = 4*word.length();
        A = new char* [len];
        for (int i = 0; i < len; i++) {
			A[i] = new char[len]; //using heap

		}
    }
    if(diff.compare("easy")!=0 && diff.compare("medium")!=0 && diff.compare("hard") != 0){
        throw BadJumbleException("Difficulty Invalid: Must be 'easy', 'medium', or 'hard'");
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            char letters[] = "abcdefghijklmnopqrstuvwxyz";
            A[i][j] = letters[rand() % 26];
        }
        
    }
    
    srand(time(NULL));
    row = rand() % len;
    col = rand() % len;

    srand(time(NULL));
    int i = 0;
    while(i<word.length()){
        srand(time(NULL));
        dir = rand() % 4;
        switch(dir){
            case 0:
                for ( i = 0; i < word.length(); i++)
                {
                    if(row+i>=len){break;}
                    A[row+i][col] = word[i];
                }
                if(row+i==len){continue;}
                break;
            case 1:
                for ( i = 0; i < word.length(); i++)
                {
                    if(row-i<0){break;}
                    A[row-i][col] = word[i];
                }
                if(row-i<0){continue;}
                break;
            case 2:
                for ( i = 0; i < word.length(); i++)
                {
                    if(col+i>=len){break;}
                    A[row][col+i] = word[i];
                }
                if(col+i>=len){continue;}
                break;
            case 3:
                for ( i = 0; i < word.length(); i++)
                {
                    if(col-i<0){break;}
                    A[row][col-i] = word[i];
                }
                if(col-i<0){continue;}
                break;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

JumblePuzzle::JumblePuzzle(JumblePuzzle& other){
    len = other.getSize();
    dir = other.getDirection();
    col = other.getColPos();
    row = other.getRowPos();
    charArrayPtr* B = other.getJumble();
    A = new charArrayPtr[other.getSize()];
    
    for (int i = 0; i < len; i++) {
        A[i] = new char[len];
        for (int j = 0; j < len; j++) {
            A[i][j] = B[i][j];
        }
    }
}

JumblePuzzle::~JumblePuzzle(){
    for (int i = 0; i < len; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

JumblePuzzle& JumblePuzzle::operator=(JumblePuzzle& right) {
  if (this != &right) {		// Check to see if assigning to self
		for (int i = 0; i < len; i++) {
			delete[] A[i];
		}
		delete[] A;
	}
		len = right.getSize();
		dir = right.getDirection();
		row = right.getRowPos();
		col = right.getColPos();
		
		char** B = new char* [len];

		for (int i = 0; i < len; i++) {
			B[i] = new char[len];
		}

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				B[i][j] = right.A[i][j]; 
			}
		}
	return *this;			
}

int JumblePuzzle::getSize() {
	return len;
}

int JumblePuzzle::getRowPos() {
	return row;
}

int JumblePuzzle::getColPos() {
	return col;
}

charArrayPtr* JumblePuzzle::getJumble() {
	return A;
}

char JumblePuzzle::getDirection() { 
	char ret = 'x';
    switch(dir){
        case 0:
            ret = 'n';
            break;
        case 1:
            ret = 's';
            break;
        case 2:
            ret = 'e';
            break;
        case 3:
            ret = 'w';
            break;
    }
    return ret;
}

BadJumbleException::BadJumbleException(const string& m) : message(m) {}
string& BadJumbleException::what() { return message; }