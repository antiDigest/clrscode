// Maximum Subarray Problem !


#include <cstdlib>
#include <ctime>
#include <iostream>
// #include "sort.h"
using namespace std;

int msa_n2(int A[], int n){
	int p[n+1];
	p[-1] = 0;
	int maxi = 0, maxj = 0, maxsum = 0, sum=0;

	for (int i = 0; i < n; i++){
		p[i] = p[i-1] + A[i];
	}

	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
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
	cin >> n;
	int A[n];
	int l;
	l=n;

	cout << "Numbers: "<< endl;
	while(l){

		A[n-l] = rand() % (50+1)-25;
		cout << A[n-l] << endl;
		l--;
	}
	msa_n2(A,n);
	return 0;
}