// Online C++ compiler to run C++ program online
#include <iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

bool detectLoop(Node* head){
    if (head==NULL){
        return 0;
    }
    map<Node*,bool> visited;
    
    Node* temp=head;
    
    while(temp!=NULL){
        if (visited[temp]==true ){
            cout<<"Present at"<<temp->data<<endl;
            return 1;
        }
        
        visited[temp]=true;
        temp=temp->next;
    }
    return 0;
}

//more better floyd detect approach
  bool hasCycle(ListNode *head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast){
                return true;
            }
        }
        return false;
      
    }
    
// won't work for this usecase [1,2]
Node* floydDetectLoop(Node* head){
    if (head==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if (fast!=NULL){
            fast=fast->next;
        }
    
        slow=slow->next;
        if(slow==fast){
            cout<<"Loop Present At "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    Node* node1=new Node(10);
    Node* node2=new Node(12);
    Node* node3=new Node(14);
    
    Node* head=node1;
    
    head->next=node2;
    
    node2->next=node3;
    
    node3->next=node2;
    
    // if(detectLoop(head)){
    //     cout<<"Loop is present"<<endl;
    // }
    // else{
    //     cout<<"Loop is not present"<<endl;
    // }
    if(floydDetectLoop(head)!=NULL){
        cout<<"Loop is Present"<<endl;
    }
    else{
        cout<<"Loop is not Present"<<endl;
    }
    
    
    return 0;
}