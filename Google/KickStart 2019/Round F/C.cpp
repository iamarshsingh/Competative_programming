#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll val[100005];
vector<ll> arr[100005];
bool visited[100005];

ll solve(){
	ll n,a,b;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>val[i];
		arr[i].clear();
		visited[i]=false;
	}
	for(ll i=1;i<n;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	ll ans=0,curr=0;
	priority_queue<pair<ll,ll>> pq;
	map<ll,ll> pos;
	for(ll i=1;i<=n;i++){
		curr=val[i];
		for(ll k:arr[i]){
			curr += val[k];
		}
		pos[i] = curr;
		pq.push({curr,i});
		//cout<<curr<<" "<<i<<endl;
	}
	while(!pq.empty() && pq.top().first>0){
		pair<ll,ll> temp = pq.top();
		//cout<<"pre temp: "<<temp.first<<" "<<temp.second<<endl;
		while(temp.first>0 && pos[temp.second]!=temp.first){
			temp.first = pos[temp.second];
			pq.pop();
			if(temp.first>0)pq.push(temp);
			if(!pq.empty())temp = pq.top();
			else return ans;
			//cout<<temp.first<<" "<<temp.second<<" "<<pos[temp.second]<<endl;
		}
		pq.pop();
		if(temp.first<=0) return ans;
		ans += temp.first;
		//cout<<"fin temp: "<<temp.first<<" "<<temp.second<<" "<<ans<<endl;
		pos[temp.second] = 0;
		for(ll i: arr[temp.second]){
			pos[i] -= (val[temp.second] + val[i]);
			//cout<<"updated"<<i<<" -> "<<pos[i]<<endl;
			for(ll j: arr[i]){
				if(j==temp.second) continue;
				pos[j] -= (val[i]);
				//cout<<"updated"<<j<<" -> "<<pos[j]<<endl;
			}
			val[i] = 0;
		}
		val[temp.second]=0;
	}
	return ans;
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
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solve()<<"\n";
	}

	return 0;
}