#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define minimum(a,b) (a<b)?a:b;
using namespace std;

ll ans=0LL;
ll n;
ll val[100005];
vector<ll> arr[100005];
bool visited[100005];

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return (a.first*b.second) > (a.second*b.first);
}

pair<ll,ll> solve(ll node){
	visited[node] = true;
	vector<pair<ll,ll>> curr;
	for(ll i:arr[node]){
		if(!visited[i]){
			pair<ll,ll> temp = solve(i);
			curr.push_back(temp);
			//cout<<temp.first<<" "<<temp.second<<" "<<ans;
			//ans += minimum( (curr.first * temp.second), (curr.second * temp.first) );
			//cout<<"->"<<ans<<endl;
			//curr.first += temp.first;
			//curr.second += temp.second;
		}
	}
	pair<ll,ll> temp = {0,0};
	sort(curr.begin(), curr.end(), comp);
	for(ll i=0;i<curr.size();i++){
		ans += (curr[i].first * temp.second);
		//cout<<"->"<<ans<<endl;
		temp.first += curr[i].first;
		temp.second += curr[i].second;
	}
	//cout<<node<<" "<<curr.first<<" "<<curr.second<<" "<<ans<<"->";
	//cout<<ans<<endl;
	if(val[node]==0){
		temp.first++;
	}
	else{
		ans += temp.first;
		temp.second++;
	}
	return temp;
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
		ll a,b;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>val[i];
			visited[i] = false;
			arr[i].clear();
		}
		for(ll i=1;i<n;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		ans = 0LL;
		pair<ll,ll> curr = solve(1);
		cout<<ans<<"\n";
	}

	return 0;
}