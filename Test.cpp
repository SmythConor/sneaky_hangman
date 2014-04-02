#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test(string c);
void separate();
int findFreq(string s);
void printArray(int arr[], int len);
int largest(int arr[], int len);
void vectorTest();
void printvector(vector<string> s, int l);

int main() {
	//vectorTest();
	test("e");
}

void vectorTest() {
	vector<string> wrds;
	int size = 0;
	int k = 97;
	for(int i = 0; i < 10; i++) {
		string w = "";
		w += k;
		wrds.push_back(w);
		size++;
		k++;
	}

	printvector(wrds, size);

	string c = "j";
	vector<string>::iterator it = wrds.begin();

	for(int i = 0; i < size; i++, it++) {
	string temp = wrds[i];
		if(temp.find(c) != string::npos) {
			wrds.erase(it);
			size--;
		}

	}

	printvector(wrds, size);
}

void printvector(vector<string> s, int l) {
	cout << "[";
	for(int i = 0; i < l; i++) {
		if(i == (l - 1)) {
			cout << s[i] << "]";
		}

		else {
			cout << s[i] << ", ";
		}

	}

	cout << endl;
}

void test(string c) {
	string temp = "test";
	if(temp.find("e") != string::npos) {
		cout << "First test should return: [1,0,0,0], 0" << endl;
		int temp = findFreq(c);
		cout << temp;
		cout << endl;
	}
	else {
		cout << "Not in string" << endl;
	}

}

void printArray(int arr[], int len) {
	cout << "[";
	for(int i = 0; i < len; i++) {
		if(i == (len -1 )) {
			cout << arr[i];
		}
		else {
			cout <<  arr[i] << ",";
		}
	}

	cout << "], ";
}

void separate() {
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
}

int findFreq(string c) {
	string s = "test";
	int wordLength = 4;
	int pos[wordLength];
	for(int i = 0; i < wordLength; i++) {
		pos[i] = 0;
	}

	for(int k = 0; k <= wordLength; k++) {
		if((s.find(c) == k) && (k <= wordLength)) {
			pos[k]++;
		}

	}

	int freq = largest(pos, wordLength);
	printArray(pos, wordLength);
	return freq;

}

int largest(int nums[], int len) {
	int most = 0;

	for(int i = 0; i < len; i++) {
		if(nums[i] > most) {
			most = i;
		}

	}

	return most;
}
