// Illustrate the operation of insertion sort on the array A = {31, 41, 59, 26, 41, 58}
#include <iostream>
// #include <stdio.h>

#include "insertion.h"
using namespace std;

int main(){
	int A[] =  {31, 41, 59, 26, 41, 58};

	insertionSort(A);
	
	for(int i=0;i<6;i++){
		cout << A[i] << " ";
	}
}