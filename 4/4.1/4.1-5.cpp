// Maximum Subarray Problem !

#include <iostream>
#include <vector>
// #include "sort.h"
using namespace std;

int msa_n(int A[], int n){
	int p[n+1];
	p[0] = 0;
	int maxi = 0, maxj = 0, maxsum = 0, sum=0;

	for (int i = 1; i <= n; i++){
		p[i] = p[i-1] + A[i];
	}

	for(int i=1;i<n;i++){
		sum = p[i]-p[maxi];
		if(sum > maxsum){
			maxj = i;
			maxsum = p[maxj]-p[maxi];
		}
		else if(sum <= 0){
			maxj = i;
			maxi = i;
		}
	}

	cout << "Max Subarray lies between: " << maxi << " and " << maxj << " and the sum is " << maxsum << endl;

}

int main(){
	
	int n;
	cout << "No. of numbers "; 
	cin >> n;
	int k=n;
	int A[n];
	while(k){
		cin >> A[n-k+1];
		k--;
	}

	msa_n(A,n);

	return 0;
}