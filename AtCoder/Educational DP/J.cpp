#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    int A[n],one=0,two=0,three=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
        sum+=A[i];
        if(A[i]==1)one++;
        if(A[i]==2)two++;
        if(A[i]==3)three++;
    }
    long double arr[n+1][n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                arr[i][j][k]=0;
            }
        }
    }
    int x=three,y=two,z=one;
    while(true){
        arr[x][y][z] = (((long double)n)/(x+y+z));
        cout<<x<<" "<<y<<" "<<z<<" "<<arr[x][y][z]<<"  ";
        if(x==0 && y==0 && z==0){
            break;
        }
        else if(z>0){
            z--;
        }
        else if(y>0){
            z = one+two-y+1;
            y--;
        }
        else if(x>0){
            z = one;
            y = two+three-x+1;
            x--;
        }
    }
    long double counts[sum+1]={0}, sums[sum+1] = {0};
    int temp;
    cout<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(arr[i][j][k]>0){
                    temp = (3*i + 2*j + k);
                    sums[temp] += arr[i][j][k];
                    counts[temp]++;
                    cout<<i<<" "<<j<<" "<<k<<" "<<sums[temp]<<" "<<counts[temp]<<endl;
                }
            }
        }
    }
    long double ans = 0;
    for(int i=1;i<=sum;i++){
        cout<<sums[i]<<" "<<counts[i]<<"   ";
        ans = ans + (sums[i]/counts[i]);
    }
    cout<<ans<<endl;
}
