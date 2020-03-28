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
	string s[n];
	vector<int> per(26,0);
	vector<vector<int>> freq(n, per);
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<s[i].length(); j++){
			freq[i][s[i][j]-'a']++;
		}
	}
	int q;
	cin>>q;
	string temp;
	while(q--){
		cin>>temp;
		vector<int> per(26,0);
		for(int j=0;j<temp.length(); j++){
			per[temp[j]-'a']++;
		}
		bool yes=false;
		for(int i=0;i<n;i++){
			bool poss=true;
			for(int j=0;j<26;j++){
				if(per[j]!=freq[i][j]){
					poss=false;
					break;
				}
			}
			if(poss){
				yes=true;
				cout<<s[i]<<" ";
			}
		}
		if(!yes){
			cout<<"-";
		}
		cout<<"\n";
	}

	return 0;
}