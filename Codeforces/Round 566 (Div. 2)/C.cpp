#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

pair<int,char> countvowels(string s){
	int ans=0;
	char vol=' ';
	for(int i=0;i<s.length();i++){
		if(s[i]=='a'){
			ans++;
			vol = 'a';
		}
		else if(s[i]=='e'){
			ans++;
			vol = 'e';
		}
		else if(s[i]=='i'){
			ans++;
			vol = 'i';
		}
		else if(s[i]=='o'){
			ans++;
			vol = 'o';
		}
		else if(s[i]=='u'){
			ans++;
			vol = 'u';
		}
	}
	return {ans,vol};
}

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
	string s[n];
	//noofvowels, index
	vector<pair<int,int>> vovels[26];
	for(int i=0;i<n;i++){
		cin>>s[i];
		pair<int,char> a = countvowels(s[i]);
		if(a.second==' ')a.second='z';
		cout<<a.second<<endl;
		vovels[a.second-'a'].push_back({a.first, i});
	}
	for(int i=0;i<26;i++){
		sort(vovels[i].begin(), vovels[i].end());
		cout<<((char)'a'+i)<<" :"<<endl;
		for(int j=0;j<vovels[i].size();j++){
			cout<<vovels[i][j].first<<" "<<vovels[i][j].second<<endl;
		}
	}

	return 0;
}