// Maximum Subarray Problem !

#include <iostream>
#include <vector>
// #include "sort.h"
using namespace std;

int msa_n2(int A[], int n){
	int p[n+1];
	p[0] = 0;
	int maxi = 0, maxj = 0, maxsum = 0, sum=0;

	for (int i = 1; i <= n; i++){
		p[i] = p[i-1] + A[i];
	}

	for (int i = 1; i <= n; i++){
		for (int j = i+1; j < n; j++){
			sum = p[j] - p[i-1];
			if (sum > maxsum){
				maxsum = sum;
				maxi = i;
				maxj = j;
			}
		}
	}
	
	cout << "Max Subarray lies between: " << maxi << " and " << maxj << " and the sum is " << maxsum << endl;
}

vector<int> crossing(int A[], int low, int mid, int high){
	vector<int> ret;
	int left_sum = 0;
	int left = mid;
	int sum = 0;

	for(int i=mid; i>low; i--){
		sum += A[i];
		if(sum > left_sum){
			left_sum = sum;
			left = i;
		}
	}

	int right_sum = 0;
	int right = mid;
	sum = 0;

	for(int i=mid+1; i<high; i++){
		sum += A[i];
		if(sum > right_sum){
			right_sum = sum;
			right = i;
		}
	}

	ret.push_back(left);
	ret.push_back(right);
	ret.push_back(left_sum+right_sum);

	return ret;

}

vector<int> msa_nlogn(int A[], int low, int high){
	vector<int> ret1, ret2, ret3;

	if (high==low){
		ret1.push_back(low);
		ret1.push_back(high);
		ret1.push_back(A[high]);
		return ret1;
	}
	else{
		int mid = (low+high)/2;
		ret1 = msa_nlogn(A,low,mid);
		ret2 = msa_nlogn(A,mid+1,high);
		ret3 = crossing(A,low,mid,high);
		if(ret1[2]>=ret2[3] && ret1[2]>=ret3[3]){
			return ret1;
		}
		else if(ret2[2]>=ret1[3] && ret2[2]>=ret3[3]){
			return ret2;
		}
		else{
			return ret3;
		}
	}
}

int main(){
	
	int n;
	cout << "No. of numbers "; 
	cin >> n;
	int k=n;
	int A[n];
	while(k){
		cin >> A[n-k];
		k--;
	}
	std::vector<int> v;
	msa_n2(A,n);
	v =msa_nlogn(A,0,n);
	cout << "Max Subarray lies between: " << v[0] << " and " << v[1] << " and the sum is " << v[2] << endl;
	return 0;
}