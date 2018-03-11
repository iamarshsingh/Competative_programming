#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int T=0;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    long long int arr[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	        }
	    }
        for(int i=0;i<n;i++)sort(arr[i], arr[i]+n);
        
        long long int total=arr[n-1][n-1];
        long long int curnum=total;
        
        for(int i=(n-2);i>=0;i--){
            for(int j=(n-1);j>=0;j--){
                if(arr[i][j]<curnum){
                    curnum=arr[i][j];
                    total=total+curnum;
                    
                    break;
                
                }
                else if(j==0){
                    total=-1;
                    break;
                }
            }
            if(total==-1)break;
        }
        cout<<total<<endl;
	}
	return 0;
} 
