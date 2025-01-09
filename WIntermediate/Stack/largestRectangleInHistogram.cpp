// Brute Force Approach
//  Source : Leet Code
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> findNSE(vector<int> &arr)
    {
        stack<int> minStack;
        vector<int> nse(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!minStack.empty() && arr[minStack.top()] >= arr[i])
                minStack.pop();
            nse[i] = minStack.empty() ? arr.size() : minStack.top();
            minStack.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int> &arr)
    {
        stack<int> minStack;
        vector<int> pse(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            while (!minStack.empty() && arr[minStack.top()] >= arr[i])
                minStack.pop();
            pse[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nse;
        vector<int> pse;

        nse = findNSE(heights);
        pse = findPSE(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxArea;
    }
};

// Most Optimal Solution
// Source : Leet Code

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();
        int element;
        int nse;
        int pse;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] > heights[i])
            {
                element = s.top();
                s.pop();
                pse = s.empty() ? -1 : s.top();
                nse = i;
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            s.push(i);
        }

        while (!s.empty())
        {
            element = s.top();
            s.pop();
            pse = s.empty() ? -1 : s.top();
            nse = n;
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }

        return maxArea;
    }
};