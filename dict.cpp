/* Class that will contain dict class */

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "dict.h"

using namespace std;

Dict::Dict(int wordLength0) {//added to h
	wordLength = wordLength0;
	size = 0;
}//dict

void Dict::reduceWords(string s) {//added to h
	string line;
	int pos = findFreq(s);
	
	cout << "before if" << endl;

	if(size == 0) {//first run
		ifstream dict("dictionary");
		for(int i = 0; i < 45394; i++) {
			getline(dict, line);
			if(line.find(s) == pos && line.length() == wordLength) {
				wrds.push_back(line);
				size++;
			}

		}
		
		cout << "size: " <<size << endl;
		printVector(wrds);
	}

	else {//other runs
		vector<string>::iterator it = wrds.begin();
		for(int i = 0; i < size; i++, it++) { //needs looking at
			if(wrds[i].find(s) == pos) {//deletes the word if character not there
				wrds.erase(it);
				size--;
			}

		}
		cout << size << endl;
		printVector(wrds);
	}

}//reduceWords

int Dict::findFreq(string s) {//added to h
	int pos[] = {0,0,0,0};
	int k = 0;
	string line;
	
	if(size == 0) {
		ifstream dict("dictionary");

		for(int i = 0; i < 45394; i++) {
			getline(dict, line);
			if((line.find(s) == k) && (k <= wordLength)) {
				pos[k]++;
			}

			else if(k > wordLength) {
				i = 45395;
			}

			else if(i == 45394)  {
				i = 0;
				k++;
			}
		}
	}

	else {
		for(int i = 0; i < size; i++) {
			if(wrds[i].find(s) == k && k <= wordLength) {
				pos[k]++;
			}

			else if(i == (size - 1)) {
				i = 0;
				k++;
			}

			else if(k > wordLength) {
				i = (size + 1);
			}
		}
	}

	int freq = largest(pos);

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
	cout << "[";
	for(int i = 0; i < size; i++) {
		if(i == (size - 1)) {
			cout << s[i];
		}

		else {
			cout << s[i] << ", ";
		}

	}

	cout << "]" << endl;
}
