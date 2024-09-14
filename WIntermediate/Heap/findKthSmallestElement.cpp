#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// O(n logk)
int kthSmallest(vector<int> &arr, int k)
{
    // Create a max-heap (priority_queue by default is a max-heap)
    priority_queue<int> maxHeap;
    // priority_queue<int, vector<int>, greater<int>> minHeap; // For Kth largest elem

    // Insert the first k elements into the heap
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(arr[i]);
    }

    // For the rest of the elements, maintain a heap of size k
    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] < maxHeap.top())
        {
            maxHeap.pop();        // Remove the largest element
            maxHeap.push(arr[i]); // Insert the current smaller element
        }
    }

    // The root of the heap is the k-th smallest element
    return maxHeap.top();
}

int main()
{
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 2;

    cout << "The " << k << "-th smallest element is " << kthSmallest(arr, k) << endl;

    return 0;
}
