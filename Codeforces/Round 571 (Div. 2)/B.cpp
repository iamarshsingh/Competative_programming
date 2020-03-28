#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll solve(ll a, ll b){
	ll ans=0;
	ll temp = (a/3);
	if(a%3==2) temp++;
	if(b==3){
		ans = max((ll)(ceil(a/(2.0)) * (b/3)), (temp*2));
	}
	else if(b%3==0){
		ans = ceil(a/(2.0)) * (b/3);
	}
	else if(b%3==1){
		ans = ceil(a/(2.0)) * (b/3);
		ans = ans + (temp);
	}
	else if(b%3==2){
		ans = ceil(a/(2.0)) * ((b/3) + 1);
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

	ll a,b,x,y;
	cin>>x>>y;
	
	cout<<max(solve(x,y), solve(y,x))<<endl;

	return 0;
}