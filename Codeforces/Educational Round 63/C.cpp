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

	ll n,m;
	cin>>n>>m;
	ll arr[n];
	ll intervals[m];
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<m;i++)cin>>intervals[i];
	
	ll a = arr[1]-arr[0];
	for(int i=2;i<n;i++){
		a = __gcd(a,arr[i]-arr[i-1]);
	}

	bool poss=false;
	ll ans;
	for(int i=0;i<m;i++){
		if(a%intervals[i]==0){
			poss=true;
			ans = i+1;
			break;
		}
	}
	if(poss){
		cout<<"YES"<<endl;
		cout<<arr[0]<<" "<<ans<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}