#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		ll arr[n],onearr[n],twoarr[n];
		ll prev=0,ones=0,twos=0;
		for(ll i=0;i<n;i++){
			onearr[i]=0;
			twoarr[i]=0;
			cin>>arr[i];
			if(prev==arr[i]){
				if(arr[i]==1){
					onearr[ones-1]++;
				}
				else{
					twoarr[twos-1]++;
				}
			}
			else{
				if(arr[i]==1){
					ones++;
					onearr[ones-1]++;
				}
				else{
					twos++;
					twoarr[twos-1]++;
				}
			}
			prev=arr[i];
		}
		/*
		for(int i=0;i<ones;i++){
			cout<<onearr[i]<<" ";
		}cout<<endl;

		for(int i=0;i<twos;i++){
			cout<<twoarr[i]<<" ";
		}cout<<endl;
		//*/
		ll dp[n][4];
		ll temp = 0;
		dp[0][0]=dp[0][2]=dp[0][3]=0;
		dp[0][1]=1;
		ll o=-1,t=-1;
		prev=arr[0];
		if(prev==1){
			o++;
			onearr[0]--;
		}
		if(prev==2){
			t++;
			twoarr[0]--;
		}
		for(int i=1;i<n;i++){
			
			dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 0;

			if(i-2>=0 && arr[i-2]==2){
				dp[i][0] = ((dp[i-2][0]+dp[i-2][1])%MOD+dp[i-2][2])%MOD;
			}
			dp[i][1] = (dp[i-1][0]+dp[i-1][1])%MOD;
			if(i+1<n && arr[i-1]==2){
				dp[i][2] = (dp[i-1][0]+dp[i-1][1])%MOD;
			}
			if(i+2<n && arr[i-1]==2 && arr[i+2]==2){
				dp[i][3] = (dp[i-1][0]+dp[i-1][1])%MOD;
			}

			if(prev==arr[i]){
				if(prev==1){
					onearr[o]--;
				}
				else{
					twoarr[t]--;
					if(twoarr[t]>1){
						temp = (temp + ((dp[i-1][0] + dp[i-1][1])*(twoarr[t]-2))%MOD + MOD)%MOD;
						//*
						if(twoarr[t]%2==0 && o+1<ones){
							temp = (temp + dp[i-1][0] + dp[i-1][1])%MOD;
							if(onearr[o+1]==1 && t+1<twos){
								temp = (temp + dp[i-1][0] + dp[i-1][1])%MOD;
							}
						}
						//*/
					}
				}
			}
			else{
				if(arr[i]==1){
					o++;
					onearr[o]--;
					if(onearr[o]==0 && t+1<twos){
						if(twoarr[t+1]>1){
							temp = (temp + ((dp[i-1][0] + dp[i-1][1])*(twoarr[t+1]-2))%MOD + MOD)%MOD;
							//cout<<"temp: "<<temp<<endl;
							//*
							if(twoarr[t+1]%2==0 && o+1<ones){
								temp = (temp + dp[i-1][0] + dp[i-1][1])%MOD;
								if(onearr[o+1]==1 && t+2<twos){
									temp = (temp + dp[i-1][0] + dp[i-1][1])%MOD;
								}
							}
							//*/
						}
					}
				}
				else{
					t++;
					twoarr[t]--;
				}
			}
			prev=arr[i];
		}
		/*
		cout<<temp<<endl;
		for(int i=0;i<n;i++){
			cout<<dp[i][0]<<" ";
		}cout<<endl;
		for(int i=0;i<n;i++){
			cout<<dp[i][1]<<" ";
		}cout<<endl;
		for(int i=0;i<n;i++){
			cout<<dp[i][2]<<" ";
		}cout<<endl;
		for(int i=0;i<n;i++){
			cout<<dp[i][3]<<" ";
		}cout<<endl;
		//*/
		for(int i=0;i<n;i++){
			temp = ((((temp + dp[i][0])%MOD + dp[i][1])%MOD + dp[i][2])%MOD + dp[i][3])%MOD;
		}
		cout<<(temp%MOD)<<endl;
	}

	return 0;
}