/* Conor Smyth 12452382
 * Hangman class header
 * Now includes sneaky features
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
		string word; //the word
		string c; //the char
		string displayWord; //the word to show the user
		string store; //store to keep guesses
	public: //public methods for hangman
		Hangman(int len); //initailise Hangman
		Hangman(string w1); //initailise Hangman
		int wordLength(); //return length of the word
		void pw(); //print the underscored word
		void getChar(); //read in char
		int checkForChar(); //check for char in word
		void alreadyGuessed(); //warn already guessed
		void charNotFound(); //char not found warning
		void charFound(); //char found prompt
		int numFound(); //number of times letter found
		void win(int g); //win message
		void lose(); //lose message
		string returnChar(); //return the char
		bool validate(); //ensure letter not already guessed
		void getWord(string s); //get a word
};
