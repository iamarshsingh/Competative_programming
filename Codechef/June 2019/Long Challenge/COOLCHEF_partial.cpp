#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll fact[500005];
map<ll,ll> mp;

ll power(ll a, ll b){
	ll ans = 1;
	if(b==0) return ans;
	ans = power(a,b/2);
	if(b%2==0) return (ans*ans)%MOD;
	else return ( (a*ans)%MOD * ans )%MOD;
}

ll modinv(ll a){
	return power(a,MOD-2);
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
	for(ll i=1;i<500000;i++)
	{
		fact[i] = (fact[i-1] * i)%MOD;
	}
	//cout<<"jer"<<endl;
	ll l,r,n,q,l1,r1,a=0;
	cin>>n>>q;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	//cout<<"her"<<endl;
	while(q--){
		cin>>l1>>l>>r1>>r;
		if(n>1001) cout<<1<<endl;
		l = ( l + (a*l1) )%n;
		r = ( r + (a*r1) )%n;
		if(l>r) swap(l,r);
		//cout<<"her"<<endl;
		mp.clear();
		map<ll,ll>::iterator it;
		ll cnt=0;
		for(ll i=l;i<=r;i++){
			cnt++;
			mp[arr[i]]++;
		}
		ll ans = fact[cnt];
		for(it = mp.begin(); it!=mp.end();it++){
			//cout<<"here: "<<it->second<<endl;
			if(it->second>1){
				ans = ( ans * modinv(fact[it->second]) )%MOD;
			}
		}
		cout<<ans<<endl;
		a = ans;
	}
	return 0;
}