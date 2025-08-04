#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    struct Node *newNode,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        newNode=new Node;
        newNode->data=A[i];
        newNode->next=NULL;
        last->next=newNode;
        last=newNode;

    }

}

void max(struct Node *p){
    int maxi=0;
    while(p){
        if(maxi<p->data){
            maxi=p->data;
        }
        p=p->next;
    }
    cout<<"maximum element is : "<<maxi;
    
}

int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    cout<<endl;
    max(first);
    // cout<<endl;
    // count_nodes(first);
    cout<<endl; 
    return 0;
}