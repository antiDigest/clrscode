// Min Heapify

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int A[10000];

int left(int i){
	return i*2;
}

int right(int i){
	return i*2+1;
}

int min_heapify(int A[], int k, int n){
	if(n==1){
		return 0;
	}
	
	int l = left(k);
	int r = right(k);
	int smallest = l;

	if (l<=n and A[k]<=A[smallest])
		smallest = k;
	else
		smallest=l;
	if(r<=n and A[r]<=A[smallest])
		smallest = r;

	if(smallest!=k){
		int temp = A[smallest];
		A[smallest] = A[k];
		A[k] = temp;
		return min_heapify(A,smallest,n);
	}

}

int main(){
	int n, k;
	cin >> n;
	// int A[n];

	k=n;

	srand(time(NULL));

	cout << "Numbers:" << endl;

	while(k--){
		A[n-k] = rand() % n+1;
		cout << A[n-k] << endl;
		// k--;
	}

	max_heapify(A,1,n);

	cout << "Heapified" <<  endl;
	k=n;
	while(k--){
		cout << A[n-k] << endl;
		// k--;
	}

	return 0;
}