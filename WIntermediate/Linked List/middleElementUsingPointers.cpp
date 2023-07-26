// Source: Coding Ninjas
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

    Node* first=head->next;
    Node* second=head;

    if (head==NULL || head->next == NULL){
        return head;

    }
    // if (head->next->next==NULL){
    //     return head->next;
    // }

    while(first!=NULL){
        first=first->next;
        if (first!=NULL){
            first=first->next;
        }
        second=second->next;
    }

    return second;



    // int len=getLength(head);
    // int ans=len/2;



    // int cnt=0;
    // Node* temp=head;
    // while(cnt<ans){
    //     temp=temp->next;
    //     cnt++;
    // }
    // return temp;
}

