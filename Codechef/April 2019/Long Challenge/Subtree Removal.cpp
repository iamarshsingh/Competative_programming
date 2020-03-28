#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll n,x,a,b;
ll sums[100005];
ll vals[100005];
bool visited[100005];
ll ans[100005];

ll iter(vector<ll> arr[], ll node){
	ll here = vals[node];
	for(ll i: arr[node]){
		if(!visited[i]){
			visited[i]=true;
			ll curr = iter(arr, i);
			//cout<<here + (-1*x)<<endl;
			here = max(here + curr, here + (-1*x));
			//cout<<node<<" "<<i<<" "<<here<<endl;
		}
	}
	ans[node] = max(here,-1*x);
	return ans[node];
}

int main(){

	fastio();

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		cin>>n>>x;

		vector<ll> arr[n+1];
		for(int i=0;i<n;i++){
			ans[i+1]=0;
			visited[i+1]=false;
			sums[i+1]=0;
			//connects[i+1]=0;
			cin>>a;
			vals[i+1] = a;
		}
		for(int i=0;i<n-1;i++){
			cin>>a>>b;
			//connects[a]++;
			//connects[b]++;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		visited[1]=true;
		ll fin = iter(arr,1);
		cout<<fin<<endl;
	}

}