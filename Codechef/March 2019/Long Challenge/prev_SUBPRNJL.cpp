#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n],ans=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}


		for(int i=1;i<=min(k,n);i++){
			int freq[2001]={0};
			deque<int> d;
			int m=0;

			for(int j=0;j<i;j++){
				freq[arr[j]]++;
				m = max(m,arr[j]);
				while(!d.empty() && d.back()<arr[j]){
					d.pop_back();
				}
				d.push_back(arr[j]);
			}
			for(int j=0;j<n && j+i<=n;j++){
				int end = j+i;
				if(freq[freq[d.front()]]>0){
					ans++;
					cout<<j<<" "<<end<<endl;
				}
				freq[arr[j]]--;
				if(j+i<n)freq[arr[j+i]]++;
				if(arr[j]==d.front())d.pop_front();
				if(j+i<n){
					while(!d.empty() && d.back()<arr[j+i]){
						d.pop_back();
					}
					d.push_back(arr[j+i]);
				}
			}
		}
		cout<<endl;
		if(k<n){
		
			for(int i=k+1;i<=n;i++){
				int freq[2001]={0};
				int m=0;
				int count = 0;
				//for(int j=0;j<2001;j++){
				//	cout<<freq[j]<<" ";
				//}
				//cout<<endl;
				for(int j=0;j<i;j++){
					freq[arr[j]]++;
				}
				/*
				for(int j=0;j<2001;j++){
					cout<<freq[j]<<" ";
				}
				cout<<endl;
				*/
				for(int j=0;j<2001;j++){
					count+=freq[j];
					//cout<<"count: "<<count<<"    k:"<<k<<endl;
					if(count>=k){
						//cout<<"j: "<<j<<" ";
						m=j;
						break;
					}
				}
				//cout<<"m:  "<<m<<endl;
				for(int j=0;j<n && j+i<=n;j++){
					int end = j+i;
					if(freq[freq[m]]>0){
						ans++;
						cout<<j<<" "<<end<<endl;
					}

					if(j+i<n){

						freq[arr[j]]--;
						freq[arr[j+i]]++;

						if(arr[j]<=m){
							count--;
							if(arr[j+i]>m){
								while(count<k){
									m++;
									count+=freq[m];
								}
							}
							else{
								count++;
							}
						}
						else{
							if(arr[j+i]<=m){
								count++;
								if(count-freq[m]>=k){
									while(count>=k){
										count = count - freq[m];
										m--;
									}
									while(count<k){
										m++;
										count = count + freq[m];
									}
								}
							}
						}
					}
				}

			}
		}

		cout<<ans<<endl;
	}

	return 0;
}