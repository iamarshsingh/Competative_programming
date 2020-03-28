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

	int n,t,ones=0,ans=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==1)ones++;
	}

	if(ones>0){
		cout<<n-ones<<endl;
		return 0;
	}

	vector<int> gcds;
	int minn=n;
	bool poss=false;
	bool fin=false;
	for(int i=0;i<n;i++){
		int curr = arr[i];
		int t=0;
		poss=false;
		for(int j=i+1;j<n;j++){
			curr = __gcd(curr,arr[j]);
			if(curr==1){
				poss=true;
				break;
			}
			t++;
		}
		if(poss){
			fin=true;
			if(t<minn)minn=t;
		}
	}
	if(fin){
		cout<<n+minn<<endl;
	}
	else cout<<-1<<endl;

	return 0;
}