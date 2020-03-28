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

	int t;
	cin>>t;
	while(t--){
		int n,a,f;
		cin>>n;
		deque<ll> left, right;
		for(int i=0;i<n-1;i++){
			cin>>a;
			right.push_back(a);
		}
		cin>>f;
		int minn = INT_MAX;
		int curr;
		bool poss = false;
		int ans;
		for(int i=0;i<n-1;i++){
			curr = 0;
			if(i>0){
				if(i%2==1){
					left.push_back(right[0]);
				}
				right.pop_front();
			}
			if(!right.empty() && right[0]<=f){
				curr = f;
				if(i%2==1){
					curr += left[left.size()-1];
				}
				int dec=ceil(i/2.0)-1;
				int next=0;
				int nums = n-(i/2)-1;
				int sn = nums;
				//cout<<i<<" "<<sn<<" "<<curr<<endl;
				while(nums>2){
					if(dec<0){
						dec = (sn + dec)%sn;
					}
					//cout<<"inside: "<<nums<<" "<<dec<<" "<<next<<" "<<curr<<" "<<ceil(i/2.0)<<endl;
					if(nums%2==1){
						if(dec<ceil(i/2.0)){
							curr += left[dec];
						}
						else{
							curr += right[dec-ceil(i/2.0)];
						}
					}
					else{
						dec = dec - pow(2,next);
					}
					next++;
					nums = ceil(((double)nums)/2);
				}
				poss = true;
				if(curr < minn){
					minn = curr;
					ans = i+1;
				}
				//cout<<i<<" "<<sn<<" "<<curr<<endl;
			}
		}
		if(poss){
			cout<<"possible"<<endl;
			cout<<ans<<" "<<minn<<endl;
		}
		else{
			cout<<"impossible"<<endl;
		}
	}

	return 0;
}