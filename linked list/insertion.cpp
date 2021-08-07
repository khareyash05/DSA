// to insert in linked list
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
}*start,*save,*nptr,*ptr;

Node * createNewNode(int);
void insertBeg(Node*);
void display(Node*);

int main(){
    start=NULL;
    save=NULL;
    char ch ='y';
    while(ch=='y'|| ch=='Y'){
        int data;
        cin>> data;
        nptr = createNewNode(data);
        if(nptr!=NULL){
            cout << "\nNew Node created";
        }
        else{
            cout <<"Cannot create new node\n";
            exit(1);
        } 
        cout<<"Now insert node\n";
        insertBeg(nptr);
        cout << "Now the list is \n";
        display(start);
        cout << "\nPress y or Y to add more nodes\n";
        cin>>ch;
    }
}

Node * createNewNode(int data){
    ptr= new Node;
    ptr->data = data;
    ptr->next=NULL;
    return ptr;
}

void insertBeg(Node*np){
    if(start==NULL) start=np;
    else{
        save=start;
        start=np;
        np->next=save;
    }
}

void display(Node*np){
    while(np!=NULL){
        cout << np->data << "-->";
        np=np->next;
    }
}