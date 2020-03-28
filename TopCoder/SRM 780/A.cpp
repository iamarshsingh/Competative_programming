#include <bits/stdc++.h>
#define ld long double
#define MOD 1000000007
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
{return cout<<'('<<P.F<<','<< P.S<<')';}

class BeatTheStar{
    public:
    double doesItMatter(int N, int G){
        
        if(N==2){
            if(G==1) return 0.0;
            else return 1.0;
        }
        
        vector<int> arr;
        int sum=0;
        for(int i=1;i<=N;i++){
            if(i==G) continue;
            arr.push_back(i);
            sum += i;
        }
        int tar = ceil(sum/2.0);
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        //cout<<n<<" "<<sum<<" "<<tar<<"\n";
        //cout<<arr<<"\n";
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum; j++){
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i-1][j];
                    if(j>=arr[i-1]){
                        dp[i][j] += dp[i-1][j-arr[i-1]];
                    }
                }
            }
        }
        int nums = 0;
        for(int i=1;i<=sum; i++){
            if( ( max(i,sum-i) - min(i, sum-i) ) < G){
                nums += dp[n][i];
                //cout<<i<<" "<<nums<<" "<<dp[n][i]<<"\n";
            }
        }
        //cout<<dp[n]<<"\n";
        //cout<<dp[n][tar]<<"\n";
        //cout<<nums<<"\n";
        double ans = ((nums*1.0)/pow(2,N-1));
        return ans;
    }
};


int main(){
    int N,G;
    cin>>N>>G;
    vector<int> arr;
    int sum=0;
    for(int i=1;i<=N;i++){
        if(i==G) continue;
        arr.push_back(i);
        sum += i;
    }
    int tar = ceil(sum/2.0);
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1));
    //cout<<n<<" "<<sum<<" "<<tar<<"\n";
    //cout<<arr<<"\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum; j++){
            if(j==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = 0;
            else{
                dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1]){
                    dp[i][j] += dp[i-1][j-arr[i-1]];
                }
            }
        }
    }
    int nums = 0;
    for(int i=1;i<=sum; i++){
        if( ( max(i,sum-i) - min(i, sum-i) ) < G){
            nums += dp[n][i];
            //cout<<i<<" "<<nums<<" "<<dp[n][i]<<"\n";
        }
    }
    //cout<<dp[n]<<"\n";
    //cout<<dp[n][tar]<<"\n";
    //cout<<nums<<"\n";
    double ans = ((nums*1.0)/pow(2,N-1));
    cout<<ans<<"\n";
    //cout<<((nums*1.0)/pow(2,N-1))<<"\n";
}