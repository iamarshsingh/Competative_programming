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
	
	ll a,b,c;
	cin>>a>>b>>c;
	
	ll ans = min(min(a/3,b/2), c/2);
	a = a - (3*ans);
	b = b - (2*ans);
	c = c - (2*ans);

	ans = ans*7;
	ll maxx=0;
	ll arr[7]={1,1,2,3,1,3,2};
	for(int i=0;i<7;i++){
		ll cur[3] = {a,b,c};
		int here=0;
		//cout<<i<<endl;
		for(int j=(i+1)%7;j!=i;j=(j+1)%7){
			if(cur[arr[j]-1]>0){
				cur[arr[j]-1]--;
				here++;
			}
			else break;
		}
		if(here>maxx)maxx=here;
	}

	cout<<ans+maxx<<endl;
	return 0;
}