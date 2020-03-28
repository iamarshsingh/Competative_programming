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

	ll a,b,n,q,maxx=0,maxxind=0;
	cin>>n>>q;
	deque<ll> arr(n);
	for(ll i=0;i<n;i++){
		cin>>a;
		arr[i] = a;
		if(a>maxx){
			maxx = a;
			maxxind = i;
		}
	}
	vector<pair<ll,ll>> ans1;
	vector<pair<ll,ll>> ans2;
	for(ll i=0;i<maxxind;i++){
		a = min(arr[0],arr[1]);
		b = max(arr[0],arr[1]);
		ans1.push_back({arr[0],arr[1]});
		arr.pop_front(); arr.pop_front();
		arr.push_front(b);
		arr.push_back(a);
	}

	for(int i=0;i<n-1;i++){
		a = min(arr[0],arr[1]);
		b = max(arr[0],arr[1]);
		ans2.push_back({arr[0],arr[1]});
		arr.pop_front(); arr.pop_front();
		arr.push_front(b);
		arr.push_back(a);
	}

	ll m;
	while(q--){
		cin>>m;
		if(m<=maxxind){
			cout<<ans1[m-1].first<<" "<<ans1[m-1].second<<endl;
		}
		else{
			m = m - maxxind-1;
			m = m%(n-1);
			cout<<ans2[m].first<<" "<<ans2[m].second<<endl;
		}
	}
	return 0;
}