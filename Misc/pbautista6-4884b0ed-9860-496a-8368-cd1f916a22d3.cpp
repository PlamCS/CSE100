#include <iostream>
#include <string>
#include <list>

using namespace std;

struct hashTable{
public:
	int m;
	list<int>* hash;

	hashTable(int bucketSize){
		m = bucketSize;
		hash = new list<int>[bucketSize];
	} 

	void insert(int key){
		hash[index(key)].push_front(key);
	}

	void del(int key){
		for(auto it = hash[index(key)].begin(); it != hash[index(key)].end(); it++){
			if(*it == key){
				hash[index(key)].erase(it);
				cout<<key<<":DELETED";		
				return;
			}
		}
		cout<<key<<":DELETE_FAILED";
	}

	void search(int key){
		int j = 0;
		for(auto it = hash[index(key)].begin(); it != hash[index(key)].end(); it++){
			if(*it == key){
				cout<<key<<":FOUND_AT"<<index(key)<<","<<j;		
				return;
			}
			j++;
		}
		cout<<key<<":NOT_FOUND";
	}

	void print(){
		for(int i = 0; i < m; i++){
			list<int> link = hash[i];
			cout<<i<<":";
			for(auto it: link){
				cout<<it<<"->";
			}
			cout<<';'<<endl;
		}
	}

	int index(int value){
		return value%m;
	}

};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	hashTable hash = hashTable(n);

	string input;
	cin>>input;
	char argument = input[0];
	string value = input.substr(1, input.size());

	while(argument != 'e'){
		if(argument == 'o'){
			hash.print();
		}else{
			if(argument == 'i'){
				hash.insert(stoi(value));
			}else if(argument == 'd'){
				hash.del(stoi(value));
				cout<<';'<<endl;
			}else if(argument == 's'){
				// hash.print();
				hash.search(stoi(value));
				cout<<';'<<endl;
			}
		}

		cin>>input;
		argument = input[0];
		value = input.substr(1, input.size());
	}

	return 0;
}