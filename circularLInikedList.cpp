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

void deleteAtNode(Node* &tail,int element){
    if(tail==NULL){
        cout<<"there are no elements int the linked list"<<endl;
    }
    else{
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=element){
            prev=prev->next;
            curr=curr->next;
        }
        prev->next=curr->next;
        //when there is onlty one element in the cll
        if(curr==tail){
            tail=prev;
        }
        //when there are two elements in the cll
        if(curr==prev){
            tail=NULL;
            delete tail;
            return;
        }
        curr->next=NULL;
        delete curr;
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
    insertAtNode(tail,54,6);
    printCLL(tail);
    deleteAtNode(tail,54);
    deleteAtNode(tail,6);
    printCLL(tail);
    deleteAtNode(tail,8);
    printCLL(tail);

    return 0;
}