class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto i : arr)
            minHeap.push(i);

        int sum = 0;

        while (minHeap.size() >= 2)
        {
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            sum += first + second;
            minHeap.push(first + second);
        }

        return sum;
    }
};