#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll temp,n,curr;
	cin>>n;

	pair<ll,ll> arr[n];

	ll val[64] = {0};

	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		temp = arr[i].first;
		curr=0;
		while(temp%2 == 0){
			temp /= 2;
			curr++;
		}
		val[curr]++;
		arr[i].second = curr;
	}
	ll maxx=0;
	for(int i=0; i<64;i++){
		if(val[i]>val[maxx]) maxx = i;
	}

	cout<<n - val[maxx]<<endl;
	for(int i=0;i<n;i++){
		if(arr[i].second != maxx) cout<<arr[i].first<<" ";
	}
	cout<<endl;
	return 0;
}