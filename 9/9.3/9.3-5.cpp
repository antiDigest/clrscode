// Deterministic Select

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int A[100];

int insertionSort(int K[], int start, int end, int index){
	int i,j, key;

	for(j=start;j<=end;j++){
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

int Rselect(int B[], int start, int end, int index){
	// int p;
	if(start<end){
		int p = partition(start,end);
		if(index==p){
			return B[p];
		}
		else if(index<p){
			return Rselect(B,start,p-1, index);
		}
		else{
			return Rselect(B, p+1,end, index);
		}
	}
}


int Dselect(int start, int end, int index){
	// int p;
	int n = end-start+1;
	int B[n], r;
	int k=0;
	for(int i=start;i<=end;i+=5){
		r = i+5;
		if(i+5>end){
			r=end;
		}
		B[k] = insertionSort(A, i, r, 2);
		k++;
	}

	return Rselect(B, 0, k-1, ((k-1)/2));

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

	cout << "Selected Random: " << Dselect(0,n-1,(n/2)) << endl;

	return 0;
}