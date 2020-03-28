#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll arr[100005];

bool comp(ll a, ll b){
	return arr[a]>arr[b];
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n,a,b;
	cin>>n;
	ll pos[n];
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ans += (b*(n-1));
		arr[i] = a-b;
		pos[i] = i;
	}
	sort(pos,pos+n,comp);
	/*
	cout<<ans<<endl;
	
	for(int i=0;i<n;i++){
		cout<<pos[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	*/
	for(int i=0;i<n;i++){
			ans += (arr[pos[i]] * i);
	}

	cout<<ans<<endl;
	return 0;
}