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

	int t;
	cin>>t;
	while(t--){
		int n,k,a;
		cin>>n>>k;
		vector<bool> poss(n,true);
		for(int i=0;i<k;i++){
			cin>>a;
			poss[a-1]=false;
		}
		ll dp[n+1] = {0};
		dp[0] = 1;
		for(int i=0;i<n;i++){
			if(poss[i]){
				dp[i+1] += dp[i];
				if(i>0) dp[i+1] += dp[i-1];
				if(i>1) dp[i+1] += dp[i-2];
				dp[i+1] %= MOD;
			}
			else{
				dp[i+1] = 0;
			}
			//cout<<dp[i+1]<<endl;
		}
		cout<<dp[n]<<endl;
	}

	return 0;
}