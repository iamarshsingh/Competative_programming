#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll const INFL = (ll)1e18 + 1e6;

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
		ll n,w,p,v,ans=0;
		cin>>n;
		vector<tuple<ll,ll,ll>> arr;
		for(int i=0;i<n;i++){
			cin>>w>>p>>v;
			arr.push_back({w,p,v});
		}

		ll part1 = (n/2);
		ll part2 = n-part1;
		vector<pair<ll,ll>> vars;
		for(ll i=0;i<1<<part1;i++){
			ll timesum = 0;
			ll cost = 0;
			bool poss=true;
			for(ll j=0;j<part1; j++){
				if(i & (1<<j)){
					tie(w,p,v) = arr[j];
					if(timesum>w){
						poss=false;
						break;
					}
					timesum+=p;
					cost+=v;
				}
			}
			if(poss){
				vars.push_back({timesum, cost});
			}
		}

		sort(vars.begin(), vars.end());
		for (int i = 1; i < vars.size(); i++) {
			vars[i].second = max(vars[i].second, vars[i - 1].second);
		}

		for(ll i=0;i<1<<part2;i++){
			ll timesum = 0;
			ll cost = 0;
			ll max_sum = INFL;
			for(ll j=0;j<part2; j++){
				if(i & (1<<j)){
					tie(w,p,v) = arr[part1+j];
					max_sum=min(max_sum, w-timesum);
					timesum+=p;
					cost+=v;
				}
			}
			if(max_sum>=0){
				int pos = upper_bound(vars.begin(), vars.end(), make_pair(max_sum, (ll)INFL)) - vars.begin() - 1;
				ans = max(ans, cost + vars[pos].second);
			}
		}

		cout<<ans<<"\n";
	}

	return 0;
}