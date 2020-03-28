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

	string s;
	cin>>s;
	if(s=="0"){
		cout<<0<<endl;
		return 0;
	}
	int ones=0;
	for(int i=0;i<s.length();i++) if(s[i]=='1') ones++;
	int ans = ((s.length()+1)/2);
	if(s.length()%2==1 && ones==1) ans--;
	cout<<ans<<endl;
	return 0;
}