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
	
	int t;
	cin>>t;
	while(t--){
		ll n,s,t;
		cin>>n>>s>>t;
		ll b = (s+t - n);
		s = s-b;
		t = t-b;
		cout<<(max(s,t)+1)<<endl;
	}

	return 0;
}