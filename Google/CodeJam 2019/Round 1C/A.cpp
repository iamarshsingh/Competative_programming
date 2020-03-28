#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;
char ans[500];
int maxx;

bool solve(string s[], int n){

	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=-1;
	}

	for(int i=0;i<500;i++){
		//P R S
		int curr[3] = {0,0,0};
		for(int j=0;j<n;j++){
			if(arr[j]==-1){
				if(s[j][i%s[j].length()]=='P') curr[1]=1;
				else if(s[j][i%s[j].length()]=='R') curr[2]=1;
				else if(s[j][i%s[j].length()]=='S') curr[0]=1;
			}
		}

		if(curr[0]==0 && curr[1]==0 && curr[2]==0) return true;
		int sum = curr[0] + curr[1] + curr[2];

		if(sum==1){
			if(curr[0]==1) ans[i]='P';
			else if(curr[1]==1) ans[i]='R';
			else if(curr[2]==1) ans[i]='S';	
			maxx=i;
			return true;
		}

		else if(sum==2){
			if(curr[0]==1 && curr[1]==1) ans[i]='P';
			if(curr[0]==1 && curr[2]==1) ans[i]='S';
			if(curr[1]==1 && curr[2]==1) ans[i]='R';
			maxx=i;
		}

		else{
			maxx=i;
			return true;
		}

		for(int j=0;j<n;j++){
			if(arr[j]==-1){
				if(s[j][i%s[j].length()]=='P' && ans[i]=='S') arr[j]=1;
				else if(s[j][i%s[j].length()]=='R' && ans[i]=='P') arr[j]=1;
				else if(s[j][i%s[j].length()]=='S' && ans[i]=='R') arr[j]=1;
			}
		}
	}
	return false;
}

int main(){
	

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		int n;
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		if(solve(s,n)){
			cout<<"Case #"<<c<<": ";
			for(int i=0;i<=maxx;i++){
				cout<<ans[i];
			}
			cout<<endl;
		}
		else cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
	}

	return 0;
}