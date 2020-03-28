#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

void dijkstra(vector<pair<ll,ll>> arr[], ll dis[], ll parent[] ,ll node, ll n){

	using pll = pair<ll,ll>;
	priority_queue<pll, vector<pll>, greater<pll>> pq;

	dis[node] = 0;
	pq.push({0,node});

	while(!pq.empty()){
		ll v = pq.top().second;
		ll d = pq.top().first;
		pq.pop();

		for(auto i: arr[v]){
			ll to = i.second;
            ll len = i.first;

            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                parent[to] = v;
                pq.push({dis[to], to});
            }
		}
		cout<<v<<" "<<d<<dis[v]<<endl;
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
	
	int t;
	cin>>t;
	while(t--){
		ll n,k,x,m,s,a,b,c;
		cin>>n>>k>>x>>m>>s;
		vector<pair<ll,ll>> arr[n+1];
		ll dis[n+1];
		ll parent[n+1]={-1};

		for(ll i=1;i<n;i++){
			if(i<=k) dis[i]=x;
			else dis[i] = 10000000000000000;
			parent[i]=-1;
		}

		for(ll i=1;i<=m;i++){
			cin>>a>>b>>c;
			arr[a].push_back({c,b});
			arr[b].push_back({c,a});
		}
		dis[s]=0;
		dijkstra(arr,dis,parent,s,n);

		for(int i=1;i<=n;i++){
			cout<<dis[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}