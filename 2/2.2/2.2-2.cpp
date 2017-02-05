/*Consider sorting n numbers stored in array A by first finding the smallest element
of A and exchanging it with the element in A[1]. Then find the second smallest
element of A, and exchange it with A[2]. Continue in this manner for the first n-1
elements of A. Write pseudocode for this algorithm, which is known as selection
sort. What loop invariant does this algorithm maintain? Why does it need to run
for only the first n 1 elements, rather than for all n elements? Give the best-case
and worst-case running times of selection sort in theta-notation.
*/

#include <iostream>
#include "sort.h"
using namespace std;

int main(){
	int i, n, j, key;
	int A[100];
	printf("\nEnter n : ");
	scanf(" %d",&n);
	for(i=0;i<n;i++){
		printf("Enter A[%d] ",i+1);
		scanf(" %d",&A[i]);
	}

	*A = selectionSort(A, n);

	for(int i=0;i<n;i++){
		printf("A[%d] = %d\n",i+1,A[i]);
	}
}