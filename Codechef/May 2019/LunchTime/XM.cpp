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
		ll l,r,n,q;
		cin>>n>>q;
		ll arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
		while(q--){
			cin>>l>>r;
			ll ans=0;
			for(ll i=l-1;i<r;i++){
				ans += arr[i] ^ (i+1-l);
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}