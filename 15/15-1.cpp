// Shortest Weighted Directed Path from s to t.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

pair< vector<int>, vector<int> > findPath(vector< vector<int> > weight, int n, int s, int t){
	vector<int> Path(n);
	vector<int> C(n);

	// Base
	Path[0] = 0;

	// Step
	for(int i=s;i<=t;i++){
		Path[i] = weight[i][1] + Path[1];
		C[i] = 1;
		for(int j=1;j<n;j++){
			if(Path[i] > Path[j] + weight[i][j]){
				Path[i] = weight[i][j] + Path[j];
				C[i] = j;
			}
		}
	}

	return {Path, C};
}

int main(){
	
	int n, k, s, t;
	// pair< int[], int[] > value;
	cin >> n;
	cin >> s >> t;
	vector< vector<int> > A(n, vector<int>(n));

	k=n;

	srand(time(NULL));

	while(k){
		for(int i=0;i<n;i++)
			A[n-k][i] = rand() % 50+1;
		k--;
	}

	cout << "Weights: "<< endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << i << " to " << j << " : " << A[i][j] << endl;
	}

	auto ret = findPath(A, n, s, t);

	vector<int> Path = ret.first;
	vector<int> C = ret.second;

	cout << "Min Weight from s to t: " << Path[t] << endl;
	cout << "Places to cut: " << endl;
	// int i = t;
	// while(i!=s){
	// 	cout << C[i] << endl;
	// 	i = C[i];
	// }

	return 0;

}