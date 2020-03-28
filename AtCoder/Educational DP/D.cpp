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

	ll n,W;
	cin>>n>>W;
	ll weg[n];
	ll val[n];
	ll dp[n+1][W+1];
	for(ll i=0;i<n;i++){
		cin>>weg[i]>>val[i];
	}

	for(ll i=0;i<=n;i++){
		for(ll w=0;w<=W;w++){
			if(i==0 || w==0){
				dp[i][w]=0;
			}
			else if(w>=weg[i-1]){
				dp[i][w] = max(val[i-1]+dp[i-1][w-weg[i-1]] , dp[i-1][w]);
			}
			else{
				dp[i][w] = dp[i-1][w];
			}
		}
		//cout<<i<<endl;
	}
	
	cout<<dp[n][W]<<endl;	

	return 0;
}