// Source: Coding Ninjas
// Link : https://www.codingninjas.com/studio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=1&campaign=YouTube_codestudio_lovebabbar28thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_codestudio_lovebabbar28thjan

/*************************************************

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
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

        if (fast == slow)
        {
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

    Node *intermediate = floydDetectLoop(head);
    Node *slow = head;

    if (intermediate == NULL)
    {
        return NULL;
    }

    while (slow != intermediate)
    {
        intermediate = intermediate->next;
        slow = slow->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    if (head == NULL)
    {
        return NULL;
    }
    Node *startNode = getStartingNode(head);
    Node *temp = startNode;

    if (startNode == NULL)
    {
        return head;
    }

    while (temp->next != startNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
