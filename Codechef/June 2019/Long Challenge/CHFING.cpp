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
		ll n,k,ans,a0,b,nfin;
		cin>>n>>k;
		nfin = ( (k+n-3)/(n-1) );
		nfin = nfin%MOD;
		n = n%MOD;
		k = k%MOD;
		//cout<<"nfin: "<<nfin<<endl;
		a0 = (k-1+MOD)%MOD;
		//cout<<a0<<endl;
		b = (n-1+MOD)%MOD;
		//cout<<"a0 b : "<<a0<<" "<<b<<endl;
		//cout<<nfin*((a0) - ((nfin-1)*(b))/2)<<endl;
		ll ans1,ans2;
		ans1 = (nfin * a0)%MOD;
		ans2 = ( ( ( nfin * ((nfin-1+MOD)%MOD) ) / 2 ) + MOD) % MOD;
		ans2 = (ans2 * b)%MOD;
		//cout<<ans1<<" "<<ans2<<endl;
		//cout<<ans<<endl;
		//cout<<ans*nfin<<endl;
		ans = (ans1 - ans2 + MOD)%MOD;
		cout<<ans<<endl;
	}

	return 0;
}