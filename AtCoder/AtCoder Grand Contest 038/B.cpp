#include <bits/stdc++.h>
#define ll long long int
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

	int n,k,ans=1,sortcount=1;

	cin>>n>>k;

	deque<int> minn;
	deque<int> maxx;

	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	for(int i=0;i<k;i++){
		while(!minn.empty() && minn.back()>arr[i]){
			minn.pop_back();
		}
		minn.push_back(arr[i]);

		while(!maxx.empty() && maxx.back()<arr[i]){
			maxx.pop_back();
		}
		maxx.push_back(arr[i]);
		if(i>0 && arr[i]>arr[i-1]) sortcount++;
		else sortcount = 1;
	}

	bool lostminn = false, gainmaxx=false, sortdone = false;

	if(sortcount>=k) sortdone = true;

	for(int i=k;i<n;i++){
		lostminn = false;
		gainmaxx=false;
		
		if(arr[i-k]==minn.front()){
			lostminn=true;
			minn.pop_front();
		}
		if(arr[i-k]==maxx.front()){
			maxx.pop_front();
		}

		while(!minn.empty() && minn.back()>arr[i]){
			minn.pop_back();
		}
		minn.push_back(arr[i]);

		while(!maxx.empty() && maxx.back()<arr[i]){
			maxx.pop_back();
		}
		maxx.push_back(arr[i]);

		if(arr[i]==maxx.front()) gainmaxx = true;

		if(arr[i]>arr[i-1]) sortcount++;
		else sortcount = 1;

		if(lostminn && gainmaxx){

		}
		else{
			//cout<<i<<" "<<sortcount<<"\n";
			if(sortcount>=k){
				if(!sortdone) ans++;
				sortdone = true;
			}
			else ans++;
		}
	}

	cout<<ans<<"\n";

	return 0;
}