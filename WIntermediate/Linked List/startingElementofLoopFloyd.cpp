// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "Present at" << temp->data << endl;
            return 1;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
        if (slow == fast)
        {
            cout << "Loop Present At " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydDetectLoop(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

int main()
{
    // Write C++ code here
    // std::cout << "Hello world!";
    Node *node1 = new Node(10);
    Node *node2 = new Node(12);
    Node *node3 = new Node(14);

    Node *head = node1;

    head->next = node2;

    node2->next = node3;

    node3->next = node2;

    // if(detectLoop(head)){
    //     cout<<"Loop is present"<<endl;
    // }
    // else{
    //     cout<<"Loop is not present"<<endl;
    // }
    if (floydDetectLoop(head) != NULL)
    {
        cout << "Loop is Present" << endl;
    }
    else
    {
        cout << "Loop is not Present" << endl;
    }

    Node *loop = getStartingNode(head);
    cout << "Starting Element of Loop is " << loop->data << endl;

    return 0;
}

// corrected code
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *floydDetection(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }

            slow = slow->next;
            if (slow == fast)
            {
                return slow;
            }
        }

        return NULL;
    }

    ListNode *getStartingNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *inter = floydDetection(head);
        if (inter == NULL)
            return NULL; // No cycle found
        ListNode *slow = head;

        while (slow != inter)
        {
            inter = inter->next;
            slow = slow->next;
        }

        return slow;
    }
    ListNode *detectCycle(ListNode *head)
    {
        return getStartingNode(head);
    }
};