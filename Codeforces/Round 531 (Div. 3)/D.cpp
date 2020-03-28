#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int need = n/3;
    int nums[3];
    nums[0]=0;
    nums[1]=0;
    nums[2]=0;
    for(int i=0;i<n;i++){
        nums[s[i]-'0']++;
    }
    int i=0;
    int saved;
    if(nums[0]<need){
        for(;i<n;i++){
            if(s[i]!='0' && nums[s[i]-'0']>need){
                if(nums[0]<need){
                    nums[s[i]-'0']--;
                    s[i]='0';
                    nums[0]++;
                }
                else break;
            }
        }
    }
    if(nums[1]<need){
        for(;i<n;i++){
            if(s[i]=='2' && nums[s[i]-'0']>need){
                if(nums[1]<need){
                    nums[s[i]-'0']--;
                    s[i]='1';
                    nums[1]++;
                }
                else break;
            }
        }
    }
    if(nums[2]<need){
        for(int i=n-1;i>=0;i--){
            if(s[i]!='2' && nums[s[i]-'0']>need){
                if(nums[2]<need){
                    nums[s[i]-'0']--;
                    s[i]='2';
                    nums[2]++;
                }
                else break;
            }
        }
    }
    if(nums[1]<need){
        for(i=n-1;i>=0;i--){
            if(s[i]!='1' && nums[s[i]-'0']>need){
                if(nums[1]<need){
                    nums[s[i]-'0']--;
                    s[i]='1';
                    nums[1]++;
                }
                else break;
            }
        }
    }


    cout<<s<<endl;
}
