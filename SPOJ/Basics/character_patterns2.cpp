#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int row,col;
        cin>>row>>col;
        for(int r=1;r<=row;r++){
            for(int c=1;c<=col;c++)
            {
                if(r==1 || r==row){
                    cout<<"*";
                }
                else if(c==1||c==col){
                    cout<<"*";
                }
                else{
                    cout<<".";

                }
            }
            cout<<endl;
        }
        cout<<endl;

    }
    return 0;
}
