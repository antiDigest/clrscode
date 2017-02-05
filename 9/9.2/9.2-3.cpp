// Randomised Select - Recursive

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int A[10000];

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


int Rselect(int start, int end, int index){
	// int p;
	if(start<end){
		int p = partition(start,end);
		if(index==p){
			return A[p];
		}
		else if(index<p){
			return Rselect(start,p-1, index);
		}
		else{
			return Rselect(p+1,end, index);
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

	int index;
	cin >> index;

	cout << "Selected Random: " << Rselect(0,n-1,index) << endl;

	return 0;
}