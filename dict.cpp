/* Class that will contain dict class */

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

int Dict::reduceDisplay(string c, int p) {
	displayWord.replace(p, 1, c);
}

void Dict::getWords() { //Read in words to start
	string line;

	ifstream dict("dictionary");

	for(int i = 0; i < 45394; i++) {
		getline(dict, line);

		if(line.length() == wordLength && !checkForRepeat(line)) {
			wrds.push_back(line);
			size++;

		}

	}

}//getWords

void Dict::reduceWords(string s) {//
	int pos = findFreq(s);

	it = wrds.begin();
	cout << pos << " " << wordLength << endl;
	if(pos == wordLength) {
		for(int i = 0; it != wrds.end(); i++) { //needs looking at
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
	}

	else {
		for(int i = 0; it != wrds.end(); i++) { //needs looking at
			string w = *it;
			int t = w.find(s);

			if(t != pos) {
				it = wrds.erase(it);
				size--;
			}

			else {
				++it;
			} 

		}

		reduceDisplay(s, pos);

	}
	
	//reduceDisplay(s, pos);
	printVector(wrds);

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
	int temp = wordLength + 1;
	int pos[temp];
	for(int i = 0; i < temp; i++) {
		pos[i] = 0;
	}

	for(it = wrds.begin(); it != wrds.end(); ++it) {
		string w = *it;
		int i = w.find(s);
		if(i != string::npos) {
			pos[i]++;
		}
		else {
			pos[wordLength]++;
		}
	}

	int freq = largest(pos);

	for(int i = 0; i < temp; i++) {
		cout << pos[i] << " ";
	}

	cout << endl;

	return freq;
}//findFreq

int Dict::largest(int nums[]) {//added to h
	int most = 0;

	for(int i = 0; i < wordLength + 1; i++) {
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

string Dict::sample() {
	return wrds[0];
}
