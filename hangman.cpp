/* Conor Smyth 12452382
 * Normal Hangman class 
 * Now includes some sneaky features
 * All work is my own
 */

#include "hangman.h"

Hangman::Hangman(int l) { //initialise hangman
	for(int i = 0; i < l; i++) { //fill display word
		displayWord += "_";
	}
}//Hangman

Hangman::Hangman(string w1) { //initailise Hangman
	word = w1;
	for(int i = 0; i < word.length(); i++) { //display underscores for users
		displayWord += "_";
	}
}//Hangman

int Hangman::wordLength() { //return word length
	return word.length();
}//wordLength

void Hangman::pw() { //print out the underscores for user
	cout << displayWord << endl;
}//pw

void Hangman::getChar() { //reads in char
	bool corr = true;
	while(corr) { //makes sure one char only
		cin >> c; //read in
		if(c.length() > 1) { //ensure length == 1
			cout << "Please enter only one character." << endl; //show warning
		}
		else {
			corr = false;
		}
	}
}//getChar

int Hangman::checkForChar() { //check for char in string
	int t = store.find(c); //store entered chars

	store += c;

	if(t != string::npos) { //check if char already entered
		return 0; //0 for already guessed
	}

	t = word.find(c); //check if in word

	if(t < 0) { // If character not there
		return -1; //-1 for not there
	}

	return 1; //1 for char existance
}//checkForChar

void Hangman::charNotFound() { //warn char not found
	cout << "Character not found." << endl;
}//charNotFound

bool Hangman::validate() { //validate
	if(store.find(c) != string::npos) { //checks if in string
		return true;
	}
	store +=c; //if not add to store and return false
	return false;
}//validate

void Hangman::alreadyGuessed() { //print that char was already guessed
	cout << "Character already guessed!" << endl;
}//alreadyGuessed

void Hangman::charFound() { //print that char was found
	cout << "Character found!" << endl;
}//charFound

int Hangman::numFound() { //find the number of times char was found
	string s = word; //temp varialbe for word
	int count = 0; //count for number of instances
	bool con = true;
	size_t temp;

	while(con) { //in case repeated letters
		temp = s.rfind(c);

		if(temp == string::npos) { //char not there anymore
			break;
		}
		else if(temp != string::npos) { //show char in display for user
			displayWord.replace(temp, 1, c);
			count++; //increment amount of instances
		}

		s.erase(temp,1); //remove found letter

		temp = 0;

	}

	return count; //return number of instances of char
}//numFound

void Hangman::win(int g) { //win message
	cout << "Congratulations you have won!" << endl;
	cout << "You had " << g << " guesses left!"<< endl;
	cout << "The word was " << word << endl;
}//win

void Hangman::lose() { //loss message
	cout << "Out of guesses hard luck." << endl;
	cout << "The word was " << word << endl;
}//lose

string Hangman::returnChar() { //returns the char read in
	return c;
}//returnChar


void Hangman::getWord(string s) { //gets a word
	word = s;
}//getWord
