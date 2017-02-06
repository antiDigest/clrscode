// Radix Sort

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int countingSort(int A[], int n, int k){
	int C[k+1];
	int Next[k+1];
	int B[n];

	for(int i=0;i<=k;i++){
		C[i] = 0;
	}
	for(int i=0;i<n;i++){
		C[A[i]]++;
	}
	Next[0] = 0;
	for(int i=1;i<=k;i++){
		Next[i] = C[i-1] + Next[i-1];
	}
	for(int i=0;i<n;i++){
		B[Next[A[i]]++] = A[i];
	}

	cout << "Sorted: "<< endl;
	int l=n;
	while(l){
		cout << B[n-l] << endl;
		l--;
	}
	return 0;
}

int main(){
	int n;
	cin >> n;
	int A[n];
	int k;
	cin >> k;
	int l;
	l=n;
	srand(time(NULL));

	cout << "Un-Sorted: "<< endl;
	while(l){
		A[n-l] = rand() % (k+1);
		cout << A[n-l] << endl;
		l--;
	}

	countingSort(A, n, k);
	
	return 0;
}