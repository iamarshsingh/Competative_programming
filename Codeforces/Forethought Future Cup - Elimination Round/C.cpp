#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	int primes[9]={1,2,3,5,7,11,13,17,19};
	while(t--){
		int n;
		cin>>n;
		int maxx=0;
		int a;
		for(int i=0;i<9;i++){
			if(primes[i]==n) continue;
			int num=1,l=0,r=0;
			bool curr=false;
			vector<int> left,right;
			left.clear();
			right.clear();
			int k=1;
			while(l+r<n){
				if(curr){
					curr=false;
					left.push_back(num);
					l++;
				}
				else{
					curr=true;
					r++;
					right.push_back(num);
				}

				num += primes[i];
				if(num>n){
					k++;
					num = k;
				}
			}
			cout<<l<<" "<<r<<" ";
			for(int j=0;j<left.size(); j++){
				cout<<left[j]<<" ";
			}
			for(int j=0;j<right.size(); j++){
				cout<<right[j]<<" ";
			}
			cout<<endl;
			cout.flush();
			cin>>a;
			if(a>maxx)maxx=a;
		}
		cout<<"-1 "<<maxx<<endl;
		cout.flush();

	}
	
	return 0;
}