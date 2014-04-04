/* Conor Smyth 12452382
 * Normal hangman main class
 * Includes sneaky hangman
 * Assuming valid input
 * All work is my own
 */

#include "hangman.h"
#include "dict.h"

//using namespace std;

/* method headers */

int guesses = 6; //global guesses never changes
void simple(); //call simple hangman game
void sneaky(); //call sneaky hangman game
string getWord(); //get a word for simple game
int randomNumber(int n, int m); //cleaner generate random number
bool cont(int i, int k); //condition to dictate progress in game
void welcome(); //welcoming message
void displayGuesses(int g); //display guesses
void prompt(); //ask user for a character
void separate(); //separation for formatting
bool endMessage(int n); //which message to display to user at end win/loss


int main() { //main
	//simple();
	sneaky();
}//main

void sneaky() {
	int len = randomNumber(4, 7); //get a random word length
	Hangman h(len); //create hangman
	Dict d(len); //create dictionary
	string line; //line to read in with
	welcome(); //welcome message
	d.getWords(); //get words into dictionary

	while(cont(guesses, len)) { //continue or not
		displayGuesses(guesses); //show user remaining guesses
		prompt(); //ask user for character
		d.printWord(); //print out the word in underscores for user

		h.getChar();//getChar

		line = h.returnChar();//get char from hangman

		if(h.validate()) { //check if already guessed
			h.alreadyGuessed();
		}

		else { //not already guessed so procede
			d.reduceWords(line); //reduce the words available

			if(d.checkDict(line)) { //check for the char in dictionary
				h.charFound();
				len--;
			}

			else { //not found
				h.charNotFound();
				guesses--;
			}
		}

		separate(); //formatting separation

	}

	string w = d.sample(); //give a sample word to display
	h.getWord(w);

	if(endMessage(guesses)) { //win, show remaining guesse(s) and the word
		h.win(guesses);
	}

	else { //lose, show word and hard luck message
		h.lose();
	}

}//sneaky

void simple() {
	string line = getWord(); //get word from dictionary file
	Hangman h(line); //create hangman
	int len = h.wordLength(); //length of word
	int num = 0; //temp variable

	welcome(); //welcome message

	while(cont(guesses, len)) { //continue or not
		displayGuesses(guesses); //display guesses left
		h.pw(); //print word in underscoes
		prompt(); //ask user for character
		h.getChar();//print out if they were correct

		int t = h.checkForChar(); //check the word for the character

		if(t == 0) { //check if already guessed
			h.alreadyGuessed();
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

		separate(); //formatting

	}

	if(endMessage(guesses)) { //win message
		h.win(guesses);
	}

	else { //loss message
		h.lose();
	}

}//simple

string getWord() { //read in a random word from dictionary file
	ifstream dict("dictionary"); //take in file
	string line; //var to read in words
	int randWord = randomNumber(1, 45394); //random word to return

	for(int i = 1; i < randWord; i++) { //get random word at randWord
		getline(dict, line);
	}

	return line; //return the word
}//getWord

int randomNumber(int n, int m) { //random number method because it looks messy otherwise.
	srand(time(NULL));
	return(rand() % m + n);
}//randomNumber

void welcome() { //welcoming messsage
	cout << "Welcome to hangman!" << endl;
}//welcome

void displayGuesses(int g) { //display remaining guesses
	cout << "You have " << g << " guess(s) left." << endl;
}//displayGuesses

void prompt() { //ask for char
	cout << "Place enter a character: " << endl;
}//prompt

bool cont(int i, int k) { //win/loss conditions for gueses
	return i > 0 && k > 0;
}//cont

void separate() {
	cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}//separate

bool endMessage(int n) { //decide which message to give
	return n > 0;
}//endMessage
