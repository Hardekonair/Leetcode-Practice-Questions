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

void count_nodes(struct Node*p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    cout<<"Total Number of Nodes are:  "<<count<<endl;
}
void sum(struct Node*p){
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    cout<<"Total sum of Nodes are:  "<<sum<<endl;
}


int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    cout<<endl;
    sum(first);
    cout<<endl;
    count_nodes(first);
    cout<<endl; 
    return 0;
}