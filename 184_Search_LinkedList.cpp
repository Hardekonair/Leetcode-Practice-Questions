#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head=NULL;

void create(int arr[],int n){
    struct Node *newNode, *temp;

    newNode=new Node;
    newNode->data=arr[0];
    newNode->next=NULL;

    head=newNode;
    temp=newNode;

    for(int i=1;i<n;i++){
        newNode=new Node;
        newNode->data=arr[i];
        newNode->next=NULL;
        temp->next=newNode;
        temp=newNode;
    }
}

void display(Node *head){
    while(head!=NULL){
        cout<<head->data<<" "; 
        head=head->next;
    }

}

void LinearSearch(Node *head,int key){
    while(head!=NULL){
        if(head->data==key){         //
            cout<<"key Found is "<<key<<endl;
            return ;
        }
        head=head->next;
    }

}

Node* RecursiveLS(Node *temp,int key){
    if(head==NULL)
        return NULL;
    if(temp->data==key)
        return temp;
    return RecursiveLS(temp->next, key);

}

Node* ImproveLS(Node* temp,int key){
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==key){
            prev->next=temp->next;
            temp->next=head;
            head=temp;
        }
        prev=temp;
        temp=temp->next;
    }
}



int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    create(arr,9);
    cout<<endl<<"displaying the linked list"<<endl;
    display(head);
    cout<<endl;
    cout<<endl<<"searching in a linked list"<<endl;
    LinearSearch(head,8);
    cout<<endl;
    cout<<endl<<"Recursive searching in a linked list";
    Node *p=RecursiveLS(head,5);
    if(p)
        cout<<endl<<"Key found is :"<<p->data<<endl;
    else 
        cout<<endl<<"Key not found"<<endl;

    cout<<endl;
    cout<<"Performing Modified LINEAR SEARCH "<<endl;
    cout<<"searching 7"<<endl;
    ImproveLS(head,7);
    cout<<"searching 9"<<endl;
    ImproveLS(head,9);
    cout<<"Displaying after searching"<<endl;
    display(head);
    return 0;
}