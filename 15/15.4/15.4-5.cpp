// Largest Monotonically Increasing Subsequence

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <String>
// #include "sort.h"

using namespace std;

vector<int> randomString(int len) {
    char alphanum[] =
        "0123456789";
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        // "abcdefghijklmnopqrstuvwxyz";
    vector<int> str(len);

    for (int i = 1; i < len; i++) {
    	// cout << alphanum[rand() % (sizeof(alphanum) - 1)] << endl;
        str[i] = rand() % 10;
    }
    str[0] = 0;
    for (int i = 0; i < len; i++) {
        cout << i <<": "<< str[i] << endl;
    }

    return str;
}

int maximum(int a, int b){
	return (a > b)? a : b;
}

pair< vector<int>, vector<int> > LMIS(vector<int> sequence, int n){
	vector<int> L(n+1);
	vector<int> from(n+1);

	//Base
	L[0] = 0;

	//Step
	for(int i=1;i<n;i++){
		L[i] = L[0]+1;
		from[i] = 0;
		for(int j=1;j<i;j++){
			if((L[i] < L[j]+1) && (sequence[i] > sequence[j])){
				L[i] = L[j]+1;
				from[i] = j;
			}
		}
	}

	return {L, from};

}

int main(){

	srand(time(NULL));

	int l1 = rand() % 15+2;
	cout << "Sequence Length: " << l1 << endl;
	cout << "Sequence: "<< endl;
	vector<int> str1 = randomString(l1);
	
	auto ret = LMIS(str1, l1);
	vector<int> L = ret.first;
	vector<int> from = ret.second;

	int max = 0, maxi = 0;
	cout << "Longest Monotonically Increasing Subsequence: " << endl;
	for(int i=0;i<l1;i++){
		cout << i << ": " << L[i] << " from: " << from[i] << endl;
		if(max<L[i]){
			max = L[i];
			maxi = i;
		}
	}

	cout << "Longest Monotonically Increasing Subsequence has length: ";
	cout << max << endl;

	int i=maxi;
	cout << i << endl;
	while(i>0){
		cout << from[i] << endl;
		i = from[i];
	}

	return 0;
}