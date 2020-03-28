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
	for(int c = 1;c<=t;c++){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string ans="";
		for(int i=0;i<s.length();i++){
			if(s[i]=='E'){
				ans+="S";
			}
			else{
				ans+="E";
			}
		}
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}

	return 0;
}