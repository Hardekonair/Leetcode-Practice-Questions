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
void reverse_recursive_display(struct Node *p){
    if(p!=NULL){
        reverse_recursive_display(p->next);
        cout<<p->data<<" ";
    }
}



int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    cout<<endl;
    cout<<"Displaying reverse recursive display function: "<<endl;
    reverse_recursive_display(first);
    cout<<endl;
    cout<<endl;
    return 0;
}