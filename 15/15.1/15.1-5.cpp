// Dynamic Programming Rod-Cutting Problem.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "sort.h"

using namespace std;

vector<int> fibonacci(int n){
	vector<int> F(n);

	// Base
	F[0] = 0;
	F[1] = 1;

	// Step
	for(int i=2;i<=n;i++){
		F[i] = F[i-2] + F[i-1];
	}

	return F;
}

int main(){
	
	int n, k;
	cin >> n;

	vector<int> R = fibonacci(n);

	cout << "fibonacci value: " << int(round(R[n])) << endl;
	
	return 0;

}