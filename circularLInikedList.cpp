#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //construttor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Node deleted with data - "<<val<<endl;
    }

   
};


 void insertAtNode(Node* &tail,int data,int element){
        if (tail==NULL){
            Node* temp=new Node(data);
            tail=temp;
            temp->next=temp;
        }
        else{
            Node*curr=tail;
            while(curr->data!=element){
                curr=curr->next;
            }

            Node* temp=new Node(data);
            temp->next=curr->next;
            curr->next=temp;

        }
   }

void printCLL(Node* &tail){
    if(tail==NULL){
        cout<<"there are no nodes in this circular LInked list";
    }
    cout<<tail->data<<" ";
    Node*temp=tail->next;
    int val=tail->data;
    while(temp->data!=val){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    Node* tail=NULL;
    insertAtNode(tail,5,0);
    insertAtNode(tail,6,5);
    insertAtNode(tail,7,6);
    insertAtNode(tail,8,7);
    insertAtNode(tail,9,7);
    printCLL(tail);

    return 0;
}