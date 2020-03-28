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

	ll t;
	cin>>t;
	while(t--){
		ll a,b,n,x,maxx=0,best=0;
		cin>>n>>x;
		for(ll i=0;i<n;i++){
			cin>>a>>b;
			if(a>=b){
				best = max(best, a-b);
			}
			maxx = max(maxx, a);
		}
		if(maxx>=x){
			cout<<1<<endl;
		}
		else if(best>0){
			int ans = 1;
			x -= maxx;
			ans += (x/best);
			ans += ((x%best!=0)?1:0);
			cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}

	return 0;
}