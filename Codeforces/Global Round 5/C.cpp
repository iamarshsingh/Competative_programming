#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define tup tuple<int,int,int,int>
using namespace std;

struct Point{
	int x,y,z,id;
	bool operator <(const Point& b) const{
		return vector<int>{x,y,z} < vector<int> {b.x, b.y, b.z};
	}
	bool same(const Point& b) const{
		return x==b.x && y==b.y;
	}
	bool samex(const Point& b) const{
		return x==b.x;
	}
}; 

int main(){
	
	//fastio
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n,x,y,z;
	cin>>n;
	vector<Point> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y>>arr[i].z;
		arr[i].id = i+1;
	}
	sort(arr.begin(), arr.end());

	vector<Point> remaining;
	for(Point p: arr){
		if(!remaining.empty() && remaining.back().same(p)){
			cout<<p.id<<" "<<remaining.back().id<<"\n";
			remaining.pop_back();
		}
		else{
			remaining.push_back(p);
		}
	}
	arr = remaining;
	remaining.clear();
	for(Point p: arr){
		if(!remaining.empty() && remaining.back().samex(p)){
			cout<<p.id<<" "<<remaining.back().id<<"\n";
			remaining.pop_back();
		}
		else{
			remaining.push_back(p);
		}
	}

	for(int i=0;i < (int)remaining.size(); i+=2){
		cout<<remaining[i].id<<" "<<remaining[i+1].id<<"\n";
	}

	return 0;
}