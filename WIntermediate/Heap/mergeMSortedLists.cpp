// Normal Approach using map and set.
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        unordered_map<int, vector<ListNode *>> map;
        set<int> sortedSet;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *first = lists[i];
            while (first != nullptr)
            {
                map[first->val].push_back(first);
                sortedSet.insert(first->val);
                first = first->next;
            }
        }

        ListNode *result = new ListNode(0);
        ListNode *ans = result;

        for (auto i : sortedSet)
        {
            // vector<ListNode*> arr=map[i];
            for (auto node : map[i])
            {
                result->next = node;
                result = result->next;
            }
        }

        return ans->next;
    }
};

// Using heap for optimized approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val; // Min-heap
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                pq.push(lists[i]);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *ans = dummy;

        while (!pq.empty())
        {
            ListNode *smallest = pq.top();
            pq.pop();

            dummy->next = smallest;
            dummy = dummy->next;

            if (smallest->next)
            {
                pq.push(smallest->next);
            }
        }

        return ans->next;
    }
};