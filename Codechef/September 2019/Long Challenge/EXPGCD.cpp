#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll fact[200005];
ll ifact[200005];
ll factsums[200005];
vector<ll> factors[200005];

void presums(ll n){
	for(int i=1;i<=n; i++){
		for(ll j=(2*i); j<=n;j+=i){
			factors[j].push_back(i);
		}
	}
}

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

ll modinv(ll a){
	return power(a, MOD-2);
}

ll nCr(ll n, ll r){
	return ((fact[n]  * ifact[r]) % MOD * ifact[n-r])%MOD;
}

ll solve(ll n, ll k){
	ll ans = 0, curr = 0;
	for(ll i:factors[n]){
		curr = ((n-1)/(i));
		//if(n==8)cout<<"fact: "<<i<<" "<<curr<<" "<<ans<<" ";
		ans = (ans + ((i - factsums[i]) * nCr(curr, k-1))%MOD )%MOD;
		//if(n==8)cout<<ans<<endl;
		for(ll j:factors[n]){
			if(j%i==0 && j!=i) factsums[j] += (i - factsums[i]);
		}
	}
	for(ll j:factors[n]){
		factsums[j] = 0;
	}
	return ans;
}

int main(){
	
	//fastio
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// #ifndef ONLINE_JUDGE 
	// freopen("input.txt", "r", stdin); 
	// freopen("output.txt", "w", stdout); 
	// #endif

	fact[0] = 1;
	ifact[0] = 1;
	for(ll i=1;i<200005;i++){
		fact[i] = (fact[i-1] * i)%MOD;
		ifact[i] = modinv(fact[i]);
	}

	presums(200001);

	ll q,k,n;
	cin>>q>>k;

	ll ans[200005];

	for(ll i=1;i<200005;i++){
		if(i<k) ans[i] = 0;
		else{
			ll curr = solve(i,k);
			ans[i] = (ans[i-1] + curr)%MOD;
		}
	}
	//cout<<"here"<<endl;
	//cout<<q<<endl;
	while(q--){
		//cout<<"g"<<endl;
		cin>>n;
		cout<<(ans[n] * modinv(nCr(n,k)))%MOD<<"\n";
	}

	return 0;
}