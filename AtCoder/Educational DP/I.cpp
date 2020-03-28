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

	cout<<setprecision(12)<<fixed;

	int n;
	cin>>n;
	long double p[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}

	long double dp[n+1][n+1];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[0][i] = 0;
		dp[i][0] = dp[i-1][0]*(1-p[i-1]);
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = (dp[i-1][j]*(1-p[i-1])) + (dp[i-1][j-1]*p[i-1]);
		}
	}

	long double ans = 0;
	for(int i=(n/2)+1;i<=n;i++){
		ans += dp[n][i];
	}
	cout<<ans<<endl;
	return 0;
}