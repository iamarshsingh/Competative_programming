#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll st,en;

ll findmin(ll arr[], ll start, ll end){
	ll curr=0;
	ll s=start;
	st = start;
	en = start;
	ll minn=0;
	for(int i=start;i<end;i++){
		curr+=arr[i];
		if(curr>0){
			curr=0;
			s = i+1;
		}
		if(curr<minn){
			minn=curr;
			st = s;
			en=i;
		}
	}
	return minn;
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];

	ll maxx=0;
	ll minn=0;
	ll curr=0;
	if(x>0){
		for(int i=0;i<n;i++){
			curr+=arr[i];
			if(curr<0) curr=0;
			if(curr>maxx)maxx=curr;
		}
		cout<<x*maxx<<endl;
		return 0;
	}
	curr=findmin(arr,0,n);
	ll maxxneg=curr*x;
	ll here=maxxneg;
	for(ll i=st-1;i>=0;i--){
		here += arr[i];
		if(here>maxxneg)maxxneg=here;
	}
	here = maxxneg;
	for(ll i=en+1;i<n;i++){
		here+=arr[i];
		if(here>maxxneg)maxxneg=here;
	}

	curr=0;
	ll cs=0,end=n,start=0;
	for(int i=0;i<n;i++){
		curr+=arr[i];
		if(curr<0){
			curr=0;
			cs=i+1;
		}
		if(curr>maxx){
			maxx=curr;
			end=i;
			start=cs;
		}
	}
	//cout<<maxxneg<<" "<<maxx<<" "<<start<<" "<<end<<endl;

	ll left = findmin(arr,0,start);
	curr=0;
	for(ll i=en+1;i<start;i++){
		curr+=arr[i];
	}
	left = x*left + curr;
	here=left;
	for(ll i=st-1;i>=0;i--){
		here += arr[i];
		if(here>left)left=here;
	}

	ll right = findmin(arr,end+1,n);
	curr=0;
	for(ll i=end+1;i<st;i++){
		curr+=arr[i];
	}
	right = x*right + curr;
	here = right;
	for(ll i=en+1;i<n;i++){
		here+=arr[i];
		if(here>right)right=here;
	}

	
	curr = findmin(arr,start,end+1);
	
	curr = maxx - curr + (x*curr);
	here=curr;
	for(ll i=start-1;i>=0;i--){
		here += arr[i];
		if(here>curr)curr=here;
	}
	here = curr;
	for(ll i=end+1;i<n;i++){
		here+=arr[i];
		if(here>curr)curr=here;
	}

	//cout<<curr<<" "<<maxx + (2*x*curr)<<endl;
	maxxneg = max(maxxneg, curr );
	

	//cout<<maxx<<" "<<left<<" "<<right<<" "<<endl;
	maxx = max(maxxneg, max(maxx+left,maxx+right));

	cout<<maxx<<endl;
	return 0;
}