#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair< ll,ll > a, pair< ll,ll > b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,curlow=0;
    cin>>n>>m;
    pair< ll,ll > arr[n];
    pair< ll,ll > prices[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
        prices[i].first = arr[i].second;
        prices[i].second=i;
    }
    sort(prices,prices+n,comp);
    while(m--){
        int d,num;
        cin>>d>>num;
        if(curlow>=n){
            cout<<0<<endl;
        }
        else{
            ll sum=0;
            if(arr[d-1].first>0){
                if(num<=arr[d-1].first){
                    sum += (num*arr[d-1].second);
                    arr[d-1].first = arr[d-1].first - num;
                    num = 0;
                }
                else{
                    sum += (arr[d-1].first*arr[d-1].second);
                    num = num - arr[d-1].first;
                    arr[d-1].first = 0;
                }
            }
            while(num>0){
                if(arr[prices[curlow].second].first<=0){
                    curlow++;
                }
                if(curlow>=n){
                    sum=0;
                    break;
                }
                if(num<=arr[prices[curlow].second].first){
                    sum += (num*arr[prices[curlow].second].second);
                    arr[prices[curlow].second].first = arr[prices[curlow].second].first - num;
                    num = 0;
                }
                else{
                    sum += (arr[prices[curlow].second].first*arr[prices[curlow].second].second);
                    num = num - arr[prices[curlow].second].first;
                    arr[prices[curlow].second].first = 0;
                }
            }
            cout<<sum<<endl;
        }
    }
}
