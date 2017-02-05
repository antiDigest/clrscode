// Minimum and second minimum simultaneously in n + logn - 2 comparisons

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int minimum(int A[]){
	
}

int main(){
	int n, k;
	cin >> n;
	int A[n];
	k=n;

	srand(time(NULL));

	cout << "Numbers:" << endl;

	while(k){
		A[n-k] = rand() % n+1;
		cout << A[n-k] << endl;
		k--;
	}

	minmax(A,n);

	return 0;
}