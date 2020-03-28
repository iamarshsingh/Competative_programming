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

	ll n,m,k,a,b;
	cin>>n>>m>>k;
	ll cost[n+1];
	for(int i=1;i<=n;i++)cin>>cost[i];
	sort(cost+1,cost+n+1);
	for(int i=2;i<=n;i++)cost[i] = cost[i]+cost[i-1];

	for(int i=0;i<=n;i++)cout<<cost[i]<<" ";

	vector<pair<ll,ll>> offers;
	ll cur,tot,minn = 10000000000000000;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		if(a<=k){
			offers.push_back({a,b});
		}
	}
	cout<<minn<<endl;

	return 0;
}