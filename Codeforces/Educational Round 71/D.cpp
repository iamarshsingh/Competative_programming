#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
 
bool comp1(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}

bool comp2(pair<int,int> a, pair<int,int> b){
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
 
	int n;
	cin>>n;
	vector<pair<int,int>> arr(n,{0,0});
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		cin>>arr[i].second;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}

	ll fact[n+1];
	fact[0] = 1;
	for(ll i=1;i<=n;i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
	ll ans = fact[n];
	//cout<<ans<<endl;
	sort(arr.begin(), arr.end(), comp1);
	ll curr=1,freq=1;
	for(int i=1;i<n;i++){
		if(arr[i].first==arr[i-1].first){
			freq++;
		}
		else{
			if(freq>1){
				//cout<<freq<<endl;
				curr = (curr * fact[freq])%MOD;
			}
			freq=1;
		}
	}
	if(freq>1){
		curr = (curr * fact[freq])%MOD;
	}
	ans = (ans - curr + MOD) %MOD;
	//cout<<ans<<endl;
	sort(arr.begin(), arr.end(), comp2);
	curr=1;freq=1;
	for(int i=1;i<n;i++){
		if(arr[i].second==arr[i-1].second){
			freq++;
		}
		else{
			if(freq>1){
				curr = (curr * fact[freq])%MOD;
			}
			freq=1;
		}
	}
	if(freq>1){
		curr = (curr * fact[freq])%MOD;
	}
	ans = (ans - curr + MOD) %MOD;
	//cout<<ans<<endl;
	sort(arr.begin(), arr.end());
	curr=1;freq=1;
	for(int i=1;i<n;i++){
		if(arr[i].first==arr[i-1].first && arr[i].second==arr[i-1].second){
			freq++;
		}
		else if(arr[i].first<arr[i-1].first || arr[i].second<arr[i-1].second){
			curr=0;
			break;
		}
		else{
			if(freq>1){
				curr = (curr * fact[freq])%MOD;
			}
			freq=1;
		}
	}
	if(freq>1){
		curr = (curr * fact[freq])%MOD;
	}
	ans = (ans + curr + MOD) %MOD;
	cout<<ans<<endl;
 
	return 0;
}