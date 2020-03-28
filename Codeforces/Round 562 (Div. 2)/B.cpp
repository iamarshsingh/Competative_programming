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

	int n,m;
	bool done=false;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>arr[i][j];
	}
		
	int ans[n]={1};
	int temp=arr[0][0];
	for(int i=1;i<n;i++){
		temp = temp ^ arr[i][0];
		ans[i] = 1;
	}

	if(temp==0){
		bool poss=false;
		for(int i=0;i<n;i++){
			for(int j=1;j<m;j++){
				if(arr[i][j]!=arr[i][0]){
					ans[i] = j+1;
					poss=true;
					break;
				}
			}
			if(poss) break;
		}

		if(poss){
			cout<<"TAK"<<endl;
			for(int i=0;i<n;i++) cout<<ans[i]<<" ";
			cout<<endl;
		}
		else{
			cout<<"NIE"<<endl;
		}
	}
	else{
		cout<<"TAK"<<endl;
		for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}