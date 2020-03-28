#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define C 1000000000
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x1=0,y1=0,x2=1000000000,y2=1000000000;
        cout<<"Q 0 0"<<flush<<endl;
        ll d1 = 0;
        cin>>d1;
        cout<<"Q 0 1000000000"<<flush<<endl;
        ll d2 = 0;
        cin>>d2;
        ll cen = (d1+C-d2)/2;
        cout<<"Q 0 "<<cen<<flush<<endl;
        cin>>x1;
        y1 = d1 - x1;

        cout<<"Q 1000000000 1000000000"<<flush<<endl;
        cin>>d1;
        cout<<"Q 1000000000 0"<<flush<<endl;
        cin>>d2;
        cen = (C-d1+d2)/2;
        cout<<"Q 1000000000 "<<cen<<flush<<endl;
        cin>>d2;
        x2 = C-d2;
        y2 = C - (d1-d2);
        /*
        if(l1!=0){
            if(l1%2==0){
                cout<<"Q "<<(l1/2)<<" "<<(l1/2)<<flush<<endl;
                ll l2;
                cin>>l2;
                cout<<"Q "<<(l1/2)+(l2)<<" "<<(l1/2)-(l2)<<flush<<endl;
                ll l3;
                cin>>l3;
                if(l3==0){
                    x1 = (l1/2)+(l2);
                    y1 = (l1/2)-(l2);
                }
                else{
                    x1 = (l1/2)-(l2);
                    y1 = (l1/2)+(l2);
                }
            }
            else{
                cout<<"Q "<<(l1/2)<<" "<<((l1/2)+1)<<flush<<endl;
                ll l2;
                cin>>l2;
                cout<<"Q "<<(l1/2)+(l2)<<" "<<(l1/2)+1-(l2)<<flush<<endl;
                ll l3;
                cin>>l3;
                if(l3==0){
                    x1 = (l1/2)+(l2);
                    y1 = (l1/2)+1-(l2);
                }
                else{
                    x1 = (l1/2)-(l2);
                    y1 = (l1/2)+1+(l2);
                }
            }
        }
        cout<<"Q 1000000000 1000000000"<<flush<<endl;
        cin>>l1;
        if(l1!=0){
            if(l1%2==0){
                cout<<"Q "<<C-(l1/2)<<" "<<C-(l1/2)<<flush<<endl;
                ll l2;
                cin>>l2;
                cout<<"Q "<<C-(l1/2)+(l2)<<" "<<C-(l1/2)-(l2)<<flush<<endl;
                ll l3;
                cin>>l3;
                if(l3==0){
                    x2 = C-(l1/2)+(l2);
                    y2 = C-(l1/2)-(l2);
                }
                else{
                    x2 = C-(l1/2)-(l2);
                    y2 = C-(l1/2)+(l2);
                }
            }
            else{
                cout<<"Q "<<C-(l1/2)<<" "<<C-((l1/2)+1)<<flush<<endl;
                ll l2;
                cin>>l2;
                cout<<"Q "<<C-(l1/2)-(l2)<<" "<<C-((l1/2)+1)+(l2)<<flush<<endl;
                ll l3;
                cin>>l3;
                if(l3==0){
                    x2 = C-(l1/2)-(l2);
                    y2 = C-((l1/2)+1)+(l2);
                }
                else{
                    x2 = C-(l1/2)+(l2);
                    y2 = C-((l1/2)+1)-(l2);
                }
            }
        }
        */
        cout<<"A "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<flush<<endl;
        int temp;
        cin>>temp;
        if(temp<0)break;
    }
    return 0;
}
