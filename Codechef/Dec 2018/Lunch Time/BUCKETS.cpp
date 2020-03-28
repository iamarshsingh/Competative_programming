#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    cout<<setprecision(10)<<fixed;
    int n,k;
    cin>>n>>k;
    double arr[n][k];
    double nums[n];
    for(int i=0;i<n;i++){
        double temp=0;
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
            temp+=arr[i][j];
        }
        nums[i]=temp;
    }
    double prob[n][k];
    for(int i=0;i<k;i++){
        prob[0][i] = (arr[0][i]/nums[0]);
        //cout<<prob[0][i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            prob[i][j] = ( (((arr[i][j]+1)*prob[i-1][j])/(nums[i]+1)) + ( (arr[i][j] * (1 - prob[i-1][j]) ) / (nums[i]+1) ) );
            //cout<<prob[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=0;i<k;i++){
        cout<<prob[n-1][i]<<" ";
    }
    cout<<endl;
    return 0;
}
