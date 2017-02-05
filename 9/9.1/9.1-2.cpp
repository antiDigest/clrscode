// Minimum and maximum simultaneously in 3n/2 comparisons

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int minmax(int A[], int n){
	int min = A[1];
	int max = A[1];

	for(int i=0;i<n;i+=2){
		if(A[i]>A[i+1]){
			if(A[i]>max)
				max = A[i];
			if(A[i+1]<min)
				min = A[i+1];
		}
		else{
			if(A[i+1]>max)
				max = A[i+1];
			if(A[i]<min)
				min = A[i];
		}
	}

	cout << "max: "<< max << endl;
	cout << "min: "<< min << endl;

	return 0;
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