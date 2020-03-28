#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll n,k;
	cin>>n>>k;
	vector<ll> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr.begin(),arr.end());

	vector<ll>::iterator i,j,savedi,savedj;
	ll maxx = 0,ans=0;
	for(int tot=0;tot<k;tot++){
		//cout<<"1: "<<maxx<<" "<<arr.size()<<endl;
		savedi = arr.begin();
		savedj = arr.begin();
		maxx=0;
		for(i=arr.begin();i!=arr.end();i++){
			j = upper_bound(arr.begin(),arr.end(),*i + 5);
			if(j-i > maxx){
				maxx = j-i;
				savedi = i;
				savedj = j;
			}
		}
		if(savedj==savedi && arr.size()>1){
			ans++;
			break;
		}
		arr.erase(savedi,savedj);
		//cout<<"2: "<<maxx<<" "<<arr.size()<<endl;
		ans += maxx;
	}
	cout<<max(k,ans)<<endl;
	return 0;
}