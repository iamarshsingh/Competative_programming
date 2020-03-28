#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll k[n];
		pair<ll,ll> points[n];
		for(int i=0;i<n;i++){
			cin>>points[i].first;
			cin>>points[i].second;
		}
		for(int i=0;i<n;i++){
			cin>>k[i];
		}
		sort(k,k+n);
		ll dissum[n];
		for(int i=0;i<n;i++){
			dissum[i]=0;
			for(int j=0;j<n;j++){
				if(i==j)continue;
				dissum[i] += abs(points[j].first - points[i].first) + abs(points[j].second - points[i].second);
			}
			//cout<<dissum[i]<<" ";
		}
		//cout<<endl;
		sort(dissum,dissum+n);
		ll ans=0;
		for(int i=0;i<n;i++){
			//cout<<dissum[i]<<" ";
			ans += (dissum[i]*k[n-i-1]);
		}
		//cout<<endl;
		cout<<ans<<endl;
	}

	return 0;
}