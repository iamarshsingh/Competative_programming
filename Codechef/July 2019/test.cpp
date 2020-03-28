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

	int fil[36] = {3,3,4,4,3,3,3,3,4,4,3,3,2,2,3,3,2,2,2,2,3,3,2,2,1,1,2,2,1,1,1,1,2,2,1,1};
	int cur[36];
	string s;
	string grid[6];
	int done=0;
	int maxx=0;
	for(int i=0;i<6;i++){
		cin>>s;
		for(int j=0;j<s.length();j++){
			if(s[j]=='-') continue;
			if(s[j]=='*'){
				cur[done] = 0;
				done++;
			}
			else{
				cur[done] = fil[done];
				if(cur[done]>maxx) maxx = cur[done];
				done++;
			}
		}
		grid[i] = s;
	}
	//cout<<temp<<endl;
	done=0;
	bool poss=false;
	for(int i=0;i<6;i++){
		string s = grid[i];
		for(int j=0;j<8;j++){
			if(s[j]=='-') continue;
			if(s[j]=='*'){
				done++;
			}
			else{
				if(cur[done]==maxx){
					grid[i][j] = 'P';
					poss = true;
					break;
				}
				done++;
			}
		}
		if(poss) break;
	}
	for(int i=0;i<6;i++){
		cout<<grid[i]<<endl;
	}
	return 0;
}