#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int n,m;
string s,t;
vector<string> temp;
int curr[26];
vector<int> arr[26];

int main(){

	// //fastio
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	cin>>n;
	cin>>s;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>t;
		temp.push_back(t);
	}
	
	for(int i=0;i<26;i++){
		arr[i].push_back(0);
	}
	
	for(int i=0;i<n;i++){
		arr[s[i]-'a'].push_back(i+1);
	}
	for(int j=0;j<m;j++){
		
		for(int i=0;i<26;i++){
			curr[i] = 0;
		}
		// cout<<"here"<<endl;
		// cout<<temp[j]<<endl;
		// cout<<temp[j].length()<<endl;
		int k = temp[j].length();
		//cout<<"ggg"<<endl;
		int i=0;
		while(true){
			//cout<<i<<" <-"<<endl;
			if(i==k) break;
			//cout<<temp[j][i]-'a';
			curr[temp[j][i]-'a']++;
			//cout<<curr[temp[j][i]-'a']<<endl;
			i++;
			//cout<<i<<" "<<(i==k)<<endl;
		}

//		cout<<"here"<<endl;
		int ans=0;
		for(int i=0;i<26;i++){
			ans = max(ans,arr[i][curr[i]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}