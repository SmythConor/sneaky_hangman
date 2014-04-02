/* Conor Smyth 12452382
 * Normal Hangman class 
 * All work is my own
 */

#include <vector>
#include <sstream>
#include <fstream>

#include <iostream>
#include <stdlib.h>
#include <string>
#include "hangman.h"

using namespace std;

Hangman::Hangman(int l) {
	for(int i = 0; i < l; i++) {
		displayWord += "_";
	}
}//added to h

Hangman::Hangman(string w1) { //initailise Hangman added to h
	word = w1;
	for(int i = 0; i < word.length(); i++) { //display underscores for users
		displayWord += "_";
	}
}//Hangman added to h

void Hangman::giveWord(string s) {
	word = s;
}//giveWord added to h

void Hangman::getChar() { //reads in char
	bool corr = true;
	while(corr) {
		cin >> c;
		if(c.length() > 1) {
			cout << "Please enter only one character." << endl;
		}
		else {
			corr = false;
		}
	}
}//getChar added to h

bool Hangman::validate() {
	if(store.find(c) != string::npos) {
		return true;
	}
	store +=c;
	return false;
}

int Hangman::checkForChar() { //check for char in string
	int t = store.find(c); //store entered chars

	store += c;

	if(t != string::npos) { //check if char already entered
		return 0; //0 for already guessed
	}

	t = word.find(c);

	if(t < 0) { // If character not there
		return -1; //-1 for not there
	}

	return 1; //1 for char existance
}//checkForChar added to h

void Hangman::alreadyGuessed() { //print that char was already guessed
	cout << "Character already guessed!" << endl;
}//alreadyGuessed added to h

void Hangman::charFound() { //print that char was found
	cout << "Character found!" << endl;
}//charFound added to h

string Hangman::returnChar() {
	return c;
}//returnChar added to h

int Hangman::numFound() { //find the number of times char was found
	string s = word; //temp varialbe for word
	int count = 0; //count for number of instances
	bool con = true;
	size_t temp;

	while(con) {
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
}//numFound added to h

int Hangman::wordLength() { //return word length
	return word.length();
}//wordLength added to h

void Hangman::charNotFound() { //warn char not found
	cout << "Character not found." << endl;
}//charNotFound added to h

void Hangman::lose() { //loss message
	cout << "Out of guesses hard luck." << endl;
	cout << "The word was " << word << endl;
}//lose added to h

void Hangman::win(int g) { //win message
	cout << "Congratulations you have won!" << endl;
	cout << "You had " << g << " guesses left!"<< endl;
	cout << "The word was " << word << endl;
}//win added to h

void Hangman::pw() { //print out the underscores for user
	//cout << word << endl;
	cout << displayWord << endl;
}//pw added to h
