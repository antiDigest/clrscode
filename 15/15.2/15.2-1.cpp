// Matrix Chain Multiplication

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
// #include "sort.h"

using namespace std;

#define INT_MAX 4294967294/2

pair< vector< vector<long long int> >, vector< vector<int> > > MCM(int A[], int n){
	vector< vector<long long int> > M(n, vector<long long int>(n));
	vector< vector<int> > S(n, vector<int>(n));

	//Base
	for (int i=1; i<n; i++)
        M[i][i] = 0;

	//Step
	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			int j = l+i-1;
			M[i][j] = INT_MAX;
			for(int k=i;k<=j-1;k++){
				long long int q = M[i][k] + M[k+1][j] + A[i-1]*A[k]*A[j];
				if(M[i][j] > q){
					M[i][j] = q;
					S[i][j] = k;
				}
			}
			// cout << M[i][j] << endl;
		}
	}

	return {M, S};

}

int print(vector< vector<int> > S, int i, int j){

	if(i==j){
		cout << "A" << i;
		return 1;
	}
	else{
		cout << "(";
		print(S, i, S[i][j]);
		print(S, S[i][j]+1, j);
		cout << ")";
	}

	return 0;
}

int main(){

	int n, k;
	// pair< int[], int[] > value;
	cin >> n;
	int A[n];

	k=n;

	srand(time(NULL));

	cout << "Profits:" << endl;

	while(k){
		A[n-k] = rand() % 5+1;
		k--;
	}

	for(int i=0;i<n;i++){
		cout << i << " : " << A[i] << endl;
	}

	auto ret = MCM(A, n);

	vector< vector<long long int> > M= ret.first;
	vector< vector<int> > S= ret.second;

	cout << "Min number of multiplications are: " << M[1][n-1] << endl;

	cout << "Optimal Multiplication ordering:" << endl;
	print(S, 0, n-1);
	cout << endl;

	return 0;
}