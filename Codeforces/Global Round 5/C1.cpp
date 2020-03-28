#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define tuple<int,int,int,int> tup
using namespace std;

struct comp{
	bool operator() (tup a, tub b){
		if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
		else if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
		else if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
		else return get<3>(a) < get<3>(b);
	}
};

bool comp1(tup a, tub b){
	if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
	else if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
	else if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
	else return get<3>(a) < get<3>(b);
}

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,x,y,z;
	cin>>n;
	vector<tup> arr;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		arr[i] = make_tuple(x,y,z,i+1);
	}
	sort(arr.begin(), arr.end(), comp1);

	for(int i=0;i<n;i+=2){
		cout<<get<3>(arr[i])<<" "<<get<3>(arr[i+1])<<endl;
	}

	return 0;
}