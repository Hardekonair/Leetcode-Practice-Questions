#include<iostream>

using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;      
};

class dll{
    private: 
        Node* head;
    public:
        dll();
        dll(int A[],int n);
        void display();
        int length();
        void insert(int pos,int x);
        int dlt(int pos);
        void reverse();
        ~dll();
};

dll::dll(){
    head=new Node;
    head->prev=nullptr;
    head->data=0;
    head->next=nullptr;
}

dll::dll(int A[],int n){
    Node *last,*temp;
    head=new Node;
    
    head->prev=nullptr;
    head->data=A[0];
    head->next=nullptr;
    last=head;

    for(int i=1;i<n;i++){
        temp=new Node;
        temp->data=A[i];
        temp->prev=last;
        temp->next=nullptr;
        last->next=temp;
        last=temp;
    }
}

void dll::display(){
    Node *temp=head;

    while(temp){
        cout<<temp->data;
        if(temp->next!=nullptr)
            cout<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int dll::length(){
    Node *temp=head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

void dll::insert(int pos,int x){
    Node *temp,*p=head;
    temp=new Node;
    temp->data=x;
    temp->prev=nullptr;
    temp->next=nullptr;
    if(pos==1){
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else{
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        temp->next=p->next;
        temp->prev=p;
        if(p->next)
            p->next->prev=temp;
        p->next=temp;
        
    }
}

int dll::dlt(int pos){
    Node *temp=head;
    int x;
    if(pos==1 && head){
        head=head->next;
        if(temp->next){
            head->prev=nullptr;
        }
        x=temp->data;
        temp->next=nullptr;
        delete temp;
    }
    else{
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        x=temp->data;
        temp->prev->next=temp->next;
        if(temp->next){
            temp->next->prev=temp->prev;
        }
    }
    return x;
}

void dll::reverse(){
    Node *p=head;
    Node *temp;
    while (p!=nullptr){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;

        if(p->next==nullptr){
            p->next=p->prev;
            p->prev=nullptr;
            head=p;
            break;
        }
    }
}

dll::~dll(){
    Node* p=head;
    while(head){
        head=head->next;
        delete p;
        p=head;
    }
}

int main(){
    int A[]={1,2,3,4,5};
    dll list(A,5);
    cout<<"Displaying Doubly Linked List"<<endl;
    list.display();
    cout<<endl;
    cout<<"Displaying length of Doubly Linked List"<<endl;
    cout<<list.length()<<endl<<endl;
    cout<<"Inserting element in Doubly Linked List"<<endl;
    list.insert(4,99);
    list.display();
    cout<<endl;
    cout<<"Deleting element in Doubly Linked List"<<endl;
    list.dlt(4);
    list.display();
    cout<<endl;
    cout<<"Reversing Doubly linked list"<<endl;
    list.reverse();
    list.display();
    cout<<endl;
    

    return 0;
}