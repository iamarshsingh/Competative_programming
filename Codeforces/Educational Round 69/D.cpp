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
 
	ll n,m,k;
	cin>>n>>m>>k;
	ll arr[n];
	ll currnums=0,curr=0,ans=0;
	pair<ll,ll> dp[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		curr = arr[i];
		currnums = 1;
		ll tcurr = arr[i];
		ll tnums = 1;
		for(int j=i-1;j>=max(0,(int)(i-m));j--){
			
			if((curr - (k*ceil(((double)currnums)/m))) <= (tcurr+dp[j].first - (k*ceil(((double)(tnums+dp[j].second))/m)))){
				curr = tcurr+dp[j].first;
				currnums = tnums+dp[j].second;
			}
			tcurr += arr[j];
			tnums++;
			if(curr - (k*ceil(((double)currnums)/m)) <= tcurr - (k*ceil(((double)tnums)/m))){
				ans = max(ans, tcurr - (k*((ll)ceil(((double)tnums)/m))));
				curr = tcurr;
				currnums = tnums;
			}
		}
		ans = max(ans, curr - (k*((ll)ceil(((double)currnums)/m))));
		dp[i] = {curr, currnums};
		//cout<<curr<<" "<<currnums<<endl;
	}
	cout<<ans<<endl;
 
	return 0;
}