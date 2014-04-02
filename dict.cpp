/* Class that will contain dict class */

#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "dict.h"

using namespace std;

Dict::Dict(int wordLength0) {//added to h
	wordLength = wordLength0;
	size = 0;
	for(int i = 0; i < wordLength; i++) {
		displayWord += "_";
	}
}//dict

void Dict::printWord() {
	cout << displayWord << endl;
}

int Dict::reduceDisplay(string c) {
	//cout << "start reduceDisplay" << endl;
	//it = wrds.begin();
	//cout << *it << endl;
	printVector(wrds);
	string s = wrds[0]; /****** Here *******/
	//cout << "just after sample word" << endl;
	int count = 0;
	bool con = true;
	size_t temp;

	//cout << "just before reduceDisplay loop" << endl;

	while(con) {
		temp = s.rfind(c);

		if(temp == string::npos) {
			break;
		}

		else if(temp != string::npos) {
			displayWord.replace(temp, 1, c);
			count++;		}

		s.erase(temp, 1);

		temp = 0;
	}

	return count;

}

void Dict::reduceWords(string s) {//added to h
	string line;
	int pos = findFreq(s);

	if(size == 0) {//first run
		ifstream dict("dictionary");
		for(int i = 0; i < 45394; i++) {
			getline(dict, line);
			if(line.length() == wordLength && !checkForRepeat(line)) {
				if(line.find(s) == pos) {
					wrds.push_back(line);
					size++;
				}
			}

		}

		//printVector(wrds);
	}

	else if(size == 2) {

	}

	else {//other runs
		//cout << "start" << endl;
		it = wrds.begin();
		//cout << "just before loop" << endl;
		for(int i = 0; it != wrds.end(); i++) { //needs looking at
			string w = *it;
			int t = w.find(s);

			//cout << "out t: " << t << " pos: " << pos << endl;

			if(((t != string::npos) &&  (t != pos)) || (t < 0)) {//deletes the word if character there but in wrong position
				//cout << "in t: " << t << " pos: " << pos << endl;
				wrds.erase(it);
				size--;
			}
			else {
				++it;
			} 

		}

		//printVector(wrds);
	}

	//cout << "SIZE: "<< size << endl;
}//reduceWords

bool Dict::checkForRepeat(string s) {
	string temp = s;

	for(int i = 0; i < wordLength - 1; i++) {
		char c = s.at(i);
		temp = s.substr(i + 1);
		if(temp.find(c) != string::npos) {
			return true;
		}

	}

	return false;
}

int Dict::findFreq(string s) {//added to h
	//cout << "start findFreq" << endl;
	int pos[wordLength];
	for(int i = 0; i < wordLength; i++) {
		pos[i] = 0;
	}
	//makes here
	int k = 0;
	string line;

	it = wrds.begin();
	//makes here
	//word length is correct
	while(k < wordLength) {
		for(int i = 0; it != wrds.end(); i++, ++it) {
			string w = *it;
			//word is correct
			if(w.find(s) == k && k <= wordLength) {
				pos[k]++;
			}
			//makes
		}
		k++;
		it = wrds.begin();
	}

	//for(int i = 0; i < wordLength; i++) {
	//	cout << pos[i] << endl;
	//}

	int freq = largest(pos);

	//cout << "largest " << freq << endl;

	return freq;
}//findFreq

int Dict::largest(int nums[]) {//added to h
	int most = 0;

	for(int i = 0; i < wordLength; i++) {
		if(nums[i] > most) {
			most = i;
		}

	}

	return most;
}//largest

bool Dict::checkDict(string s) {
	for(int i = 0; i < size; i++) {
		if(wrds[i].find(s) != string::npos) {
			return true;
		}
	}

	return false;
}

string Dict::sample() {//added to h
	return wrds[0];
}//sample


void Dict::printVector(vector<string> s) {
	it = wrds.begin();
	cout << "[";
	for(int i = 0; it != wrds.end(); i++, it++) {
		if(i == (size - 1)) {
			//cout << s[i];
			cout << *it << "]";
		}

		else {
			//cout << s[i] << ", ";
			cout << *it << ", ";
		}

	}

	cout << endl;
}
