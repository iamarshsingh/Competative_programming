#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int arr[1003][1003];

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
	#endif

	int n,m,q;
	cin>>n>>m>>q;
	string s;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			arr[i][j] = 0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='1'){
				arr[i][j] = 1;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			arr[i][j] += arr[i+1][j] + arr[i][j+1] - arr[i+1][j+1];
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int c,a,b,x=0,y=0;
	int cover[4] = {0,0,n,m};
	while(q--){
		cin>>c;
		if(c==1){
			cin>>a>>b;
			y += a;
			x += b;
			cover[0] = max(cover[0], min(x,n));
			cover[1] = max(cover[1], min(y,m));
			cover[2] = min(cover[2], max(n+x,0));
			cover[3] = min(cover[3], max(m+y,0));
		}
		else if(c==2){
			if(cover[0]<=cover[2] && cover[1]<=cover[3]){
				cout<<(arr[cover[0]][cover[1]] - arr[cover[0]][cover[3]] - arr[cover[2]][cover[1]] + arr[cover[2]][cover[3]])<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		//cout<<cover[0]<<" "<<cover[1]<<" "<<cover[2]<<" "<<cover[3]<<endl;
	}
	

	return 0;
}