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

	int h,w;
	cin>>h>>w;
	char arr[h][w];
	ll ans[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>arr[i][j];
			ans[i][j]=0;
		}
	}

	ans[0][0]=1;
	
	for(int i=1;i<h;i++){
		if(arr[i][0]=='.'){
			ans[i][0]=1;
		}
		else if(arr[i][0]=='#'){
			break;
		}
	}
	
	for(int i=1;i<w;i++){
		if(arr[0][i]=='.'){
			ans[0][i]=1;
		}
		else if(arr[0][i]=='#'){
			break;
		}
	}

	for(int i=1;i<h;i++){
		for(int j=1;j<w;j++){
			if(arr[i][j]=='.'){
				ans[i][j]=(ans[i][j-1] + ans[i-1][j])%MOD;
			}
			else if(arr[i][0]=='#'){
				ans[i][j]=0;
			}
		}
	}
	
	cout<<ans[h-1][w-1]<<endl;

	return 0;
}