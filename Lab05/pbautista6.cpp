#include <iostream>

using namespace std;

//3, 2, 1, 1, 2 -> 1, 1, 2, 2, 3
//0, 0, 2, 1, 3 -> 0, 0, 1, 2, 3

// int findMax(int** array, int size){
// 	int maxIndex = 0;
// 	int maxVal = 0;
// 	for(int i = 0; i < size; i++){
// 		int currMax = 0;
// 		for(int j = 0; j < 10; j++){
// 			currMax+=array[i][j];
// 		}
// 		if(currMax > maxVal){
// 			maxIndex = i;
// 			maxVal = currMax;
// 		}
// 	}
// 	return maxIndex;
// }

void printArray(int** array, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < 10; j++){
			cout<<array[i][j]<<";";
		}
		// if(i < size - 1){
		cout<<endl;
		// }
		
	}
}

void countSort(int** array, int j, int size){
	int* count = new int[4];
	for(int i = 0; i < size; i++){
		count[array[i][j]]++;
	}

	// for(int i = 0; i < 4; i++){
	// 	cout<<count[i]<<";";
	// }
	// cout<<endl;

	for(int i = 1; i < 4; i++){
		count[i] += count[i- 1];
	}

	// for(int i = 0; i < 4; i++){
	// 	cout<<count[i]<<";";
	// }
	// cout<<endl;

	int** newArray = new int*[size];
	for(int i = size - 1; i >= 0; i--){
		newArray[count[array[i][j]] - 1] = array[i];
		count[array[i][j]]--;
	}

	for(int i = 0; i < size; i++){
		array[i] = newArray[i];
	}
}

void radixSort(int** array, int size){
	// countSort(array, 0, size);
	// countSort(array, 1, size);
	for(int i = 9; i >= 0 ; i--){
		countSort(array, i, size);
	}

	// int* count = new int[size];
	// for(int i = 0; i < size; i++){
	// 	int counter = 0;
	// 	for(int j = 0; j < 10; j++){
	// 		counter += array[i][j];
	// 	}
	// 	count[counter%10] = i;
	// }

	// for(int i = 0; i < size; i++){
	// 	cout<<count[i]<<";";
	// }
	// cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int** array = new int*[n];

	for(int i = 0; i < n; i++){
		int* row = new int[10];
		for(int j = 0; j < 10; j++){
			cin >> row[j];
		}
		array[i] = row;
	}

	// printArray(array, n);

	radixSort(array, n);

	printArray(array, n);
	// cout<< findMax(array, n)<<endl;

	return 0;
}