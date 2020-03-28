#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define MOD 1000000007
#define N 1000006
#define INF 1000000000000000000
using namespace std;

int arr[N]; 
int temp[N]; 
int temp2[N];

int merge(int l, int mid, int r){
    int i=l, j=mid+1, k=l, ans = 0;
    while(i<=mid && j<=r){
        if(temp2[i]<=temp2[j]){
            temp[k++] = temp2[i++];
        }
        else if(temp2[i]>temp2[j]){
            ans += (mid-i+1);
            temp[k++] = temp2[j++];
        }
    }
    while(i<=mid){
        temp[k++] = temp2[i++];
    }
    while(j<=r){
        temp[k++] = temp2[j++];
    }
    for(i=l; i<=r;i++){
        temp2[i] = temp[i];
    }
    return ans;
}

int count(int l, int r){
    if(l==r){
        temp[l] = temp2[l];
        return 0LL;
    }
    int mid = (l+r)/2;
    int c1 = count(l, mid);
    int c2 = count(mid+1, r);
    return (c1 + c2 + merge(l, mid, r));
}


signed main(){
    int t;
    cin>>t;
    int n,q,a;
    while(t--){
        scanf("%lld %lld", &n, &q);
        for(int i=0;i<n;i++){
            scanf("%lld", &arr[i]);
            temp2[i] = arr[i];
        }
        int diff[32];
        int ori = count(0, n-1);

        for(int i=0;i<31;i++){
            for(int j=0;j<n;j++){
                temp2[j] = arr[j] ^ (1LL<<i);
            }
            //diff[i] = ori - count(0, n-1);
            diff[i] = count(0, n-1);
            cout<<i<<" "<<ori<<" "<<diff[i]<<"\n";
        }
        int tdif;
        while(q--){
            scanf("%lld", &a);
            tdif = 0;
            for(int i=0;i<31;i++){
                if(a%2==1) tdif += diff[i];
                a/=2;
            }
            printf("%lld\n", (ori-tdif));
        }
    }
}