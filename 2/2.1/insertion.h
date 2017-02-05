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