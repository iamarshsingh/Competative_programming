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
		ll n,k,ans;
		cin>>n>>k;
		k = k%MOD;
		n = n%MOD;
		ans = (((k-1)*k)/2)%MOD;
		cout<<ans<<endl;
	}

	return 0;
}