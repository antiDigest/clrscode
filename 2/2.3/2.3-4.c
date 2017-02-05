
/*
	We can express insertion sort as a recursive procedure as follows. In order to sort
	A(1,..,n), we recursively sort A(1, .. ,n-1) and then insert A[n] into the sorted array
	A(1,..,n-1). Write a recurrence for the running time of this recursive version of
	insertion sort.
*/

#include <stdio.h>

int main(){
	int i, j, A[10], key, n, k;
	printf("Enter n(<10) : ");
	scanf(" %d",&n);
	printf("Enter values \n");
	for(i=0;i<n;i++){
		printf("Enter A[%d] : ",i+1 );
		scanf(" %d",&A[i]);
	}

	k=0;
	for(i=0;i<n;i++){
		for(j=i;j>=0;j--){
			key = A[j];
			if(A[j-1]>key){
				A[j] = A[j-1];
				A[j-1] = key;
			}
		}
	}

	printf("\nSorted \n");
	for(i=0;i<n;i++){
		printf("Enter A[%d] : %d\n",i+1,A[i] );
	}
}