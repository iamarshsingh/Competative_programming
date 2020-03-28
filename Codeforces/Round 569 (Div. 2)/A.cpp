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

	ll n,temp;
	cin>>n;
	temp = 4;
	ll ans=1;
	for(ll i=2;i<=n;i++){
		ans += temp;
		temp += 4;
	}
	cout<<ans<<endl;
	return 0;
}