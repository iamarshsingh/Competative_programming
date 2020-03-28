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
		int r,c;
		cin>>r>>c;
		string grid[r];
		for(int i=0;i<r;i++){
			cin>>grid[i];
		}
		int ans[r][c][max(r,c)+1];

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				for(int k=0;k<=max(r,c);k++){
					ans[i][j][k]=0;
				}
			}
		}

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				int rr=0,cc=0;
				bool move = false;
				switch(grid[i][j]){
					case 'U' :	rr = -1;
								move = true;
								break;
					case 'D' :	rr = 1;
								move = true;
								break;
					case 'L' :	cc = -1;
								move = true;
								break;
					case 'R' :	cc = 1;
								move = true;
								break;	
					default : break;
				}
				if(move){
					//cout<<"here "<<rr<<" "<<cc<<endl;
					int curR=i+rr,curC=j+cc;
					//cout<<curR<<" "<<curC<<endl;
					int cur=0;
					while(curR<r && curR>=0 && curC<c && curC>=0){
						//cout<<curR<<" "<<curC<<" "<<cur<<endl;
						if(grid[curR][curC]=='#'){
							break;
						}
						else{
							ans[curR][curC][cur]++;
						}
						curR += rr;
						curC += cc;
						cur++;
					}
				}
			}
		}
		ll res = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				for(int k=0;k<=max(r,c);k++){
					//cout<<i<<" "<<j<<" "<<k<<" : "<<ans[i][j][k]<<endl;
					res += ( (ans[i][j][k] * (ans[i][j][k]-1))/2);
				}
			}
		}
		cout<<res<<endl;
	}

	return 0;
}