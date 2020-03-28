#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct Node {
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b;
    cin>>n;
    Node* heads[n+1]={nullptr};
    Node* tails[n+1]={nullptr};
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        if(heads[a]==nullptr && heads[b]==nullptr){
            struct Node* tempA = new Node();
            struct Node* tempB = new Node();
            tempA->data = a;
            tempB->data = b;
            tempA->next = tempB;
            tempB->prev = tempA;
            tempB->next = nullptr;
            tempA->prev = nullptr;
            heads[a] = tempB;
            heads[b] = tempB;
            tails[a] = tempA;
            tails[b] = tempA;
        }
        else if(heads[a]==nullptr){
            struct Node* tempA = new Node();
            tempA->data = a;
            struct Node* tempB = tails[b];
            while(tempB->prev!=nullptr){
                tempB = tails[tempB->prev->data];
            }
            tempA->next = tempB;
            tempA->prev = nullptr;
            tempB->prev = tempA;
            heads[a] = heads[b];
            tails[a] = tempA;
            tails[b] = tempA;
        }
        else if(heads[b]==nullptr){
            struct Node* tempB = new Node();
            tempB->data = b;
            struct Node* tempA = heads[a];
            while(tempA->next!=nullptr){
                tempA = heads[tempA->next->data];
            }
            tempB->prev = tempA;
            tempB->next = nullptr;
            tempA->next = tempB;
            heads[b] = tempB;
            heads[a] = tempB;
            tails[b] = tails[a];
        }
        else{
            struct Node* tempA = heads[a];
            struct Node* tempB = tails[b];
            while(tempA->next!=nullptr){
                tempA = heads[tempA->next->data];
            }
            while(tempB->prev!=nullptr){
                tempB = tails[tempB->prev->data];
            }
            tempA->next = tempB;
            tempB->prev = tempA;
        }
        /*
        for(int i=1;i<=n;i++){
            if(heads[i]!=nullptr)cout<<i<<":   "<<heads[i]->data<<"    "<<tails[i]->data<<endl;
        }
        */
    }
    struct Node* start = heads[1];
    //cout<<endl;
    /*
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<arr[i]->data<<endl;
        if(arr[i]->prev==nullptr){
            start = arr[i];
            break;
        }
    }
    */
    while(start->prev != nullptr){
        start = start->prev;
    }
    while(start!=nullptr){
        cout<<start->data<<" ";
        start = start->next;
    }
    cout<<endl;
}
