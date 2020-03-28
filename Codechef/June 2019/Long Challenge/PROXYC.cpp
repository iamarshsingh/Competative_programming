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
		int d;
		cin>>d;
		string s;
		cin>>s;
		int pres=0,poss=0,req;
		for(int i=0;i<d;i++){
			if(s[i]=='A'){
				if(i==0 || i==1 || i==d-2 || i==d-1) continue;
				if( ( s[i-2]=='P' || s[i-1]=='P' ) && (s[i+1]=='P' || s[i+2]=='P') ){
					poss++;
					//cout<<"poss: "<<i<<endl;
				}
			}
			else{
				pres++;
			}
		}
		req = ceil( (double)d * 0.75 );
		if(poss+pres>=req){
			cout<<max(0,req-pres)<<endl;
		}
		else cout<<-1<<endl;
	}

	return 0;
}