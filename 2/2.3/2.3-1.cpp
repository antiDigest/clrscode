/* Using Figure 2.4 as a model, illustrate the operation of 
//MERGE SORT
on the Array
A = {3; 41; 52; 26; 38; 57; 9; 49}.
*/

#include <iostream>
#include "sort.h"
using namespace std;

int A[] = {3, 41, 52, 26, 38, 57, 9, 49};

int main(){
	int i;
	printf("Unsorted : \n");
	for(i=0;i<8;i++){
		printf("A[%d] : %d\n",i+1,A[i]);
	}
	
	*A = merge_sort(A,0,7);

	printf("Sorted : \n");
	for(i=0;i<8;i++){
		printf("A[%d] : %d\n",i+1,A[i]);
	}
}