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

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	int minn=100000;
	for(int i=0;i<=100;i++){
		int prev = 0;
		bool poss=true;
		for(int j=0;j<n;j++){
			if(prev==0){
				if(abs(arr[j]-i)!=0){
					//cout<<"here"<<endl;
					prev = abs(arr[j]-i);
				}
			}
			if(abs(arr[j]-i)==abs(prev) || arr[j]-i==0){

			}
			else{
				poss=false;
				break;
			}
		}
		if(poss){
			if(abs(prev)<minn)minn=abs(prev);
		}
	}
	if(minn==100000) cout<<-1<<endl;
	else cout<<minn<<endl;
	return 0;
}