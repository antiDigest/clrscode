// Deterministic Select

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "sort.h"

using namespace std;

int A[10000];

int insertionSortIndex(int K[], int start, int end, int index){
	int i,j, key;

	for(j=start+1;j<=end;j++){
		key = K[j];
		i = j-1;
		while(i>=start && K[i]<key){
			K[i+1] = K[i];
			i = i-1;
			K[i+1] = key;
		}
	}

	return K[start+index];
}

int partition(int start, int end){
	
	int temp;

	int pivot = A[end];
	int i = start;

	for(int j=start;j<end;j++){
		if(pivot > A[j]){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
		}
	}

	temp = A[i];
	A[i] = A[end];
	A[end] = temp;

	return i;
}

int select(int B[], int start, int end, int index){
	
	if(start<end){
		int p = partition(start,end);
		if(index==p){
			return B[p];
		}
		else if(index<p){
			return select(B,start,p-1, index);
		}
		else{
			return select(B, p+1,end, index);
		}
	}
}


int Median(int start, int end){
	// int p;
	int n = end-start+1;
	int B[n], r;
	int k=0;
	for(int i=start;i<=end;i+=5){
		r = i+5;
		if(i+5>end){
			r=end;
		}
		B[k] = insertionSortIndex(A, i, r, 2);
		k++;
	}

	return select(B, 0, k-1, ((k-1)/2));

}

int KClosest(int n, int k){
	int m = Median(0,n);

	cout << "Median: " << A[m] << endl; 

	int dist[n];

	for(int i=0;i<n;i++){
		dist[i] = abs(A[i]-A[m]);
	}
	int delta = select(dist, 0, n, k);

	cout << "K Closest to the median" << endl;
	for(int i=0;i<n;i++){
		if(delta>dist[i]){
			cout << A[i] <<  endl;
		}
	}
	return 0;
}

int main(){

	int n, k;
	cin >> n;

	k=n;

	srand(time(NULL));

	cout << "Numbers:" << endl;

	while(k){
		A[n-k] = rand() % n+1;
		cout << A[n-k] << endl;
		k--;
	}

	cout << "k : ";
	cin >> k;
	// cout << "Selected Random: " << Median(0,n-1,(n/2)) << endl;
	KClosest(n, k);

	k=n;
	insertionSort(A, n);
	cout << "Sorted: " << endl;
	while(k){
		// A[n-k] = rand() % n+1;
		cout << A[n-k] << endl;
		k--;
	}

	return 0;
}