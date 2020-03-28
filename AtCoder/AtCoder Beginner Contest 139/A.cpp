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

	string a,b;
	cin>>a>>b;
	int ans=0;
	for(int i=0;i<3;i++){
		if(a[i]==b[i]) ans++;
	}
	cout<<ans<<endl;

	return 0;
}