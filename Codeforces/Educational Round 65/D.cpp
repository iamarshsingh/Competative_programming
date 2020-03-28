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
	vector<pair<int,pair<int,int>>> instack;
	vector<pair<int,int>> v;
	int maxx=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(') v.push_back({v.size(), i});
		else{
			pair<int,int> temp = v[v.size()-1];
			v.pop_back();
			instack.push_back({temp.first, {temp.second,i}});
			if(temp.first>maxx)maxx=temp.first;
		}
	}
	int ans[n];
	for(int i=0;i<instack.size();i++){
		if(instack[i].first<=(maxx/2)){
			ans[instack[i].second.first]=0;
			ans[instack[i].second.second]=0;
		}
		else{
			ans[instack[i].second.first]=1;
			ans[instack[i].second.second]=1;
		}
	}

	for(int i=0;i<n;i++){
		cout<<ans[i];
	}
	cout<<endl;

	return 0;
}