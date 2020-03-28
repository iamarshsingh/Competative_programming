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

	int a,b;
	cin>>a>>b;
	int curr=1,ans=0;
	while(curr<b){
		curr--;
		curr += (a);
		ans++;
	}
	cout<<ans<<endl;

	return 0;
}