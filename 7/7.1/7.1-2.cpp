// Quicksort - Partition Algorithm

#include <cstdlib>
#include <ctime>
#include <iostream>
// #include <>
using namespace std;

int partition(int A[], int start, int end){
	int pivot = A[end-1];
	int temp;
	int i = start;

	for(int j=(start);j<end-1;j++){
		if(pivot > A[j]){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
		}
	}

	temp = A[i];
	A[i] = A[start];
	A[start] = temp;

	return i;
}

int main(){

	int n, k;
	cin >> n;
	int array[n+1];
	k=n;

	srand(time(NULL));

	while(k){
		array[n-k] = rand() % 100+1;
		cout << array[n-k] << endl;
		// cin >> array[n-k];
		k--;
	}

	cout << "Partition: " << partition(array, 0, n) << endl;

}