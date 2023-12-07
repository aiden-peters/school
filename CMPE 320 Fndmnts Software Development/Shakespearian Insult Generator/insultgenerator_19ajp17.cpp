
#include "insultgenerator_19ajp17.h"

using namespace std;

void InsultGenerator::initialize(){
    string line;
    ifstream fileIn("InsultsSource.txt");
    if (fileIn.fail()) {
        throw FileException("Illegal file!");
        return;
    }
    stringstream ss;
    while (!fileIn.eof()) { 
        getline(fileIn, line);
        ss.clear();
        ss.str(" ");
        ss << line;
        while (ss >> line) { 
            all.push_back(line);
        } 
    } 
    for (int i = 0; i < all.size(); i += 3) {
        col1.push_back(all[i]);
        col2.push_back(all[i + 1]);
        col3.push_back(all[i + 2]);
    }
    fileIn.close();
}; 

int InsultGenerator::generateRand(){
    int n;
    n = rand() % 49;
    return n;
};

string InsultGenerator::talkToMe(){
    string one, two, three;
    one = col1[generateRand()];
    two = col2[generateRand()];
    three = col3[generateRand()];
    string insult = "Thou " + one + ' ' + two + ' ' + three +'!';
    return insult;
};

vector<string> InsultGenerator::generate(int n){
    set<string> insults;
    if(n>10000||n<1){
        throw NumInsultsOutOfBounds("Number out of bounds!");
        return vector<string>();
    }
    else{
    while(n > insults.size()){
        string insult = talkToMe();
        insults.insert(insult);
    }}
    vector<string> insultsToReturn(insults.begin(),insults.end());
    return insultsToReturn;
};

vector<string> InsultGenerator::generateAndSave(string file, int n){
    set<string> insults;
    ofstream outputFile(file);
    if(n>10000||n<1){
        throw NumInsultsOutOfBounds("Number out of bounds!");
        return vector<string>();
    }
    else{
    while(n > insults.size()){
        string insult = talkToMe();
        insults.insert(insult);
        
    }}
    vector<string> insultsToReturn(insults.begin(),insults.end());
    for (int i = 0; i < insults.size(); i++)
    {
        outputFile << insultsToReturn[i];
        outputFile << "\n";
    }
    
    return insultsToReturn;
};

FileException::FileException(const string& m) : message(m){}
string FileException::what(){
    return message;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {}
string NumInsultsOutOfBounds::what(){
    return message;
}

