#include <iostream>

int linearSearch(int A[], int key){
	for(int i=0;A[i]!=NULL;i++){
		if (A[i] == key){
			return i;
		}
	}
	return NULL;
}
