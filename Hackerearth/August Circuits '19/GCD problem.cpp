#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll st[1000006];
ll sums[1000006];

void build(ll arr[], ll l, ll r, ll node){
	if(l==r){
		st[node] = arr[l];
		sums[node] = arr[l];
	}
	else{
		ll mid = (l+r)/2;
		build(arr, l, mid, 2*node);
		build(arr, mid+1, r, 2*node + 1);
		st[node] = __gcd(st[2*node], st[2*node + 1]);
		sums[node] = st[2*node] + st[2*node + 1] + st[node];
	}
}

ll query(ll node, ll l, ll r, ll ql, ll qr){
	if(ql>qr){
		return 0;
	}
	else if(l==ql && r==qr){
		return st[node];
	}
	else{
		ll mid = (l+r)/2;
		ll q1 = query(2*node, l, r, ql, mid);
		ll q2 = query(2*node + 1, l, r, mid+1, qr);
		return (q1 + q2 + __gcd(st[]))
	}
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	ll l,r,n,m,ans=0,curr;
	cin>>n>>m;
	ll arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	build(arr, 0, n-1, 1);
	while(m--)
	{
		ans=0;
		cin>>l>>r;
		l--;r--;
		for(int i=l;i<=r;i++){
			ans+= gcds[i][r];
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}

	return 0;
}