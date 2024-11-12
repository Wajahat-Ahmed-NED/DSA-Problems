#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
void reverse(LinkedListNode<int> *&head, LinkedListNode<int> *curr, LinkedListNode<int> *prev)
{

    if (curr == NULL)
    {
        head = prev;
        return;
    }

    LinkedListNode<int> *forward = curr->next;

    curr->next = prev;
    reverse(head, forward, curr);
    // curr->next=prev; will give same result
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    // Write your code here
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    reverse(head, curr, prev);

    return head;

    // if(head==NULL || head->next==NULL){
    //     return head;
    // }

    // LinkedListNode<int>* prev=NULL;
    // LinkedListNode<int>* curr=head;
    // LinkedListNode<int>* forward=NULL;

    // while(curr!=NULL){
    //     forward=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=forward;
    // }
    // return prev;
}