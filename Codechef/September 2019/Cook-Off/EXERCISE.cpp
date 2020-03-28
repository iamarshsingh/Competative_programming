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
		int n;
		string s;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		//0-min 1-max
		int A[n][2];
		cin>>s;
		if(arr[0]==-1){
			A[0][0] = 0;
			A[0][1] = MOD;
		}
		else{
			A[0][0] = A[0][1] = arr[0];
		}
		bool poss=true;
		for(int i=1;i<n;i++){
			//cout<<i<<" ";
			if(arr[i]==-1){
				A[i][0] = A[i-1][0];
				A[i][1] = A[i-1][1];
				if(s[i-1]=='>'){
					A[i][1]--;
					A[i][0] = 0;
				}
				if(s[i-1]=='<'){
					A[i][0]++;
					A[i][1] = MOD;
				}
			}
			else{
				if(s[i-1]=='='){
					if(arr[i]>=A[i-1][0] && arr[i]<=A[i-1][1]){
						A[i][0] = A[i][1] = arr[i];
					}
					else{
						poss=false;
						break;
					}
				}
				else if(s[i-1]=='>'){
					if(arr[i]<A[i-1][1]){
						A[i][0] = A[i][1] = arr[i];
					}
					else{
						poss=false;
						break;
					}
				}
				else if(s[i-1]=='<'){
					if(arr[i]>A[i-1][0]){
						A[i][0] = A[i][1] = arr[i];
					}
					else{
						poss=false;
						break;
					}
				}
			}
			if(A[i][1]<0){
				poss=false;
				break;
			}
			//cout<<A[i][0]<<" "<<A[i][1]<<endl;
		}
		if(poss) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}

	return 0;
}