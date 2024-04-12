#include <iostream>

#define INT_MAX 2147483647;

using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	int max = 0;
	int min = INT_MAX;
	cin >> n;
	for(int i = 0; i < n; i++){
		int value;
		cin>>value;
		if(value > max) max = value;
		if(value < min) min = value;
	}
	printf("%d;%d", max, min);
	return 0;
}