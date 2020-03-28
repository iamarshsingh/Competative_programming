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

	ll n,m,k;
	cin>>n>>m>>k;
	vector<ll> diff(k);
	ll curr = m-1;
	diff[0] = m;
	for(int i=1;i<k;i++){
		diff[i] = diff[i-1]+curr;
		curr--;
	}
	ll ans = (n/diff[k-1]);
	ans = ans*k;
	n = n%diff[k-1];
	ll i = upper_bound(diff.begin(), diff.end(), n)-diff.begin();
	ans += i+1;
	n = n - diff[i];
	if(n>=0) ans++;
	cout<<ans<<endl; 

	return 0;
}