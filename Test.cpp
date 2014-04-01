#include <iostream>
#include <string>

using namespace std;

void test(string c);
void separate();
int findFreq(string s);
void printArray(int arr[], int len);
int largest(int arr[], int len);

int main() {
	test("t");
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
	int pos[] = {0, 0, 0, 0};

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
