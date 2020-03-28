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
		int a,n,ans=0;
		cin>>n;
		map<int,int> m;
		for(int i=0;i<n;i++){
			cin>>a;
			if(a%2==0)ans += m[a/2];
			ans += m[2*a];
			m[a]++;
		}
		cout<<ans<<endl;
	}

	return 0;
}