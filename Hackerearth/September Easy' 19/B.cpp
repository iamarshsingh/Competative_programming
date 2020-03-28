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

	int q;
	cin>>q;
	ll l,c;
	while(q--){
		cin>>l>>c;
		cout<<((l-1) + (c))<<endl;
	}

	return 0;
}