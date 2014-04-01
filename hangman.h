/* Conor Smyth 12452382
 * Hangman class header
 * All work is my own
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#include <string>
#include <stdlib.h>

using namespace std;

class Hangman {
	private: //private variables for hangman
		string word;
		string c;
		string displayWord;
		string store;
	public: //public methods for hangman
		Hangman(string w1);
		Hangman(int len);
		void win(int g);
		void lose();
		string returnChar();
		int randomNumber(int n, int m);
		void getChar();
		int checkForChar();
		void charNotFound();
		void charFound();
		void pw();
		int wordLength();
		void alreadyGuessed();
		int numFound();
		bool oneChar(string s);
		void giveWord(string s);
		bool validate();
};
