#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct node{
	ll key,dis;
	vector<ll> tot;
	vector<ll> roots;

	node(ll k,ll d){
		key=k;
		dis=d;
		tot=0;
	}
};

ll power(ll a, ll b){
	ll ans = 1;
	if(b==0) return 1;
	ans = power(a,b/2);
	if(b%2==0) return (ans*ans)%MOD;
	else return ((a*ans)%MOD * ans)%MOD;
}

ll calnodes(node* visited[], ll n){
	vector<ll> fin;
	ll curr = visited[n]->roots.size();
	if(curr==0){
		fin.push_back(0);
		return fin;
	}
	else{
		
	}
	ll temp = 0;
	for(ll i:visited[n]->roots){
		temp += calnodes(visited, i);
	}
	visited[n]->tot = fin;
	return ans;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll t;
	cin>>t;
	while(t--){
		ll n,q,a,b;
		cin>>n>>q;
		vector<ll> arr[n+1];
		for(ll i=0;i<n-1;i++){
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		node *visited[n+1];
		for(ll i=0;i<=n;i++){
			visited[i]=NULL;
		}

		deque<ll> d;
		d.push_back(1);
		visited[1] = new node(1,0);
		while(!d.empty()){
			ll curr = d.front();
			d.pop_front();
			ll dis = visited[curr]->dis;
			for(ll i:arr[curr]){
				if(visited[i]==NULL){
					visited[curr]->roots.push_back(i); 
					visited[i] = new node(i,dis+1);
					d.push_back(i);
				}
			}
		}
		
		calnodes(visited,1);

		for(ll i=1;i<=6;i++){
			cout<<i<<" "<<visited[i]->tot<<endl;
		}
		
		ll ans=0,v=0,y=0;
		while(q--){
			cin>>a>>b;
			v = (a^ans);
			y = (b^ans);
			//while(!d.empty())d.pop_front();
			ans = 0;
			ans = visited[v]->tot;
			/*
			d.push_back(v);
			ll dis = visited[v]->dis;
			ll ind=1;
			//cout<<"v y ans dis: "<<v<<" "<<y<<" "<<ans<<" "<<dis<<endl;
			while(!d.empty()){
				ll curr = d.front();
				d.pop_front();
				//cout<<curr<<": "<<endl;
				for(ll i:visited[curr]->roots){
					ind++;
					//cout<<(visited[i]->dis - dis)<<" "<<power(y,ind - 1)<<endl;
					ans = ( ((visited[i]->dis - dis) * power(y,ind - 1))%MOD + ans )%MOD;
					//cout<<i<<" "<<ans<<endl;
					d.push_back(visited[i]->key);	
				}
				///cout<<endl;
			}
			*/
			cout<<ans<<endl;
		}

	}

	return 0;
}