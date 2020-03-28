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

	int n,a=0;
	cin>>n;
	int grid[n][n];
	for(int i=0;i<n;i+=4){
		for(int j=0;j<n;j+=4){
			for(int k=0;k<4;k++){
				for(int l=0;l<4;l++){
					grid[i+k][j+l] = a++;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}	

	return 0;
}