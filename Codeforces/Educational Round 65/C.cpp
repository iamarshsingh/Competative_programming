#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int root(int par[], int n){
	//cout<<n<<" "<<par[n]<<endl;
	if(n==par[n]) return n;
	else{
		par[n] = root(par,par[n]);
		return par[n];
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

	int n,m;
	cin>>n>>m;
	int ans[n+1]={0};
	int par[n+1];
	for(int i=1;i<n+1;i++){
		ans[i]=0;
		par[i]=i;
	}
	int a;
	for(int i=0;i<m;i++){
		cin>>a;
		if(a==0) continue;
		int arr[a];
		for(int j=0;j<a;j++){
			cin>>arr[j];
		}
		sort(arr,arr+a);

		for(int j=1;j<a;j++){
			par[root(par,arr[j])] = root(par,arr[0]);
		}
	}

	for(int i=1;i<=n;i++){
		ans[root(par,i)]++;
		//cout<<"root of "<<i<<" is "<<root(par,i)<<endl;
	}

	for(int i=1;i<=n;i++){
		cout<<ans[root(par,i)]<<" ";
	}
	cout<<endl;

	return 0;
}