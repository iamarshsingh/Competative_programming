#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	int arr[n];
	int minn=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]<arr[minn]) minn = i;
	}
    
    int i=(minn-1+n)%n;
    int div2;
	vector<int> ans(n+1,-1);
	bool poss=false;
	deque<int> d;
	d.push_back(minn);
	for(int i=(minn-1+n)%n ; i!=minn; i = (i-1+n)%n){
		div2 = (arr[i]%2==0)?(arr[i]/2):(((arr[i]/2))+1);
		for(int j=0;j<d.size();j++){
			if(arr[d[j]]<div2){
				ans[i] = ((i<j)?(i+n-j):(i-j));
				poss=true;
			}
		}
		while(d.size()>0 && d[0]<arr[i]){
			d.pop_front();
		}
		d.push_front(i);
	}
	if(!poss){
		for(int i=0;i<n;i++){
    		cout<<"-1 ";
    	}
    	cout<<endl;
		return 0;
	}
	for(int i=minn-1;i>=0;i--){
		div2 = (arr[i]%2==0)?(arr[i]/2):(((arr[i]/2))+1);
		if(div2>arr[i+1]){
			ans[i] = 1;
		}
		else{
			ans[i] = ans[i+1]+1;
		}
	}
	ans[n] = ans[0];
	arr[n] = arr[0];
	//cout<<ans[0]<<" "<<ans[n]<<endl;
	for(int i=n-1;i>minn;i--){
		div2 = (arr[i]%2==0)?(arr[i]/2):(((arr[i]/2))+1);
		if(div2>arr[i+1]){
			ans[i] = 1;
		}
		else{
			ans[i] = ans[i+1]+1;
			//cout<<i<<" "<<ans[i]<<" "<<ans[i+1]<<endl;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}