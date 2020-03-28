#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

char arr[105][105];
int n;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

void dfs(int i, int j, char c){
	arr[i][j] = c;
	for(int t=0;t<8;t++){
		int x = i+dx[t];
		int y = j+dy[t];
		if(x>=0 && x<n && y>=0 && y<n && arr[x][y]=='0'){
			dfs(x,y,(c=='W')?'B':'W');
		}
	}
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	cin>>n;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j] = '0';
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == '0'){
				dfs(i,j,'W');
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j];
		}
		cout<<"\n";
	}

	return 0;
}