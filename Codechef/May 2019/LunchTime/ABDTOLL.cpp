#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool visited[100005];

ll postorder(vector<ll> arr[], ll tl[], ll rate[], ll x){
	ll temp=0;
	visited[x]=true;
	for(ll i:arr[x]){
		if(!visited[i])	temp = max(temp, postorder(arr,tl, rate, i));
	}
	temp += tl[x];
	rate[x] = temp;
	return temp;
}

ll solve(vector<ll> arr[], ll tl[], ll rate[], ll k, ll x){
	ll curred = min(tl[x], max(0LL, rate[x]-k));
	visited[x]=true;
	rate[x] -= curred;
	for(ll i:arr[x]){
		if(!visited[i])	curred += solve(arr, tl, rate, k, i);
	}
	return curred;
}

int main(){
	
	fastio();
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	*/
	int t;
	cin>>t;
	while(t--){
		ll a,b,n,x,k;
		cin>>n>>x>>k;
		ll tl[n+1];
		for(int i=1;i<=n;i++){
			cin>>tl[i];
			visited[i]=false;
		}
		
		vector<ll> arr[n+1];
		for(int i=0;i<n-1;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		ll rate[n+1]={0};
		ll rat = postorder(arr,tl,rate,x);
		//cout<<"here"<<endl;
		for(int i=1;i<=n;i++){
			visited[i]=false;
		}
		ll ans=0;
		if(rat>k){
			ans = solve(arr, tl, rate, k, x);
		}
		cout<<(2*ans)<<endl;
	}

}