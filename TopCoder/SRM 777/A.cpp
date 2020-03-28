#include <bits/stdc++.h>
#define ld long double
#define MOD 1000000007
#define N 1000006
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define randright srand(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
// int my_rand(){ int a=rand(); int b=rand(); return a*(RAND_MAX+1)+b; }

//#define int long long int

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}

class PreviousOccurrence{
    public:
    int findValue(int defaultValue, int query){
        vector<int> sec(10000007, -1);
        vector<int> fir(10000007, -1);
        vector<int> arr(10000007, -1);
        fir[0] = 0;
        arr[0] = 0;
        if(query==0){
            return 0;
        }
        for(int i=1;i<=10000000; i++){
            //cout<<i<<"\n";
            if(sec[arr[i-1]]==-1){
                arr[i] = defaultValue;
            }
            else{
                arr[i] = sec[arr[i-1]] - fir[arr[i-1]];
            }
            if(fir[arr[i]]==-1){
                fir[arr[i]] = i;
            }
            else if(sec[arr[i]]==-1){
                sec[arr[i]] = i;
            }
            else{
                fir[arr[i]] = sec[arr[i]];
                sec[arr[i]] = i;
            }
            //cout<<"("<<i<<","<<arr[i]<<")\n";
            if(arr[i]==query){
                break;
            }
            
        }
        return fir[query];
    }
};