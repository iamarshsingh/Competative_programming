#include <bits/stdc++.h>
#define ll long long int 
#define MOD 1000000007
using namespace std;

vector<pair<ll,ll>> ans;

ll gcd(ll a, ll b){
	if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

ll solve(ll a, ll b){
	ll temp = gcd(a,b); 
	return b-temp;
}

void iter(vector<ll> arr[], ll v[], ll m[], bool visited[] ,ll node, ll val){
	bool leaf = true;
	for(ll i:arr[node]){
		if(!visited[i]){
			visited[i]=true;
			leaf=false;
			iter(arr,v,m,visited,i,gcd(v[i],val));
		}
	}
	if(leaf){
		//cout<<node<<endl;
		ans.push_back({node,solve(val,m[node])});
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

	ll t;
	cin>>t;
	while(t--){
		ll n,a,b;
		cin>>n;
		vector<ll> arr[n+1];
		ll v[n+1];
		ll m[n+1];
		bool visited[n+1]={false};
		for(int i=0;i<n-1;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for(int i=0;i<n;i++){
			cin>>v[i+1];
		}
		for(int i=0;i<n;i++){
			cin>>m[i+1];
		}
		ans.clear();
		visited[1]=true;
		iter(arr,v,m,visited,1,v[1]);
		sort(ans.begin(),ans.end());
		//cout<<"here"<<endl;
		for(int i=0;i<ans.size();i++)cout<<ans[i].second<<" ";
		cout<<endl;
	}

	return 0;
}