// Quicksort with Randomised partition Algorithm

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int A[10000];

int partition(int start, int end){
	
	int random = start + rand() % (end-start);
	int temp;

	// cout << "Random: " << random <<  endl;

	temp = A[end];
	A[end] = A[random];
	A[random] = temp;

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

	cout << "Un-Sorted:" << endl;

	while(k){
		A[n-k] = rand() % n+1;
		cout << A[n-k] << endl;
		k--;
	}

	quicksort(0, n-1);

	cout << "Sorted:" << endl;

	for(int i=0;i<n;i++){
		cout<< A[i] <<endl;
	}

}