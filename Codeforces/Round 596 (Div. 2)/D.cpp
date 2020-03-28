#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 10000000000
using namespace std;

int power(int a, int b){
    int ans = 1;
    while (b > 0) 
    {
        if (b & 1) 
            ans = (ans*a); 
        
        b = b>>1;
        a = (a*a);
    }
    return ans; 
}

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(k==2){
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int a = arr[i];
            int req = 1;
            //cout<<a<<endl;
            if(a==1 || a==2 || a==3) req = a;
            for(int j=2;j*j<=a;j++){
                int d=0;
                //cout<<a<<endl;
                while(a>0 && a%j==0){
                    //cout<<a<<endl;
                    if(d==0LL) req = req * j;
                    else req = req / j;
                    d = (d+1)%2;
                    a = a/j;
                }
                //cout<<a<<endl;
                if(a>0 && a%j==0){
                    int tj = (a/j);
                    while(a%tj==0){
                        if(d==0) req = req * tj;
                        else req = req /tj;
                        d = (d+1)%2;
                        a = a/tj;
                    }
                }
            }
            //cout<<"req: "<<req<<endl;
            ans += mp[req];
            //cout<<arr[i]<<" "<<req<<" "<<mp[req]<<"\n";
            mp[arr[i]]++;
        }
        cout<<ans<<"\n";
    }
    else{
        vector<int> powers;
        int i=1, j=power(1,k);
        while(j<=INF){
            powers.push_back(j);
            i++;
            j=power(i,k);
        }
        //cout<<powers.size()<<"\n";
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<powers.size();j++){
                if(powers[j]%arr[i]==0 && mp[powers[j]/arr[i]]>0){
                    //cout<<arr[i]<<" "<<powers[j]<<" "<<mp[powers[j]/arr[i]]<<"\n";
                    ans += mp[powers[j]/arr[i]];
                }
            }
            mp[arr[i]]++;
        }
        cout<<ans<<"\n";
    }
}

signed main(){
    //fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}