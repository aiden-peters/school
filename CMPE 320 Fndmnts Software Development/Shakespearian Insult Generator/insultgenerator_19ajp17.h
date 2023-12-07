#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include <set>
#include <sstream>
#include <algorithm>


using namespace std;

class InsultGenerator //Insult generating class
{
public:
    void initialize(); //takes the source text file and puts it in three vectors, one for each column
    string talkToMe(); //generates a single insult from col1, col2, and col3
    vector<string> generate(int n); //creates n insults, sorted alphabetically with no duplicates
    vector<string> generateAndSave(string file, int n); //creates n insults, sorted alphabetically with no duplicates and saves them to a text file

private:
    vector<string> col1, col2, col3, all; //creats a vector for each insult column and one with all three
    int generateRand(); //generates a random integer from 0 to 49 
    
};
class FileException //error for files
{
    public:
        FileException(const string&);
        string what();
    private:
        string message;
};
class NumInsultsOutOfBounds //error for if n > 10000 or n < 1
{
    public:
        NumInsultsOutOfBounds(const string&);
        string what();
    private:
        string message;
};
