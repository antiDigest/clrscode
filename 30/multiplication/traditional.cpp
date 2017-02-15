// Traditional Multiplication

#include <iostream>
#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> multiply(vector<int> A, vector<int> B, int n){
	vector<int> C, mul;
	int muli;

	for(int i=0;i<n;i++){
		muli = A[i];
		for(int j=0;j<n;j++){
			muli = B[j];
		}
		mul = mul + muli * pow(10,i);
	}

	for(int i=0;i<mul.size();i++)
		cout << mul[i] << " ";

	return C;

}

int main(){

	int n, k;
	cin >> n;

	k=2;

	srand(time(NULL));
	
	vector<int> A, B;

	A.push_back(rand() % (10*n)+1);
	for(int i=0;i<A.size();i++)
		cout << A[i] << " ";
	cout << endl;
	// cout << A << endl;
	B.push_back(rand() % (10*n)+1);
	for(int i=0;i<B.size();i++)
		cout << B[i] << " ";
	cout << endl;
	// cout << B << endl;

	multiply(A,B,n);

	return 0;


}