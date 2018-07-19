#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct node{
	int data;
	node *leftChild;
	node *rightChild;
	node(int _data, node *_leftChild, node *_rightChild) {
		data = _data;
		leftChild = _leftChild;
		rightChild = _rightChild;
	}
};
vector<int> horizontal_traversal(node *root) {
	// Implement Here
    vector<int> result;
    if(root == NULL) return result;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* current_node = q.front();
        q.pop();
        result.push_back(current_node->data);
        if(current_node->leftChild != NULL) q.push(current_node->leftChild);
        if(current_node->rightChild != NULL) q.push(current_node->rightChild);
    }
    return result;
}

string checkAnswer(vector<int> correctAnswer, vector<int> answer);
string test1();
string test2();

int main() {
	cout << test1() << endl;
	cout << test2() << endl;
}
string checkAnswer(vector<int> correctAnswer, vector<int> answer) {

	if(answer.size() != correctAnswer.size()) return "Wrong";
	for(int i=0;i < correctAnswer.size();i++) {
		if(correctAnswer[i] != answer[i])
			return "Wrong";
	}
	return "Correct";
}

string test1() {
	node *root = new node(1, 
						  new node(2, 
						  		   new node(3, NULL, NULL), 
						  		   new node(4, NULL, NULL)),
						  new node(5,
						  		   new node(6, NULL, NULL),
						  		   NULL));
	vector<int> correctAnswer{1, 2, 5, 3, 4, 6};
	vector<int> answer = horizontal_traversal(root);
	return checkAnswer(correctAnswer, answer);
}
string test2() {
	node *root = new node(1, 
						  new node(2, 
						  		   new node(3, 
						  		   			new node(4, NULL, NULL),
						  		   			NULL), 
						  		   NULL),
						  NULL);
	vector<int> correctAnswer{1, 2, 3, 4};
	vector<int> answer = horizontal_traversal(root);
	return checkAnswer(correctAnswer, answer);
}