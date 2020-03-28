#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

bool prime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
        if(n==1) cout<<"YES"<<endl;
		if(prime(n+1)){
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}

	return 0;
}