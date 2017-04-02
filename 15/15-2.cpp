// Longest Palindromic Subsequence

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <String>
// #include "sort.h"

using namespace std;

vector<char> randomString(int len) {
    char alphanum[] =
        // "0123456789"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    vector<char> str(len);

    for (int i = 1; i <= len; i++) {
    	// cout << alphanum[rand() % (sizeof(alphanum) - 1)] << endl;
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    string s( str.begin(), str.end() );

    cout << s << endl;

    return str;
}

int maximum(int a, int b){
	return (a > b)? a : b;
}

vector< vector<int> > LPS(vector<char> string1, int n){
	vector< vector<int> > L(n, vector<int>(n));

	//Base
	for(int i=0;i<n;i++)
		L[0][i] = 0;
	for(int i=0;i<n;i++){
		L[i][0] = 0;
		L[i][i] = 1;
	}

	//Step
	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){

			int j = i + l - 1;

			if(string1[i]==string1[j]){
				L[i][j] = L[i+1][j-1]+2;
			}
			else{
				L[i][j] = maximum(L[i+1][j], L[i][j-1]);
			}
			// cout << i << ":" << j << " -- " << L[i][j] << endl;
		}
	}

	return L;

}

int main(){

	srand(time(NULL));

	static const char arr[] = "aaabaaxyzes";
	vector<char> str1 (arr, arr + sizeof(arr) / sizeof(arr[0]) );

	cout << "String: ";
	for(int i=0;i<11;i++){
		cout << str1[i];
	}
	cout <<  endl;

	vector< vector<int> > L = LPS(str1, 11);
	cout << "Longest Palindromic Subtring has length: " << L[1][10] << endl;

	return 0;
}