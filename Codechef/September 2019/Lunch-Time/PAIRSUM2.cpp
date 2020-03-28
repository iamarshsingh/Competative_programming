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
		ll n,q,l,r,a,b;
		cin>>n>>q;
		ll arr[n]={0};
		ll sums[n]={0};
		for(ll i=1;i<n;i++){
			cin>>arr[i];
			if(i==1) sums[i] = arr[i];
			else sums[i] = sums[i-2] + arr[i];
		}
		while(q--){
			cin>>a>>b;
			l=min(a,b); r=max(a,b);
			//cout<<l<<" "<<r<<endl;
			if((r-l)%2==0){
				cout<<"UNKNOWN\n";
				continue;
			}
			ll ans = sums[r-1];
			if(l>1) ans -= sums[l-2];
			ans -= (sums[r-2] - sums[l-1]);
			cout<<ans<<"\n";
		}
	}

	return 0;
}