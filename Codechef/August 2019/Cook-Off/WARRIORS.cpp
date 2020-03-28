#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 10000000000
using namespace std;

ll power(ll a, ll b){
	if(b==0) return 1;
	ll ans = power(a,b/2);
	if(b%2==0) return (ans*ans);
	else return (a*ans*ans);
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
		int n,q;
		cin>>n>>q;
		vector<ll> arr(n,0);
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr.begin(), arr.end());
		vector<ll> dp(n,0);
		ll curr=1,beg=1;
		for(int i=0;i<n;i++){
			if(curr < INF && curr<=arr[i]){
				//cout<<curr<<endl;
				if(i>=33){
					curr = MOD;
					beg++;
				}
				else{
					//cout<<arr[i]<<" "<<curr<<endl;
					ll diff = arr[i] - curr + 1;
					ll p = ceil(((double) diff) / power(2,i));
					curr += (p*power(2,i));
					beg += p;
				}
			}
			dp[i] = beg;
			//cout<<i<<" "<<curr<<" "<<beg<<endl;
			if(curr<INF){
				curr = curr - arr[i];
				curr = curr*2;
			}
		}
		// for(int i=0;i<n;i++) cout<<dp[i]<<" ";
		// cout<<endl;
		ll a;
		while(q--){
			cin>>a;
			ll ans = upper_bound(dp.begin(), dp.end(), a) - dp.begin();
			cout<<ans<<endl;
		}
	}

	return 0;
}