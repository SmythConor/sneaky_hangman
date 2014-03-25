/* Conor Smyth 12452382
 * Hangman class header
 * All work is my own
 */
#include <string>

using namespace std;

class Hangman {
	private: //private variables for hangman
		string word;
		string c;
		string displayWord;
		string store;
	public: //public methods for hangman
		Hangman(string w1);
		void win(int g);
		void lose();
		int randomNumber(int n, int m);
		void getChar();
		int checkForChar();
		void charNotFound();
		void charFound();
		void pw();
		int wordLength();
		void alreadyGuessed();
		int numFound();
};
