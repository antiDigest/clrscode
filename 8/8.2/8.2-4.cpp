// Counting Sort

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int integersInRange(int A[], int n, int k, int a, int b){
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
	// for(int i=0;i<n;i++){
	// 	B[Next[A[i]]++] = A[i];
	// }

	// cout << "Integers in Range: "<< endl;
	// int l=a;
	// while(l<=b){
	// 	cout << B[l] << endl;
	// 	l++;
	// }
	return (Next[b] - Next[a-1]);
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

	int a,b;
	cout << "Range start: ";
	cin >> a;
	cout << "Range end: ";
	cin >> b;

	cout << "Integers in Range: "<< integersInRange(A, n, k, a, b) << endl;
	
	return 0;
}