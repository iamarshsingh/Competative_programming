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

	int b,g,n;
	cin>>b>>g>>n;
	int maxb = min(b,n);
	int maxg = min(g,n);
	int ans=0;
	for(int i=0;i<=maxb;i++){
		if(i+maxg>=n){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}