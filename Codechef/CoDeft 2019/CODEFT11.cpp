#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll fact[4000006];

ll power(ll a, ll b){
	if(b==0) return 1LL;
	ll ans = power(a, b/2);
	if(b%2==0) return (ans*ans)%MOD;
	return ((a*ans)%MOD *ans)%MOD;
}

ll inv(ll a){
	return power(a, MOD-2);
}

ll solve(ll n, ll a, ll b){
	return ((fact[n] * inv(fact[a]))%MOD * inv(fact[b]))%MOD;
}

int main(){

	fact[0] = 1;
	for(ll i=1;i<=4000000;i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		cout<<solve((abs(c-a)+abs(d-b)), abs(d-b), abs(c-a))<<"\n";
	}

	return 0;
}