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
		int n,f,k;
		char c;
		cin>>n>>f>>k;
		cin>>c;
		string s;
		cin>>s;
		if(f>k){
			cout<<-1<<endl;
		}
		else{
			int ans=0,curr=0;
			int l=0, r=k-1;
			for(int i=0;i<=r;i++){
				if(s[i]==c)curr++;
			}
			if(curr==f){
				cout<<0<<endl;
			}
			else{
				while(ans!=n && curr!=f){
					if(s[r]==c) curr--;
					l--;
					r--;
					if(l<0) l+=n;
					if(r<0) r+=n;
					if(s[l]==c) curr++;
					ans++;
				}
				if(ans>=n){
					cout<<-1<<endl;
				}
				else{
					cout<<ans<<endl;
				}
			}
		}
	}

	return 0;
}