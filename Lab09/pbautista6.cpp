#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int n = 6;
const char letters[n] = {'A','B','C','D','E','F'};

struct Node
{
	char letter;
	int freq;
	Node* left;
	Node* right;

	Node(char letter, int freq){
		this->letter = letter;
		this->freq = freq;
		left = right = nullptr;
	}
};

struct comparing
{
	bool operator()(Node* left, Node* right){
		return left->freq > right->freq;
	}
};

void printValues(Node* root, char letter, string value){
	if(root){
		if(root->letter == letter){
			cout<<root->letter<<":"<<value<<endl;
		}
		printValues(root->left, letter, value + '0');
		printValues(root->right, letter, value + '1');
	}
}

void huffman(int frequency[]){
	Node* left;
	Node* right; 
	Node* top;
	priority_queue<Node*, vector<Node*>, comparing> minHeap;
	for(int i = 0; i < n; i++){
		minHeap.push(new Node(letters[i], frequency[i]));
	}

	while(minHeap.size() != 1){
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new Node('.', left->freq + right->freq);
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	for(int i = 0; i < n; i++){
		printValues(minHeap.top(), letters[i], "");
	}
}

int main(int argc, char const *argv[])
{
	int freq[n];
	for(int i = 0; i < n; i++){
		cin>>freq[i];
	}

	huffman(freq);

	return 0;
}