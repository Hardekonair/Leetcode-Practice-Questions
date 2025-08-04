#include<iostream>

using namespace std;

struct Matrix{
    int *A;
    int n;
};

void set(struct Matrix *m, int i,int j,int x)
{
    if(i>=j)
        m->A[i*(i+1)/2+j]=x;
}

void get(struct Matrix m, int i,int j){
    if(i>=j)
        cout<<m.A[i*(i+1)/2+j]<<endl;
    else
        cout<<"0 ";
}

void display(struct Matrix m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            if(i>=j)
                cout<<m.A[i*(i+1)/2+j]<<" ";
            else 
                cout<<"0 ";
        }
        cout<<endl;
    }

}


int main(){
    struct Matrix m;
    cout<<"enter dimension";
    cin>>m.n;

    m.A=new int[m.n*(m.n+1)/2];

    cout<<"enter elements";

    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            int x;
            cin>>x;
            set(&m,i,j,x);
        }
    }

    cout<<"Displaying Matrix \n";
    display(m);

    get(m,1,2);
    get(m,2,2);
    get(m,2,0);
    get(m,3,3);


    return 0;
}