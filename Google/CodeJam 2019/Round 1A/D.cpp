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
	for(int c=1;c<=t;c++){
		int n;
		cin>>n;
		string s[n];
		bool done[n]={false};
		for(int i=0;i<n;i++){
			cin>>s[i];
			done[i]=false;
		}

		int ans=0;
		map<string,int> mp;
		for(int i=0;i<n;i++){
			if(!done[i]){
				int maxx=0;
				int maxxind=0;
				string maxstr="";
				for(int j=i+1;j<n;j++){
					if(!done[j]){
						int curr=0;
						string curstr="";
						int len = min(s[i].length(), s[j].length());
						for(int k=0;k<len;k++){
							if(s[i][s[i].length()-k-1] == s[j][s[j].length()-k-1]){
								curr++;
								curstr = string(1,s[i][s[i].length()-k-1]) + curstr;
							}
							else break;
						}
						if(curr>maxx){
							maxx=curr;
							maxxind=j;
							maxstr = curstr;
						}
					}
				}

				if(maxx>0 && mp[maxstr]==0){
					cout<<i<<" "<<maxxind<<" "<<maxstr<<endl;
					done[i]=true;
					done[maxxind]=true;
					ans = ans + 2;
					mp[maxstr]++;
				}
			}
		}

		cout<<"Case #"<<c<<": "<<ans<<endl;
	}

	return 0;
}