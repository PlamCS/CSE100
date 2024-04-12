#include <iostream>

using namespace std;

void merge(int* array, int start, int mid, int end){
	int n1 = mid - start + 1;
	int n2 = end - mid;

	int* leftArray = new int[n1];
	int* rightArray = new int[n2];

	for(int i = 0; i < n1; i++){
		leftArray[i] = array[start + i];
	}

	for(int j = 0; j < n2; j++){
		rightArray[j] = array[mid + 1 + j];
	}

	int left = 0;
	int right = 0;
	int k = start;

	while(left < n1 && right < n2){
		if(leftArray[left] <= rightArray[right]){
			array[k] = leftArray[left];
			left++;
		}else{
			array[k] = rightArray[right];
			right++;
		}
		k++;
	}

	while(left < n1){
		array[k] = leftArray[left];
		left++;
		k++;
	}
	while(right < n2){
		array[k] = rightArray[right];
		right++;
		k++;
	}
	
}

void mergeSort(int* array, int start, int end){
	if(start < end){
		int mid = start + (end - start)/2;
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int* array = new int[n];
	for(int i = 0; i < n; i++){
		cin >> array[i];
	}

	mergeSort(array, 0, n - 1);

	for(int i = 0; i < n; i++){
		cout<<array[i]<<";";
	}

	return 0;
}