#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

using pll = pair<int,int>;

bool comp(pair<int,pll> a, pair<int,pll> b){
	if(a.second.first)
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,g;
	cin>>n>>g;
	pair<int,pll> arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		cin>>arr[i].second.first;
		cin>>arr[i].second.second;
	}
	sort(arr, arr+n, comp);
	


	return 0;
}