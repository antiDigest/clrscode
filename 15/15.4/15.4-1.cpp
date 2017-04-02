// Largest Common Substring

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

vector< vector<int> > LCS(vector<char> string1, int m, vector<char> string2, int n){
	vector< vector<int> > L(m, vector<int>(n));

	//Base
	for(int i=0;i<n;i++)
		L[0][i] = 0;
	for(int i=0;i<m;i++)
		L[i][0] = 0;

	//Step
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(string1[i]==string2[j]){
				L[i][j] = L[i-1][j-1]+1;
			}
			else{
				L[i][j] = maximum(L[i-1][j], L[i][j-1]);
			}
		}
	}

	int i = m-1, j = n-1;
	cout << "Longest Common Subsequence:" << endl;
	while (i > 0 && j > 0){
		if(string1[i-1] == string2[j-1]){
			cout << string1[i-1];
			i--;
			j--;
		}
		else if(L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}
	cout << endl;

	return L;

}

int main(){

	srand(time(NULL));

	int l1 = rand() % 10+1;
	int l2 = rand() % 10+1;

	cout << "First String: ";
	vector<char> str1 = randomString(l1);
	cout << "Second String: ";
	vector<char> str2 = randomString(l2);

	vector< vector<int> > L = LCS(str1, l1, str2, l2);
	cout << "Longest Common Subtring has length: " << L[l1-1][l2-1] << endl;

	return 0;
}