// Return a "part" sized array from A in the middle of A

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

void output(int K[], int start, int end){
	for(int i=start; i<=end;i++){
		cout << K[i] << " ";
	}
	cout << endl;
}

int Rselect(int B[], int start, int end, int index, int part){
	// int p;
	if((end-start)>part){
		int p = partition(start,end);
		if((end-start)==part){
			output(B, start, end);
			return 0;
		}
		else if(index==p){
			return B[p];
		}
		else if(index<p){
			return Rselect(B,start,p-1, index, part);
		}
		else{
			return Rselect(B, p+1,end, index, part);
		}
	}
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

	cout << "Partition size: ";
	int part;
	cin >> part;

	cout << "Selected Random: " << Rselect(A, 0,n-1,(n/2), part) << endl;

	return 0;
}