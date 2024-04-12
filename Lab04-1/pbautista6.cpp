#include <iostream>
#include <cmath>

using namespace std;

void maxHeapify(int* A, int i, int n){
	int left = 2*i + 1;
	int right = 2*i + 2;
	int largest = i;

	if(left <= n && A[left] > A[largest]){
		largest	= left;
	}

	if(right <= n && A[right]> A[largest]){
		largest = right;
	}

	if(largest != i){
		swap(A[i], A[largest]);
		maxHeapify(A, largest, n);
	}
}

void buildMaxHeap(int* A, int size){
	for(int i = floor(size/2); i >= 0; i--){
		maxHeapify(A, i, size);
	}
}

void HeapSort(int* A, int size){
	buildMaxHeap(A, size);
	for(int i = size; i >= 1; i--){
		swap(A[0], A[i]);
		size--;
		maxHeapify(A, 0, size);
	}
}

void printA(int* array, int size){
	for(int i = 0; i < size; i++){
		cout << array[i] <<";";
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

	HeapSort(array, n - 1);
	
	printA(array, n);

	return 0;
}