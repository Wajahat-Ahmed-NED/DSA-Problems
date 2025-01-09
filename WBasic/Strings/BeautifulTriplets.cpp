
// Source : Hacker Rank

// BruteForce Approach O(n^3)
int beautifulTriplets(int d, vector<int> arr)
{
    if (arr.size() < 3)
        return 0;
    int i = 0;
    int j = 1;
    int k = 2;

    int cnt = 0;

    while (i < arr.size())
    {
        j = i + 1;
        while (j < arr.size())
        {
            if (arr[j] - arr[i] == d)
            {
                k = j + 1;
                while (k < arr.size())
                {
                    if (arr[k] - arr[j] == d)
                        cnt++;
                    k++;
                }
            }
            j++;
        }
        i++;
    }

    return cnt;
}

// Optimized Approach O(n)
int beautifulTriplets(int d, vector<int> arr)
{
    unordered_map<int, int> freq;
    int count = 0;

    // Populate the frequency map
    for (int num : arr)
    {
        freq[num]++;
    }

    // Count beautiful triplets
    for (int num : arr)
    {
        if (freq[num + d] > 0 && freq[num + 2 * d] > 0)
        {
            count += freq[num + d] * freq[num + 2 * d];
        }
    }

    return count;
}