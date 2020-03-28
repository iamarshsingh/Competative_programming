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
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n<11){
			cout<<"NO"<<endl;
		}
		else{
			bool poss=false;
			for(int i=0;i<s.length()-10;i++){
				if(s[i]=='8'){
					cout<<"YES"<<endl;
					poss=true;
					break;
				}
			}
			if(!poss) cout<<"NO"<<endl;
		}
	}

	return 0;
}