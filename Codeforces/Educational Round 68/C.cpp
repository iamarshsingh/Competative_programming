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
		string s;
		string t;
		string p;
		cin>>s>>t>>p;
		int j=0;
		bool poss = true;
		for(int i=0;i<s.length();i++){
			while(j<t.length() && t[j]!=s[i]){
				j++;
			}
			if(j>=t.length()){
				poss = false;
				break;
			}
			j++;
		}
		if(poss){
			int req[26]={0};
			int fr[26]={0};
			for(int i=0;i<t.length();i++){
				req[t[i]-'a']++;
			}
			for(int i=0;i<s.length();i++){
				fr[s[i]-'a']++;
			}
			for(int i=0;i<p.length();i++){
				fr[p[i]-'a']++;	
			}
			for(int i=0;i<26;i++){
				if(fr[i]<req[i]){
					cout<<"NO"<<endl;
					poss=false;
					break;
				}
			}
			if(poss){
				cout<<"YES"<<endl;
			}
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}