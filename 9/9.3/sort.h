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

int merge(int A[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        A[k] = R[j];
        j++;
        k++;
    }
    return *A;
}

int merge_sort(int A[], int p, int r){
	int q;
	if(p<r){
		q=((p+r)/2);
		*A=merge_sort(A,p,q);
		*A=merge_sort(A,q+1,r);
		*A=merge(A,p,q,r);	
	}
	return *A;
}