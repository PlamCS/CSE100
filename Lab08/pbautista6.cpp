#include <iostream>
#define INT_MAX 2147483647

using namespace std;

void printSol( int i, int j, int size, int** s){
	if(i == j){
		printf("A%d", i - 1);
		return;
	}
	else{
		printf("(");
		printSol(i, s[i][j], size, s);
		printSol(s[i][j] + 1, j, size, s);
		printf(")");
	}
}

int matrixChainOrder(int* arr,int size){
	// for(int i = 0; i <= size; i++){
	// 	printf("%d ", arr[i]);
	// }
	int m[size][size];
	int** s = new int*[size];
	for(int i = 0; i < size; i++){
		s[i] = new int[size];
	}

	for (int i = 1; i < size; i++){
		m[i][i] = 0;
	}
	// cout<<"multiplying"<<endl;
	for(int l = 2; l < size; l++){
		for(int i = 1; i < size - l + 1; i++){
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for(int k = i; k <= j - 1; k++){
				int q = m[i][k] + m[k + 1][j]+arr[i - 1]*arr[k]*arr[j];
				
				// printf("%d < %d\n", q, m[i][j]);
				if(q < m[i][j]){
					// printf("Found");
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout<<m[1][size - 1]<<endl;
	printSol(1, size - 1, size, s);
	return m[1][size - 1];
}

void printArray(int** array, int size){
	for(int i = 0; i <= size; i++){
		printf("[");
		for(int j = 0; j <= size; j++){
			printf("%d ",array[i][j]);
		}
		printf("]");
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	// cout<<n<<endl;
	int array[n];
	for(int i = 0; i <= n; i++){
		cin>>array[i];
	}
	// for(int i = 0; i <= n; i++){
	// 	printf("%d ", array[i]);
	// }
	// cout<<endl;
	// int** m = new int*[n];
	// for(int i = 0; i < n; i++){
	// 	m[i] = new int[n];
	// }
	// int** s = new int*[n];
	// for(int i = 0; i < n; i++){
	// 	s[i] = new int[n];
	// }
	matrixChainOrder(array, n+1);
	cout<<endl;
	// cout<<matrixChainOrder(array, m, s, n+1)<<endl;
	// printArray(m, n);
	// cout<<endl;
	// printArray(s, n);
	// cout<<endl;
	
	return 0;
}