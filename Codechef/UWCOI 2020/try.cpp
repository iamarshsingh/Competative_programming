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

#define int long long int

template<class T> ostream& operator<<(ostream& cout,vector<T> V)
{cout<<"[ ";for(auto v:V)cout<<v<<' ';return cout<<']';}
template<class L,class R> ostream& operator<<(ostream& cout,pair<L, R> P)
{return cout<<'('<<P.x<<','<< P.y<<')';}

void multiply(int T[3][3], int M[3][3]) 
{
    int temp[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int curr = 0;
            for(int k=0;k<3;k++){
                curr += (T[i][k]*M[k][j]);
                curr %= MOD;
            }
            temp[i][j] = curr;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            T[i][j] = temp[i][j];
        }
    }
}
  
void power(int T[3][3], int n) 
{ 
    if (n == 0 || n == 1) 
        return; 
    int M[3][3] = {{ 1, 1, 1 },  
                   { 1, 0, 0 },  
                   { 0, 1, 0 }}; 
  
    power(T, n / 2); 
  
    multiply(T, T); 
  
    if (n % 2) 
        multiply(T, M); 
} 
int tribonacci(int n) 
{ 
    int T[3][3] = {{ 1, 1, 1 },  
                   { 1, 0, 0 }, 
                   { 0, 1, 0 }}; 
  
    if (n == 0 || n == 1) 
        return 0; 
    else
        power(T, n - 2); 
  
    return T[0][0]; 
} 



void solve(){
    int n;
    cin>>n;
    cout<<(2*tribonacci(n+2))%MOD<<"\n";
}

signed main(){
    fastio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}