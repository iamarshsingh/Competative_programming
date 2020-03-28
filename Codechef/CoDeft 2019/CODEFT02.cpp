#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n;
int maxx=0;

void rec(vector<int> sfreq, vector<vector<int>> &nfreq, int curr, int passed){
	if(curr>=n){
		maxx = max(maxx, passed);
		return;
	}
	vector<int> curfreq(sfreq);
	bool poss=true;
	for(int i=0;i<26;i++){
		curfreq[i] -= nfreq[curr][i];
		if(curfreq[i]<0){
			poss=false;
			break;
		}
	}
	rec(sfreq, nfreq, curr+1, passed);
	if(poss) rec(curfreq, nfreq, curr+1, passed+1);
}

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
	vector<int> sfreq(26, 0);
	for(int i=0;i<s.length();i++){
		sfreq[s[i]-'a']++;
	}

	cin>>n;
	vector<int> temp(26,0);
	vector<vector<int>> nfreq(n, temp);

	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<s.length();j++){
			nfreq[i][s[j]-'a']++;
		}
	}

	//cout<<"here"<<endl;

	rec(sfreq, nfreq, 0, 0);

	cout<<maxx<<endl;

	return 0;
}