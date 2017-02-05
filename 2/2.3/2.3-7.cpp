// Need to make this O(n) instead of O(n logn) -- other than merge sort

#include <iostream>
#include <math.h>
#include "sort.h"
using namespace std;

// <<<<<<<<<<<<<<<<If you just want a method/idea as to how to do it>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// To make the run time of this algorithm in O(n), keep two pointers on either side of the array and keep reducing 
// them on conditions till the time both of them are equal to the sum (x in this case)!

// DOCUMENTATION ABOVE ! ^o^
void sumx(int S[], int x, int n){

	int i=0, j=n-1;
	while(i<j){
		if(S[i]+S[j]==x){
		    cout << i << ", " << j << ", " << S[i] << " + " << S[j] <<  endl;
		    return 0;
		}
		else if(S[i]+S[j] != x){
		    if(S[j] > (x-S[i])){
			j--;
			continue;
		    }
		    if(S[i] < (x-S[j])){
			i++;
			continue;
		    }
		}
	}
	cout << "No two numbers sum to " << x << endl;
	return;
}

int main(){
	int n;
	cout << "No. of numbers "; 
	cin >> n;
	int k=n;
	int S[n];
	while(k){
		cin >> S[n-k];
		k--;
	}
	*S = merge_sort(S,0,n);

	int x;
	cout << "Required sum: ";
	cin >> x;
	sumx(S,x,k);
}
