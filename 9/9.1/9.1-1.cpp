// Minimum and second minimum simultaneously in n + logn - 2 comparisons

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int minimum(int A[], int start, int end){
	if(start==end){
		return A[start];
	}
	else if(start-end==1){
		return min(A[start], A[end]);
	}
	else{
		int mid = (start+end) / 2;
		return min(minimum(A, start, mid),minimum(A, mid+1, end));
	}
}

int secondMin(int A[], int start, int end){
	int min = minimum(A, start, end);
	int smin = A[start];

	for(int i=start;i<=end;i++){
		if(A[i]<smin && A[i]>min){
			smin = A[i];
		}
	}
	return smin;
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

	cout << "Minimum: " << minimum(A,0,n-1) <<  endl;
	cout << "secondMin: " << secondMin(A,0,n-1) << endl;

	return 0;
}