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
		ll n,ans=0;
		cin>>n;
		for(ll i=n-2;i>=2;i--){
			for(ll j=1; (2*j)<=n-i; j++){
				if(i>max(j, n-i-j)){
					if(j==n-i-j) ans+=3;
					else ans+=6;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}