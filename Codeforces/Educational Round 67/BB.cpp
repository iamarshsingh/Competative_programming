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
	cin>>n;
	vector<int> arr[26];
	for(int i=0;i<26;i++){
		arr[i].push_back(0);
	}
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		arr[s[i]-'a'].push_back(i+1);
	}
	int m;
	cin>>m;
	cin>>s;
	cout<<"h";
	while(m--){
		cout<<"h";
		cout<<"h";
		int curr[26]={0};
		for(int i=0;i<s.length();i++){
			curr[s[i]-'a']++;
		}
		cout<<"here";
		int ans=0;
		for(int i=0;i<26;i++){
			ans = max(ans,arr['a'+i][curr['a'+i]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}