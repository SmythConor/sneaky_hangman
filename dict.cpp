/* Class that will contain dict class */

#include "dict.h"

Dict::Dict(int wordLength0) { //initialise Dict
	wordLength = wordLength0;
	size = 0;
	for(int i = 0; i < wordLength; i++) {
		displayWord += "_";
	}
}//dict

void Dict::getWords() { //Read in words to start
	string line; //var to get words

	ifstream dict("dictionary"); //file to read in

	for(int i = 0; i < 45394; i++) { //loop over all words
		getline(dict, line);

		if(line.length() == wordLength && !checkForRepeat(line)) { //No repeated letter and correct length
			wrds.push_back(line);
			size++;
		}

	}

}//getWords

bool Dict::checkForRepeat(string s) { //check for repeated letters
	string temp = s; //temp var to hold word

	for(int i = 0; i < wordLength - 1; i++) { //look for repeated letter
		char c = s.at(i);
		temp = s.substr(i + 1);
		if(temp.find(c) != string::npos) {
			return true;
		}

	}

	return false;
}//checkForRepeat

void Dict::reduceWords(string s) { //reduce the amount of words left in the dict
	int pos = findFreq(s); //find the positon it occurs the most, or not at all

	it = wrds.begin(); //initailise iterator

	if(pos == wordLength) { //if found in the most remove them words
		for(int i = 0; it != wrds.end(); i++) {
			string w = *it;
			int t = w.find(s);

			if(t != string::npos) {
				it = wrds.erase(it);
				size--;
			}

			else {
				++it;
			} 

		}
	}//

	else { //otherwise remove any word with that letter
		for(int i = 0; it != wrds.end(); i++) {
			string w = *it;
			int t = w.find(s);

			if(t != pos) {
				it = wrds.erase(it);
				size--;
			}

			else {
				++it;
			} 

		}//

		reduceDisplay(s, pos); //now reduce the display word

	}

}//reduceWords

int Dict::findFreq(string s) { //find frequency of char in each position
	int temp = wordLength + 1;
	int pos[temp]; //array to count the position
	for(int i = 0; i < temp; i++) {
		pos[i] = 0;
	}

	for(it = wrds.begin(); it != wrds.end(); ++it) { //check words for character position
		string w = *it;
		int i = w.find(s);
		if(i != string::npos) {
			pos[i]++; //increment relevant position
		}
		else {
			pos[wordLength]++; //otherwise not there
		}
	}

	int freq = largest(pos); //return largest positon

	return freq;
}//findFreq

int Dict::largest(int nums[]) { //returns largest in array
	int most = 0;

	for(int i = 0; i < wordLength + 1; i++) {
		if(nums[i] > most) {
			most = i;
		}

	}

	return most;
}//largest

int Dict::reduceDisplay(string c, int p) { //reduce the display word
	displayWord.replace(p, 1, c);
}//reduceDisplay

bool Dict::checkDict(string s) { //check the dict for the letter
	for(int i = 0; i < size; i++) {
		if(wrds[i].find(s) != string::npos) {
			return true;
		}
	}

	return false;
}//checkDict

string Dict::sample() { //return a sample word
	return wrds[0];
}//sample

void Dict::printWord() { //print the display word
	cout << displayWord << endl;
}//printWord
