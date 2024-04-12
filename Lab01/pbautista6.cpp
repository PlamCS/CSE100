#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int* array;
	int n;
	cin >> n;
	array = new int[n];

	for(int i = 0; i < n; i++){
		cin >> array[i];
	}
	if(n > 1){
		for(int i = 0; i < n - 1; i++){
			int j = i + 1;
			for(j; j > 0; j--){
				if(array[j] < array[j - 1]){
					swap(array[j], array[j - 1]);
				}
			}
			for(int k = 0; k <= i + 1; k++){
				printf("%d;", array[k]);
			}
			printf("\n");
		}
	}
	return 0;
}
