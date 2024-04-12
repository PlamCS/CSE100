#include <iostream>
#include <stdlib.h>

using namespace std;

int partition(int* A, int p, int r){
	int pivot = A[r];
	int i = (p - 1);
	for(int j = p; j <= r-1; j++){
		if(A[j] <= pivot){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return (i + 1);
}

int randomPartition(int* A, int p, int r){
	int i = p + rand() % (r - p);
	swap(A[r], A[i]);
	return partition(A, p, r);
}

void randomQuickSort(int* A, int p, int r){
	if (p < r){
		int q = randomPartition(A, p, r);
		randomQuickSort(A, p, q-1);
		randomQuickSort(A, q+1, r);
	}
}

void printA(int* array, int n){
	for(int i = 0; i < n; i++){
		cout<<array[i]<<";";
	}
	// cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int* array = new int[n];
	for(int i = 0; i < n; i++){
		cin >> array[i];
	}
	// printA(array, n);

	randomQuickSort(array, 0, n - 1);

	printA(array, n);

	return 0;
}