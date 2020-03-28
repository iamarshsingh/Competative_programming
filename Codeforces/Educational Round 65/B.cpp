#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	ll arr[6] = {4 , 8, 15, 16, 23, 42 };
	ll n;
	ll in[4][2];
	cout<<"? 1 2"<<endl;
	fflush(stdout);

	cin>>n;
	bool poss=false;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(arr[i]*arr[j]==n){
				in[0][0]=arr[i];
				in[0][1]=arr[j];
				poss=true;
				break;
			}
		}
		if(poss) break;
	}

	cout<<"? 2 3"<<endl;
	fflush(stdout);

	cin>>n;
	poss=false;
	//cout<<"n:"<<n<<endl;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(arr[i]*arr[j]==n){
				in[1][0]=arr[i];
				in[1][1]=arr[j];
				//cout<<in[1][0]<<in[1][1]<<endl;
				poss=true;
				break;
			}
		}
		if(poss) break;
	}

	cout<<"? 3 4"<<endl;
	fflush(stdout);

	cin>>n;
	poss=false;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(arr[i]*arr[j]==n){
				in[2][0]=arr[i];
				in[2][1]=arr[j];
				poss=true;
				break;
			}
		}
		if(poss) break;
	}

	cout<<"? 4 5"<<endl;
	fflush(stdout);

	cin>>n;
	poss=false;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(arr[i]*arr[j]==n){
				in[3][0]=arr[i];
				in[3][1]=arr[j];
				poss=true;
				break;
			}
		}
		if(poss) break;
	}

	ll ans[6];

	for(int k=0;k<3;k++){
		poss=false;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(in[k][i]==in[k+1][j]){
					ans[k+1]=in[k][i];
					ans[k] = in[k][(i==0)?1:0];
					ans[k+2] = in[k+1][(j==0)?1:0];
					poss=true;
					break;
				}
			}
			if(poss)break;
		}
	}

	ll temp=0;
	ans[5]=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			if(arr[i]==ans[j])arr[i]=0;
		}
		//cout<<"sum+ "<<arr[i]<<endl;
		temp += arr[i];
		//cout<<ans[i]<<endl;
	}
	//cout<<"temp: "<<temp<<endl;
	ans[5]=temp;
	cout<<"! ";
	for(int i=0;i<6;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}