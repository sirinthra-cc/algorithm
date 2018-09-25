#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int binary_search(vector<int> data, int search_number) {
	// Implement Here
	// return index
	// If not found, return -1
	// If found many, return the first index
	// find 1
	// [ 0 1 2 3 4 ]
	//   f   m   l
	// [ 0 1 2 3 4 ]
	//   f m l

	// find 4
	// [ 0 1 2 3 4 5 ]
	//   f   m     l
	// [ 0 1 2 3 4 5 ]
	//         f m l
	int first = 0;
	int last = data.size() - 1;
	int mid;
	while(first < last){
		mid = (first + last) / 2;
		if(data[mid] < search_number) first = mid + 1;
		else last = mid;
	}
	if(data[first] != search_number) return -1;
	return first;
}

string checkAnswer(vector<int> correctAnswer, vector<int> answer);
string test();

int main() {
	for(int i=0;i<100;i++) {
		cout << test() << endl;
	}
}
string checkAnswer(int correctAnswer, int answer) {

	if(correctAnswer == answer)
		return "Correct";
	return "Wrong";
}

string test() {
	int _size = rand() % 1000000;
	vector<int> data;
	for(int i=0;i<_size;i++){
		int inc = rand() % 3;
		if(data.size() == 0) data.push_back(inc);
		else data.push_back(data[data.size() - 1] + inc);
	}
	int wanted_number = rand() % data[data.size() - 1];
	int correct_index = 0;
	for(; correct_index<_size;correct_index++){
		if(data[correct_index] == wanted_number)
			break;
	}
	if(data[correct_index] != wanted_number)
		correct_index = -1;
 	return checkAnswer(correct_index, binary_search(data, wanted_number));
}