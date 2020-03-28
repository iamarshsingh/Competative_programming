#include <bits/stdc++.h>
#define ll unsigned long long
#define MOD 1000000007

using namespace std;

ll power(ll a, ll b, ll y){
	
	ll ans = 1;

	while(b>0){

		if(b & 1)
			ans = (ans * a);

		b = b >> 1;
		a = (a*a);
	}
	return ans;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cout<<power(2,63,0)<<endl;

	return 0;
}