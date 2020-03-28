#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

bool check(vector<int> arr, int n, int days, int p){
	int curr=0;
	for(int i=0;i<=n;i++){
		while(arr[i]>=days){
			curr++;
			arr[i] -= days;
		}
		if(curr>=p) return true;
	}
	return false;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,m,a;
	cin>>n>>m;
	vector<int> arr(101,0);
	//for(int i=0;i<=100;i++)arr[i]=0;
	for(int i=0;i<m;i++){
		cin>>a;
		arr[a]++;
	}
	sort(arr.begin(),arr.end(),greater<int>());
	int l=0, r=arr[0];
	int ans=0;
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		int mid=(l+r+1)/2;
		if(check(arr,100,mid,n)){
			l=mid;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}