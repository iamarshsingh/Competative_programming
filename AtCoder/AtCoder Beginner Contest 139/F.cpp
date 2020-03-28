#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

	ll n;
	cin>>n;
	ld a,b;
	pair<ld,ld> arr[n+1][4];
	arr[0][0] = arr[0][1] = arr[0][2] = arr[0][3] = {0.0, 0.0};

	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=0;j<4;j++){
			pair<ld,ld> temp = arr[i-1][j];
			temp.first += a;
			temp.second += b;
			//cout<<temp.first<<" "<<temp.second<<endl;
			for(int k=0;k<4;k++){
				//cout<<"k: "<<k;
				pair<ld,ld> temp2 = arr[i][k];
				ld prev = sqrt(temp2.first*temp2.first + temp2.second*temp2.second);
				//cout<<prev<<"   ";
				if((k==0 && temp.first>=0) || (k==1 && temp.second>=0) || (k==2 && temp.first<=0) || (k==3 && temp.second<=0) ){
					//cout<<" here ";
					//cout<<sqrt(temp.first*temp.first + temp.second*temp.second)<<" "<<prev;
					if(sqrt(temp.first*temp.first + temp.second*temp.second) >= prev){
						arr[i][k] = temp;
						//cout<<"yes";
					}
				}
				//cout<<endl;
			}
		}
		if(i<n){
			for(int j=0;j<4;j++)
				arr[i+1][j] = arr[i][j];	
		}
		for(int j=0;j<4;j++){
			pair<ld,ld> temp = arr[i][j];
			//cout<<temp.first<<" "<<temp.second<<endl;
		}
		//cout<<endl;
	}

	ld maxx=0;
	for(int j=0;j<4;j++){
		pair<ld,ld> temp = arr[n][j];
		//cout<<temp.first<<" "<<temp.second<<endl;
		ld prev = sqrt(temp.first*temp.first + temp.second*temp.second);
		//cout<<prev<<endl;
		maxx = max(prev, maxx);
	}
	cout<<setprecision(25)<<fixed;
	cout<<maxx<<endl;

	return 0;
}