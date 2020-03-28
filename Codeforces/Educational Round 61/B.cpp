#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(ll a, ll b){
	return a>b;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
		
	ll sum=0,a,n,m;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	sort(arr,arr+n,comp);
	cin>>m;
	while(m--){
		cin>>a;
		cout<<sum-arr[a-1]<<endl;
	}
	return 0;
}