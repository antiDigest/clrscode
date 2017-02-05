// Maximum Subarray Problem !

#include <iostream>
// #include "sort.h"
using namespace std;

int msa_n2(int A[], int n){
	int p[n+1];
	p[0] = 0;
	int maxi = 0, maxj = 0, maxsum = 0, sum=0;

	for (int i = 1; i <= n; i++){
		p[i] = p[i-1] + A[i];
	}

	for (int i = 1; i <= n; i++){
		for (int j = i+1; j < n; j++){
			sum = p[j] - p[i-1];
			if (sum > maxsum){
				maxsum = sum;
				maxi = i;
				maxj = j;
			}
		}
	}

	cout << "Max Subarray lies between: " << maxi << " and " << maxj << " and the sum is " << maxsum << endl;
}

int main(){
	
	int n;
	cout << "No. of numbers "; 
	cin >> n;
	int k=n;
	int A[n+1];
	while(k){
		cin >> A[n-k+1];
		k--;
	}
	msa_n2(A,n);
	return 0;
}