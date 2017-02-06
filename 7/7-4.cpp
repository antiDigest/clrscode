// Quicksort with 3-way partition Algorithm

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int A[10000];

int median(int a, int b, int c){
	if ((a >= b && a <= c) || (a >= c && a <= b)) return a;
	else if ((b >= a && b <= c) || (b >= c && b <= a)) return b;
	else return c;
}

int partition(int start, int end){

	int random1 = start + rand() % (end-start);
	int random2 = start + rand() % (end-start);
	int random3 = start + rand() % (end-start);
	
	int random = median(random1, random2, random3);
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
	while (start<end){
		int mid = partition(start, end);
		quicksort(start, mid-1);
		start = mid+1;
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