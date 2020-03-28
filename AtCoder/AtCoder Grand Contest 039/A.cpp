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

	string s;
	cin>>s;
	ll need=0,k,n=s.length();
	cin>>k;

	if(n==1){
		cout<<(k/2)<<endl;
		return 0;
	}

	s+=s;
	s+=s;
	s+=s;
	s+=s;
	//cout<<s<<endl;

	ll dp[(16*n)][26];
	for(int i=0;i<26;i++) dp[0][i] = ((i == s[0]-'a')? 0 : 1);

	ll ans[16*n]={0};
	for(ll i=1;i<(16*n);i++){
		//cout<<i<<" ";
		ll add=1, temp = s[i]-'a';
		//cout<<i<<endl;
		ans[i] = MOD;
		for(ll j=0;j<26;j++){
			//cout<<"h"<<endl;
			if(temp==j) add=0;
			else add=1;
			dp[i][j] = dp[i-1][j] + 1;
			for(ll k=0;k<26;k++){
				if(j==k) continue;
				dp[i][j] = min(dp[i][j], dp[i-1][k]+add);
			}
			ans[i] = min(ans[i], dp[i][j]);
		}
	}

	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<26;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	//cout<<n<<" "<<k<<endl;
	//ll ans1=INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX, ans4 = INT_MAX, ans5 = INT_MAX;

	// for(ll i=0;i<26;i++){
	// 	ans1 = min(ans1, dp[n-1][i]);
	// 	ans2 = min(ans2, dp[(2*n)-1][i]);
	// 	ans3 = min(ans3, dp[(3*n)-1][i]);
	// 	ans4 = min(ans4, dp[(4*n)-1][i]);
	// 	ans5 = min(ans5, dp[(5*n)-1][i]);
	// }
	//cout<<n<<endl;
	//if(s[n-1]==s[0] && s[n-1]!=s[n-2]) need=1;
	//cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<endl;
	// for(int i=1;i<=16;i++){
	// 	cout<<ans[i*n-1]<<" ";
	// }
	// cout<<endl;
	ll even = ans[2*n-1] - ans[n-1];
	ll odd = ans[3*n-1] - ans[2*n-1];
	
	if(k==1) cout<<ans[n-1]<<endl;
	else if(k==2) cout<<ans[2*n-1]<<endl;
	else if(k==3) cout<<ans[3*n-1]<<endl;
	else if(k==4) cout<<ans[4*n-1]<<endl;
	else if(k==5) cout<<ans[5*n-1]<<endl;
	else cout<<ans[n-1] + ((k/2)*(odd+even))<<endl;

	return 0;
}