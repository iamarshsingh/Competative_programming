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
		string a,b;
		cin>>a>>b;
		int i=0,j=0;
		bool poss=false;
		while(i<a.length() || j<b.length()){
			if(i<a.length() && j<b.length() && a[i]==b[j]){
				i++;
				j++;
			}
			else if(i>0 && a[i-1]==b[j] && j<b.length()){
				j++;
			}
			else{
				poss=true;
				break;
			}
		}
		if(poss){
			//cout<<"here"<<endl;
			cout<<"NO"<<endl;
		}
		else{
			if(i<a.length() || j<b.length()){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
	}

	return 0;
}