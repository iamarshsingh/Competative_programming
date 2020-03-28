#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll n,k;
	cin>>n>>k;
	ll h[n];
	ll dp[n]={0};
	for(ll i=0;i<n;i++){
		cin>>h[i];
		dp[i]=10000000000000000;
	}
	
	for(ll i=1;i<n;i++){
		for(ll j=i-1;j>=max((ll)0,i-k);j--){
			dp[i] = min(dp[i],dp[j]+abs(h[i]-h[j]));
		}
	}

	cout<<dp[n-1]<<endl;
	return 0;
}