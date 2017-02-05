// Quicksort with "end" partition Algorithm

#include <cstdlib>
#include <ctime>
#include <iostream>
// #include <>
using namespace std;

int A[10000];

int partition(int start, int end){
	int pivot = A[end];
	int temp;
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

int quicksort(int start, int end){
	if (start<end){
		int mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

int main(){

	int n, k;
	cin >> n;

	k=n;

	srand(time(NULL));

	while(k){
		A[n-k] = rand() % 10+1;
		cout << A[n-k] << endl;
		k--;
	}

	quicksort(0, n-1);

	cout << "Sorted:" << endl;

	for(int i=0;i<n;i++){
		cout<<(A[i])<<endl;
	}

}