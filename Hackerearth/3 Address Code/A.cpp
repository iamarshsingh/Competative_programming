#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		string s;
		char ans='a';
		int maxx=0;
		cin>>s;
		int n = s.length();
		int freq[26]={0};
		for(int i=0;i<n;i++){
			freq[s[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			if(freq[i]>maxx){
				maxx=freq[i];
				ans='a'+i;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}