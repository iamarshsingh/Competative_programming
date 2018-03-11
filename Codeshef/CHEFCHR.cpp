#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int nums[26],count=0;
        for(int i=0;i<26;i++)nums[i]=0;
        
        int len=str.length();
        for(int i=0;i<(len-3);i++){
            for(int j=i;j<(i+4);j++){
                nums[str[j]-'a']++;
            }
            if(nums[2]==1 && nums[4]==1 && nums[5]==1 && nums[7]==1)count++;
            for(int i=0;i<26;i++)nums[i]=0;
        }
        
        if(count>0)cout<<"lovely "<<count<<endl;
        else cout<<"normal"<<endl;
    }
    return 0;
} 
