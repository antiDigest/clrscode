// Return a "part" sized array from A in the middle of A

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "sort.h"

using namespace std;

int median(int X[], int Y[], int startx, int endx, int starty, int endy){

	int midx = (startx+endx)/2;
	int midy = (starty+endy)/2;

	if(X[midx] < Y[midy]){
		return median(X, Y, midx+1, endx, starty, midy-1);
	}
	else if(X[midx] > Y[midy]){
		return median(X, Y, startx, midx-1, midy+1, endx);
	}
	else{
		return X[midx];
	}
}


int main(){

	int n, k;
	cin >> n;
	int X[n], Y[n];
	k=n;

	srand(time(NULL));

	while(k){
		X[n-k] = rand() % n+1;
		Y[n-k] = rand() % n+1;
		cout << X[n-k] << endl;
		cout << Y[n-k] << endl;
		k--;
	}

	*X = merge_sort(X,0,n);
	*Y = merge_sort(Y,0,n);

	cout << median(X,Y,0,n,0,n) << endl;

	return 0;
}