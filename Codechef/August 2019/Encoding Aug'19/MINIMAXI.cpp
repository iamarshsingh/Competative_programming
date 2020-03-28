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
		ll n,a,maxx=0,minn=10000000000000000;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			if(a>maxx) maxx=a;
			if(a<minn) minn=a;
		}
		cout<<minn<<" "<<maxx<<endl;
	}

	return 0;
}