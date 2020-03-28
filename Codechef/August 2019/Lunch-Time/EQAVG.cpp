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
		int a,n,k;
		cin>>n>>k;
		map<int,int> m;
		for(int i=0;i<n;i++){
			cin>>a;
			mp[a]++;
		}
		if(m.size()>k){
			cout<<"NO"<<endl;
		}
		else{
			int ans[n];
			auto it = m.begin();
			bool poss = false;
			for(int i=0;i<n;i++){
				if(it==m.end()) it = m.begin();
				if((*it0).second==1){
					ans[i] = (*it).first;
					m.erase((*it).first)
				}
				else{
					ans[i] = (*m).first;
					m[(*it).first]--;
				}
				if(i>=k && ans[i]!=ans[i-k]){
					poss=false;
					break;
				}
			}
		}
	}	

	return 0;
}