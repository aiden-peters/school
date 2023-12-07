#include <string>
using namespace std;
typedef char* charArrayPtr;

class JumblePuzzle {
	private:
		int len;
		int dir;
		int row;
		int col;
		charArrayPtr* A = nullptr;

	public:
		JumblePuzzle(); 
		JumblePuzzle(string word, string diff); 
		JumblePuzzle(JumblePuzzle& otherJumble); 
		~JumblePuzzle();
		charArrayPtr* getJumble(); 
		int getSize(); 
		int getRowPos(); 
		int getColPos(); 
		char getDirection(); 
		JumblePuzzle& operator=(JumblePuzzle& right); 
};

//Exception
class BadJumbleException {
public:
	BadJumbleException(const string& message);
	string& what();

private:
	string message;
};