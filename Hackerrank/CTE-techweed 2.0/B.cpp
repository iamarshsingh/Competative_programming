#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll power(ll a, ll b){
	if(b==0) return 1LL;
	ll ans = power(a, b/2);
	if(b%2==0) return (ans*ans)%MOD;
	else return ((a*ans)%MOD * ans)%MOD;
}

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
		int n;
		cin>>n;
		char c;
		ll curr=0;
		for(int i=0;i<n;i++){
			cin>>c;
			if(c=='1'){
				curr++;
			}
		}
		ll ans = (power(2LL, curr) - 1 + MOD ) %MOD;
		cout<<ans<<"\n";
	}
	return 0;
}