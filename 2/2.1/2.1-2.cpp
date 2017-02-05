// Illustrate the operation of insertion sort on the array A = {31, 41, 59, 26, 41, 58} in reverse order

#include <iostream>
#include "insertion.h"
using namespace std;

// int insertionSort(int A[]){
// 	int i,j, key;
// 	for(j=1;j<6;j++){
// 		key = A[j];
// 		i = j-1;
// 		while(i>=0 && A[i]<key){
// 			A[i+1] = A[i];
// 			i = i-1;
// 			A[i+1] = key;
// 		}
// 	}
// }

int main(){
	int A[] =  {31, 41, 59, 26, 41, 58};

	insertionSort(A, true);
	
	for(int i=0;i<6;i++){
		cout << A[i] << " ";
	}
}