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
	int start = 0;
	int end = data.size() - 1;
    int mid;
	while(start < end){
		mid = (start + end) / 2;
		if(search_number <= data[mid]) end = mid;
		else start = mid + 1;
	}
    if(data[start] != search_number) return -1;
	return start;
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