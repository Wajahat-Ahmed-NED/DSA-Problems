// Source : Coding Ninjas
// Link : https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTab=1

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
int getLength(Node* head){
    // if (head==NULL){

    // }
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    // Write your code here

    int len=getLength(head);
    int ans=len/2;

    int cnt=0;
    Node* temp=head;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
}


