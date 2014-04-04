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
		Dict(int wordLength0); //1
		void getWords(); //2
		bool checkForRepeat(string s); //just after 2
		void reduceWords(string s);//reduces the amount of words in vector relevant //3
		int findFreq(string s);//find the freq for reducing //just after 3
		int largest(int nums[]);//find the pos with the most //just after find freq before reduce
		int reduceDisplay(string s, int p); //just after findfreq
		bool checkDict(string s); //4
		string sample();//give a sample //5
		void printWord(); //last
};
