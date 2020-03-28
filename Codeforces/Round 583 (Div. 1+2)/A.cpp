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

	ll n,d,e,a,b;
	cin>>n>>d>>e;
	e=5*e;

	ll curre = 0, ans = MOD;
	while(curre<=n){
		ans = min(ans, (n-curre)%d);
		curre += e;
	}
	cout<<ans<<endl;
	return 0;
}