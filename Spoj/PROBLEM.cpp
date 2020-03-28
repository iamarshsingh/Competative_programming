#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		int ans=0;
		for(int i=0;i<s.length();i++){
			switch(s[i]){
				case '0':
				case '6':
				case '9': ans++; break;
				case '8': ans++; ans++; break;
				default: break;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}