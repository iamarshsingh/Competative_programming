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
	
	ll n;
	cin>>n;
	ll inp[n][3];
	ll dp[n][3];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<3;j++)
			cin>>dp[i][j];
		if(i>0){
			dp[i][0] += max(dp[i-1][1],dp[i-1][2]);
			dp[i][1] += max(dp[i-1][0],dp[i-1][2]);
			dp[i][2] += max(dp[i-1][0],dp[i-1][1]);
		}
	}

	cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<endl;

	return 0;
}