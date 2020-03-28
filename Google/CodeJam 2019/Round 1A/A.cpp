#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

bool comp(pair<string,pair<int,int>> a, pair<string,pair<int,int>> b){
	return a.first.length()>b.first.length();
}

map<string,int> m;

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
	for(int c=1;c<=t;c++){
		m.clear();
		int n;
		cin>>n;
		string s[n];
		bool done[n]={false};
		for(int i=0;i<n;i++){
			cin>>s[i];
			done[i]=false;
		}

		
		vector<pair<string,pair<int,int>>> mp;
		for(int i=0;i<n;i++){

			for(int j=i+1;j<n;j++){
				int curr=0;
				string curstr="";
				int len = min(s[i].length(), s[j].length());
				for(int k=0;k<len;k++){
					if(s[i][s[i].length()-k-1]==s[j][s[j].length()-k-1]){
						curr++;
						curstr = string(1,s[i][s[i].length()-k-1]) + curstr;
					}
					else break;
				}
				if(curr>0){
					mp.push_back({curstr,{i,j}});
				}
			
			}

		}

		sort(mp.begin(), mp.end(), comp);
		int ans=0;
		
		for(int i=0;i<mp.size();i++){
			//cout<<mp[i].first<<endl;
			if(m[mp[i].first]==0){
				//cout<<mp[i].second.first<<" "<<mp[i].second.second<<endl;
				if(!done[mp[i].second.first] && !done[mp[i].second.second]){
					m[mp[i].first]++;
					done[mp[i].second.first]=true;
					done[mp[i].second.second]=true;
					ans += 2;
				}
			}
		}

		cout<<"Case #"<<c<<": "<<ans<<endl;
	}

	return 0;
}