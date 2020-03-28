#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define N 100005
using namespace std;

ll fact[N];
ll ifact[N];

ll power(ll a, ll b){
	ll ans=1;
	while(b>0)
	{
		if(b%2==1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}

ll modinv(ll x){
	return power(x,MOD-2);
}

ll nCr(ll n, ll r){
	return ((fact[n] * ifact[r])%MOD * ifact[n-r])%MOD;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	fact[0] = 1;
	ifact[0] = 1;

	for(ll i=1;i<N;i++){
		fact[i] = (fact[i-1]*i)%MOD;
		//if(i<10)cout<<(i * fact[i-1])<<" "<<modinv(i * fact[i-1])<<endl;
		ifact[i] = modinv(fact[i]);
		//if(i<10)cout<<fact[i]<<" "<<ifact[i]<<endl;
	}

	int t;
	cin>>t;
	while(t--){
		ll n,m,k,ans=0,a=1;
		cin>>n>>m>>k;
		for(int i=n;i>=k;i--)
		{
			ans= ((nCr(n,i)*a)%MOD + ans)%MOD;
			a = (a*(m-1))%MOD;
		}
		cout<<ans<<'\n';
	}

	return 0;
}