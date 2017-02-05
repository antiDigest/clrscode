/*
Consider the searching problem:
Input: A sequence of n numbers A = {a1 ; a2 ; : : : ; an} and a value v.
Output: An index i such that v = A[i] or the special value NIL if v does not appear in A.

Write pseudocode for linear search, which scans through the sequence, looking
for v. Using a loop invariant, prove that your algorithm is correct. Make sure that
your loop invariant fulfills the three necessary properties.
*/

#include <iostream>

#include "search.h"
using namespace std;

int main(){
	int i, n, v, flag;
	int A[100];
	printf("\nEnter the value of n : ");
	scanf(" %d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter A[%d] : ",i);
		scanf(" %d",&A[i]);
	}
	printf("\nEnter the value v : ");
	scanf(" %d",&v);

	int output = linearSearch(A, v);
	
	if(output==NULL){
		printf("Sorry, the number you entered was not in the list !\n");
	}
	else{
		cout << output << endl;
	}
}