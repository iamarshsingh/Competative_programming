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
		
		int x,y,p,q;
		cin>>p>>q;
		int X[q+2]={0};
		int Y[q+2]={0};
		char d;

		while(p--){
			cin>>x>>y>>d;
			if(d=='N'){
				Y[y+1]++;
			}
			else if(d=='S'){
				Y[0]++;
				Y[y]--;
			}
			else if(d=='E'){
				X[x+1]++;
			}
			else if(d=='W'){
				X[0]++;
				X[x]--;
			}
		}
		int curr=0;
		for(int i=0;i<=q;i++){
			curr+=X[i];
			X[i] = curr;	
		}
		curr=0;
		for(int i=0;i<=q;i++){
			curr+=Y[i];
			Y[i] = curr;	
		}

		int ansx=0;
		int ansy=0;
		for(int i=0;i<=q;i++){
			if(X[i]>X[ansx])ansx=i;
			if(Y[i]>Y[ansy])ansy=i;
		}

		cout<<"Case #"<<c<<": "<<ansx<<" "<<ansy<<endl;
	}

	return 0;
}