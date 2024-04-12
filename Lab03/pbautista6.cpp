#include <iostream>

#define INT_MIN -2147483647;

using namespace std;

int maxSubarray(int* array, int start, int end){
	if(start>end){
		return INT_MIN;
	}
	int mid = (start+end)/2;
	int sumLeft = 0;
	int sumRight = 0;
	for(int i = mid - 1, sum = 0; i >= start; i--){
		sum += array[i];
		sumLeft = max(sumLeft, sum);
	}
	for(int j = mid + 1, sum = 0; j <= end; j++){
		sum += array[j];
		sumRight = max(sumRight, sum);
	}
	return max(max(maxSubarray(array, start, mid - 1), maxSubarray(array, mid + 1, end)), sumLeft + array[mid] + sumRight);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int* array = new int[n];
	for(int i = 0; i < n; i++){
		cin >> array[i];
	}

	// Look for Max Subarray
	cout<<maxSubarray(array, 0, n - 1);

	return 0;
}