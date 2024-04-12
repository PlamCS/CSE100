#include <iostream>
#include <cmath>

#define INT_MIN -2147483647

using namespace std;

void printArray(int* array, int size){
	cout<<"[";
	for(int i = 1; i < size+1; i++){
		cout<<i<<"\t";
	}
	cout<<"]"<<endl;
	cout<<"[";
	for(int i = 0; i < size; i++){
		cout<<array[i]<<"\t";
	}
	cout<<"]"<<endl;
}

int maxRevenue(int* array, int* revenues,int* cuts, int size){
	revenues[0] = 0;

	for (int i = 1; i <= size; i++){
       	int value = INT_MIN;
       	for (int  j = 0; j < i; j++)
       		if(value < array[j] + revenues[i-j-1]){
       			value = array[j] + revenues[i-j-1];
       			cuts[i] = j+1;
       		}
       	revenues[i] = value;
    }
 
   return revenues[size];
}

void printPath(int* revenues, int* cuts, int size){
	int i = size;
	while(i > 0){
		cout<<cuts[i]<<" ";
		i -= cuts[i];
	}
	cout<<"-1"<<endl;
}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	
	int* array = new int[n];
	for(int i = 0; i <= n; i++){
		cin >> array[i];
	}
	int* revenues = new int[n+1];
	for(int i = 0; i <= n; i++){
		revenues[i] = 0;
	}
	int* cuts = new int[n+1];
	for(int i = 0; i <= n; i++){
		cuts[i] = 0;
	}

	// printArray(array, n);
	cout<<maxRevenue(array, revenues, cuts, n)<<endl;
	// printArray(revenues, n);
	// printArray(cuts, n);
	// cout<< n - 1 << "\tCuts: " << cuts[n - 1]<<endl;

	printPath(revenues, cuts, n);
	return 0;
}