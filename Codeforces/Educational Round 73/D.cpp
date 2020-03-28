#include <bits/stdc++.h>
#define ll unsigned long long
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
		ll n;
		cin>>n;
		ll h[n];
		ll c[n];
		ll dp[n][3];
		for(int i=0;i<n;i++){
			cin>>h[i]>>c[i];
			dp[i][0] = dp[i][1] = dp[i][2] = 0;
		}
		dp[0][1] = c[0];
		dp[0][2] = (2*c[0]);

		for(int i=1;i<n;i++){
			if(h[i]==h[i-1]){
				dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
				dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + c[i];
				dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + (2*c[i]);
			}
			else if(h[i]==(h[i-1]+1)){
				dp[i][0] = min(dp[i-1][2], dp[i-1][0]);
				dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + c[i];
				dp[i][2] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0])) + (2*c[i]);
			}
			else if(h[i] == (h[i-1]+2)){
				dp[i][0] = min(dp[i-1][1], dp[i-1][0]);
				dp[i][1] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0])) + c[i];
				dp[i][2] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0])) + (2*c[i]);
			}
			else if(h[i]==(h[i-1]-1)){
				dp[i][0] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0]));
				dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + c[i];
				dp[i][2] = min(dp[i-1][0], dp[i-1][2]) + (2*c[i]);
			}
			else if(h[i] == (h[i-1]-2)){
				dp[i][0] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0]));
				dp[i][1] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0])) + c[i];
				dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + (2*c[i]);
			}
			else{
				dp[i][0] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0]));
				dp[i][1] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0])) + c[i];
				dp[i][2] = min(dp[i-1][2], min(dp[i-1][1], dp[i-1][0])) + (2*c[i]);
			}
		}
		// for(int i=0;i<n;i++){
		// 	cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		// }
		cout<<min(dp[n-1][2], min(dp[n-1][0], dp[n-1][1]))<<"\n";
	}

	return 0;
}