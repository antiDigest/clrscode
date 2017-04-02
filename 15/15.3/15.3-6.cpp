// Matrix Chain Multiplication

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
// #include "sort.h"

using namespace std;

pair< vector<int>, vector<int> > comissionZero(vector< vector<int> > A, int n){
	vector<int> C(n);
	vector<int> from(n);

	int d;
	cout << "Enter Initial value:";
	cin >> d;

	//Base
	C[0] = d;

	//Step
	for(int i=1;i<n;i++){
		C[i] = 0;
		for(int k=0;k<i;k++){
			int q = C[k]*A[k][i];
			if(C[i] < q){
				C[i] = q;
				from[i] = k;
			}
		}
		// cout << C[i] << endl;
	}

	return {C, from};

}

pair< vector< vector<int> >, vector<int> > comissionNotZero(vector< vector<int> > A, int n, vector<int> S){
	vector< vector<int> > C(n, vector<int>(n));
	vector<int> from(n);

	int d;
	cout << "Enter Initial value:";
	cin >> d;

	//Base
	for(int i=0;i<n;i++)
		C[0][i] = d;

	//Step
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			C[i][j] = 0;
			for(int k=0;k<i;k++){
				int q = C[k][j+1]*A[k][i];
				if(C[i][j] < q){
					C[i][j] = q;
					from[i] = k;
				}
			}
		}
	}

	return {C, from};

}

int main(){

	int n, k;
	// pair< int[], int[] > value;
	cin >> n;
	vector< vector<int> > A(n, vector<int>(n));
	vector<int> S(n);

	k=n;

	srand(time(NULL));

	cout << "Profits:" << endl;

	while(k){
		for(int i=0;i<n;i++){
			if(n-k==i) A[n-k][i] = 0;
			else A[n-k][i] = rand() % 10+1;
		}
		S[n-k] = rand() % 5+1;
		k--;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << i << " to " << j << " : " << A[i][j] << endl;
	}

	auto ret1 = comissionZero(A, n);
	vector<int> C= ret1.first;
	cout << "Max output recieved(Comission Zero): "<< C[n-1] << endl;

	auto ret2 = comissionNotZero(A, n, S);
	vector< vector<int> > R = ret2.first;
	cout << "Comissions: " << endl;
	for(int i=0;i<n;i++){
		cout << i << " : " << S[i] << endl;
	}
	int max = 0;
	for(int i=0;i<n;i++){
		if(max< R[n-1][i]-S[i]) max = R[n-1][i]-S[i];
	}
	cout << "Max output recieved(Comission Not Zero): "<< max << endl;

	return 0;
}