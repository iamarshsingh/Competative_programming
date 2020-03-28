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
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='2' || s[i]=='4' || s[i]=='6' || s[i]=='8'){
			ans = ans + (i+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}