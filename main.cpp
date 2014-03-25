/* Conor Smyth 12452382
 * Normal hangman main class
 * Assuming valid input
 * All work is my own
 */

#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "hangman.h"

using namespace std;

/* method headers */

int randomNumber(int n, int m); 
string getWord();
void displayGuesses(int g);
void prompt();
bool endMessage(int n);
bool cont(int i, int k);

int main() { //main
	string line = getWord(); //get word from dictionary file
	Hangman h(line); //
	int guesses = 5; //number of guesses 
	int len = h.wordLength(); //length of word
	int num = 0; //temp variable

	cout << "Welcome to hangman." << endl; //welcome message

	while(cont(guesses, len)) {
		displayGuesses(guesses); //display guesses left
		h.pw(); //print word in underscoes
		prompt(); //ask user for character
		h.getChar();//print out if they were correct

		int t = h.checkForChar();

		if(t == 0) {
			h.alreadyGuessed(); //already guessed
		}

		else if(t < 0) { //char not found so decrement guesses and show warning
			h.charNotFound();
			guesses--;
		}

		else { //char found show places and decrement how many more letters are needed
			h.charFound();
			int num = h.numFound();
			len = len - num;
		}

	}

	if(endMessage(guesses)) { //win message
		h.win(guesses);
	}

	else { //loss message
		h.lose();
	}

}

bool cont(int i, int k) { //win/loss conditions for gueses
	return i > 0 && k > 0;
}

bool endMessage(int n) { //decide which message to give
	return n > 0;
}

void displayGuesses(int g) { //display remaining guesses
	cout << "You have " << g << " guess(s) left." << endl;
}

void prompt() { //ask for char
	cout << "Place enter a character: " << endl;
}

string getWord() { //read in a random word from dictionary file
	ifstream dict("dictionary");
	string line;
	int randWord = randomNumber(1, 45394); //random word to return 

	for(int i = 1; i < randWord; i++) {
		getline(dict, line);
	}

	return line; //return the word
}

int randomNumber(int n, int m) { //random number method because it looks messy otherwise.
	srand(time(NULL));
	return(rand() % m + n);
}
