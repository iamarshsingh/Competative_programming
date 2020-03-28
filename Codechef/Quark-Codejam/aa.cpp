#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,p;
    cin>>n>>m>>p;
    int row[n][2];
    int col[m][2];
    for(int i=0;i<n;i++){
        row[i][0]=m;
        row[i][1]=-1;
    }
    for(int i=0;i<m;i++){
        col[i][0]=n;
        col[i][1]=-1;
    }
    while(p--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        for(int i=r1;i<=r2;i++){
            row[i-1][0] = min(c1-1,row[i-1][0]);
            row[i-1][1] = max(c2-1,row[i-1][1]);
        }
        for(int i=c1;i<=c2;i++){
            col[i-1][0] = min(r1-1,col[i-1][0]);
            col[i-1][1] = max(r2-1,col[i-1][1]);
        }
    }
    int grid[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            grid[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        //cout<<row[i][0]<<" "<<row[i][1]<<endl;
        for(int j=row[i][0];j<=row[i][1];j++){
            grid[i][j]=1;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=col[i][0];j<=col[i][1];j++){
            grid[j][i]=1;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
            if(grid[i][j]==0){
                ans++;
            }
        }
        cout<<endl;
    }
    cout<<ans<<endl;
}
