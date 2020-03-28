#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

void solve(){
	int n;
	cin>>n;
	int arr[n];
	vector<int> freq(n+2,0);
	vector<int> of(n+2,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		freq[arr[i]]++;
		of[arr[i]]++;	
	}

	int dpmin[n+1][3];
	
	dpmin[0][0] = dpmin[0][1] = dpmin[0][2] = 0;
	for(int i=1;i<=n;i++){
		if(freq[i]>0){
			if(freq[i-1]>0){
				dpmin[i][0] = min( min(dpmin[i-1][0]+1, dpmin[i-1][1]), dpmin[i-1][2]+1);
				dpmin[i][1] = min( min(dpmin[i-1][0]+1, dpmin[i-1][1]+1), dpmin[i-1][2]);
				dpmin[i][2] = min( min(dpmin[i-1][0]+1, dpmin[i-1][1]+1), dpmin[i-1][2]+1);
			}
			else{
				dpmin[i][2] = dpmin[i][1] = dpmin[i][0] = min( min(dpmin[i-1][0]+1, dpmin[i-1][1]+1), dpmin[i-1][2]+1);
			}			
		}
		else{
			dpmin[i][2] = dpmin[i][1] = dpmin[i][0] = min( min(dpmin[i-1][0], dpmin[i-1][1]), dpmin[i-1][2]);
		}
		// cout<<dpmin[i][0]<<" "<<dpmin[i][1]<<" "<<dpmin[i][2]<<"\n";
	}

	for(int i=0;i<=n+1;i++){
		if(freq[i]==0){
			if( i>0 && freq[i-1]>1){
				freq[i]++;
				freq[i-1]--;
			}
			else if( i>1 && of[i-1]==1 && freq[i-2]>1){
				freq[i-2]--;
				freq[i]++;
			}
			else if( i<=n && freq[i+1]>1){
				freq[i]++;
				freq[i+1]--;
			}
			else if( i<n && of[i+1]==1 && freq[i+2]>1){
				freq[i+2]--;
				freq[i]++;
			}
		}
	}

	int ans=0;
	for(int i=0;i<=(n+1);i++){
		if(freq[i]>0){
			ans++;
			// cout<<i<<" ";
		}
	}

	cout<<min( min(dpmin[n][0], dpmin[n][1]), dpmin[n][2])<<" "<<ans<<"\n";
}

signed main(){
	fastio
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}