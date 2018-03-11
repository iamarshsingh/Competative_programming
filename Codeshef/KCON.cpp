#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int T=0;
	cin>>T;
	while(T--){
	    int n=0,k=0;
	    long long int cursum=0,sum=0,max=-1000009;
	    cin>>n>>k;
	    long long int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    if(k>100){
	    for(int i=0;i<n;i++){
	        sum=sum+arr[i];
	    }
	    for(int i=0;i<2;i++){
	        for(int j=0;j<n;j++){
	            cursum=cursum+arr[j];
	            if(cursum>max)max=cursum;
	            if(cursum<0)cursum=0;
	        }
	    }
	    if(sum>0){
	        max=max+(sum*(k-2));
	    }
	    cout<<max<<endl;
	    }
	    else{
	        for(int i=0;i<k;i++){
	        for(int j=0;j<n;j++){
	            cursum=cursum+arr[j];
	           	if(cursum>max)max=cursum;
	            if(cursum<0)cursum=0;
	        }
	    }
	    cout<<max<<endl;
	    }
	}
	return 0;
}  
