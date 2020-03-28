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
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>weg[i]>>val[i];
		sum+=val[i];
	}

	vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 1000000000));
	dp[0][0]=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (j >= val[i]) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - val[i]] + weg[i]);
		}
	}
	/*
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	//*/
	ll ans=0;
	for(int i=0;i<=sum;i++){
		if(dp[n][i] <= W){
			ans=i;
		}
	}
	cout<<ans<<endl;

	return 0;
}