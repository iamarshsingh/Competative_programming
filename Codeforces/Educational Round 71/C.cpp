#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 100000000000000000
using namespace std;

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int t;
	cin>>t;
	while(t--){
		ll n,a,b;
		cin>>n>>a>>b;
		string s;
		ll dp[n+1][2];
		for(int i=0;i<n;i++){
			dp[i][0] = dp[i][1] = INF;
		}
		cin>>s;
		dp[0][0] = b;
		for(int i=1;i<n;i++){
			if(s[i]=='0' && s[i-1]=='0'){
				//cout<<"1"<<" ";
				dp[i][0] = min(dp[i-1][0]+a, dp[i-1][1]+(2*a)) + b;
				dp[i][1] = min(dp[i-1][0]+(2*a), dp[i-1][1]+a) + (2*b);
			}
			else{
				//cout<<"2 ";
				dp[i][0] = INF;
				dp[i][1] = min(dp[i-1][0]+(2*a), dp[i-1][1]+a) + (2*b);
			}
			//cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		dp[n][0] = min(dp[n-1][0]+a, dp[n-1][1]+(2*a)) + b;
		cout<<dp[n][0]<<endl;
	}

	return 0;
}