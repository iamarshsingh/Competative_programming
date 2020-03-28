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

	int n,m,a,b;
	cin>>n>>m>>a>>b;

	char arr[n][m];

	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++){
			arr[i][j] = '0';
		}
		for(int j=a;j<m;j++){
			arr[i][j] = '1';
		}
	}

	for(int i=b;i<n;i++){
		for(int j=0;j<a;j++){
			arr[i][j] = '1';
		}
		for(int j=a;j<m;j++){
			arr[i][j] = '0';
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cout<<arr[i][j];
		cout<<endl;
	}

	return 0;
}