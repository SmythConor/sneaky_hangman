#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

/* Some of the methods and variables needed not completed */

class Dict {
	private:
		int size;
		int wordLength;
		vector<string> wrds;
		string displayWord;
		vector<string>::iterator it;
	public:
		Dict(int wordLength0);
		void reduceWords(string s);//reduces the amount of words in vector relevant
		int findFreq(string s);//find the freq for reducing
		int largest(int nums[]);//find the pos with the most
		string sample();//give a sample
		bool checkDict(string s);
		void printVector(vector<string> s);
		int reduceDisplay(string s, int p);
		void printWord();
		bool checkForRepeat(string s);
		void getWords();
};
