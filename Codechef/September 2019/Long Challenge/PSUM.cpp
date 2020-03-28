#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

ll n,s,k,ans=0;
ll val[105];
ll cost[105];

ll power(ll x, ll y){
	ll res = 1;
	while (y > 0) { 
		if (y & 1)
			res = (res * x)%MOD; 
		y = y >> 1;
		x = (x * x)%MOD;
	}
	return res;
}

void solve(ll curcost, ll curval, ll pos){
	if(pos>=n){
		ans = (ans + power(curval, k))%MOD;
		return ;
	}
	//cout<<power(curval, k)<<" "<<ans<<" "<<curcost<<" "<<curval<<" "<<pos<<endl;
	solve(curcost, curval, pos+1);
	if(curcost + cost[pos] <= s) solve(curcost + cost[pos], curval+val[pos], pos+1);
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	cin>>n>>s>>k;

	for(int i=0;i<n;i++){
		cin>>cost[i]>>val[i];
	}

	solve(0,0,0);

	cout<<ans<<endl;

	return 0;
}