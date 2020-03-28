#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int sums[200001]={0};
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			sums[arr[i]+arr[j]]++;
		}
	}
	int maxx=0;
	for(int i=0;i<=200000;i++){
		if(sums[i]>maxx)maxx=sums[i];
	}
	cout<<maxx<<endl;
	return 0;
}