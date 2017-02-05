/*
Consider the problem of adding two n-bit binary integers, stored in two n-element
arrays A and B. The sum of the two integers should be stored in binary form in
an (n + 1)-element array C . State the problem formally and write pseudocode for
adding the two integers.
*/

#include <iostream>
using namespace std;

int main(){
	int i, n, sum;
	int A[100], B[100], C[100];
	printf("\nEnter length of binary integers ... ");
	scanf(" %d",&n);
	for(i=0;i<=n;i++){
		C[i] = 0;
		A[i] = 0;
		B[i] = 0;
	}
	printf("Enter binary numbers with spaces between each bit\n");
	printf("Enter the first binary number :\n");
	for(i=0;i<n;i++){
		scanf(" %d",&A[i]);
	}
	printf("Enter the second binary number :\n");
	for(i=0;i<n;i++){
		scanf(" %d",&B[i]);
	}
	
	sum = 0;
	for(i=n;i>0;i--){
		sum = A[i-1] + B[i-1] + C[i-1];
		if(sum==0 || sum ==1){
			C[i-1] = sum;
		}
		else if(sum==2){
			C[i-1] = 0;
			C[i] = 1;
		}
		else if(sum == 3){
			C[i-1] = 1;
			C[i] = 1; 
		}
		
	}
	printf("Sum of the two binary numbers : \n");
	for(i=n;i>=0;i--){
		printf("%d ", C[i]);
	}
	printf("\n\n");
}