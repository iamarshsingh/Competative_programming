#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll n,negs=0,zeros=0,pos=0;
	cin>>n;
	ll arr[n];
	ll maxx=0, minind=-1;
	ll minusone;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>=0){
			arr[i] = -1*arr[i] - 1;
		}
		if(arr[i]!=-1){
			if(arr[i]<maxx){
				maxx = arr[i];
				minind = i;
			}
		}
		else{
			minusone = i;
		}
	}
	
	if(n%2==1){
		if(minind!=-1){
			arr[minind] = -1*arr[minind] - 1;
		}
		else{
			arr[minusone] = 0;
		}
	}
	
	for(ll i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}