#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool check(string s){
	if(s[0]==s[1]) return true;
	if(s[0]==s[2]) return true;
	if(s[1]==s[2]) return true;
	return false;
}

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
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		int ans[n+1]={0};
		ans[0]=0;
		//cout<<"here"<<endl;

		for(int i=0;i<n-2;i++){
			//cout<<i<<endl;
			if(check(s.substr(i,3))){
				ans[i+1] = ans[i]+1;
			}
			else{
				ans[i+1] = ans[i];
			}
		}
		int a,b;
		while(q--){
			cin>>a>>b;
			if(b<a+2){
				cout<<"NO"<<endl;
			}
			else{
				if(ans[b-2]-ans[a-1] > 0){
					cout<<"YES"<<endl;
				}
				else cout<<"NO"<<endl;
			}
		}
	}

	return 0;
}