#include <iostream>

int insertionSort(int A[], int reverse=false){
	int i,j, key;
	if(reverse){
		for(j=1;j<6;j++){
		key = A[j];
		i = j-1;
		while(i>=0 && A[i]<key){
			A[i+1] = A[i];
			i = i-1;
			A[i+1] = key;
		}
	}
	}
	else{
		for(j=1;j<6;j++){
		key = A[j];
		i = j-1;
		while(i>=0 && A[i]>key){
			A[i+1] = A[i];
			i = i-1;
			A[i+1] = key;
		}
	}
	}
	
}

int selectionSort(int A[], int n, int reverse=false){
	// int n=sizeof(A)/sizeof(*A);

	if(not reverse){
		for(int i=0;i<n;i++){
			int key = A[i];
			for(int j=i+1;j<n;j++){			
				if(A[j]<key){
					A[i] = A[j];
					A[j] = key;
					key = A[i];
				}
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			int key = A[i];
			for(int j=i+1;j<n;j++){			
				if(A[j]>key){
					A[i] = A[j];
					A[j] = key;
					key = A[i];
				}
			}
		}
	}
	return *A;
}