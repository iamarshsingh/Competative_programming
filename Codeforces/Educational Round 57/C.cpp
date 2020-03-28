#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    int ans[] = [180, 90, 60, 45, 36, 30, 180, 45, 20, 18, 180, 15, 180, 90, 12, 45, 180, 10, 180, 9, 60, 90, 180, 15, 36, 90, 20, 45, 180, 6, 180, 45, 60, 90, 36, 5, 180, 90, 60, 9, 180, 30, 180, 45, 4, 90, 180, 15, 180, 18, 60, 45, 180, 10, 36, 45, 60, 90, 180, 3, 180, 90, 20, 45, 36, 30, 180, 45, 60, 18, 180, 5, 180, 90, 12, 45, 180, 30, 180, 9, 20, 90, 180, 15, 36, 90, 60, 45, 180, 4, 180, 45, 60, 90, 36, 15, 180, 90, 20, 9, 180, 30, 180, 45, 12, 90, 180, 5, 180, 18, 60, 45, 180, 30, 36, 45, 20, 90, 180, 6, 180, 90, 60, 45, 36, 10, 180, 45, 60, 18, 180, 15, 180, 90, 8, 45, 180, 30, 180, 9, 60, 90, 180, 10, 36, 90, 60, 45, 180, 12, 180, 45, 20, 90, 36, 15, 180, 90, 60, 18, 180, 20, 180, 45, 24, 90, 180, 30, 180, 36, 40, 45, 180, 60, 72, 90, 120, 180]
Important Links
Recent Interview Experiences
Project Ideas
School Programming
Company Preparation
Quiz Corner
Topic-wise Problems
Subjective Problems
Placements
How to pick a difficulty level?
    while(t--){
        int ang,besta;
        cin>>ang;
        besta=-1;
        int a =  180;
        for(int i=3;i<=180;i++){
            a = ((i-2)*180);
            if(a%i!=0){
                continue;
            }
            a = a/(i);
            for(int j=1;j<=(i-2);j++){
                if(ang<(a*j)){
                    break;
                }
                else if(ang==(a*j)){
                    besta = i;
                }
                if(besta>0)break;
            }
            if(besta>0)break;
        }
        cout<<besta<<endl;
    }
    return 0;
}
