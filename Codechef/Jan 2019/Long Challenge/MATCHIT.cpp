#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first==b.first){
        if(a.first%2==0) return a.second>b.second;
        else return a.second<b.second;
    }
    else{
        return a.first<b.first;
    }
}

int main(){
	//cout<<(INT_MIN)<<endl;
	ll n,m,pr=0;
	cin>>n>>m;
	ll grid[n][n];
	pr = 2*m;
	pair<ll,ll> arr[pr];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			grid[i][j]=0;
		}
	}
	for(int i=0;i<(pr);i++){
		cin>>arr[i].first;
		cin>>arr[i].second;
		grid[arr[i].first-1][arr[i].second-1] = INT_MIN;
	}
	sort(arr,arr+pr,comp);
	int waste;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
            if(grid[i][j]==INT_MIN) cin>>waste;
			else cin>>grid[i][j];
		}
	}
	//cout<<"here"<<endl;
	ll limX,limY;
	pair<int,int> curr;
	vector<pair<ll,ll>> temp;
	int x=0,y=0;
	ll len = 0;
	for(int i=0;i<pr;i=i+2){
		temp.clear();
		len=0;
		while(true){
			len++;
			temp.push_back(arr[i]);
			if(arr[i+1].first==arr[i].first){
                if(arr[i+1].second>arr[i].second) arr[i].second++;
                else if(arr[i+1].second<arr[i].second) arr[i].second--;
                else break;
			}
			else{
                if(arr[i].second<n)arr[i].second++;
                else arr[i].first++;
			}
		}
		cout<<len<<" ";
		for(int j=0;j<len;j++){
            cout<<temp[j].first<<" "<<temp[j].second<<" ";
		}
		cout<<endl;
	}

}
