// BruteForce Approach O(nlogn)

vector<int> countBits(int n)
{

    vector<int> totalCnts;
    for (int i = 0; i <= n; i++)
    {
        int cnt = 0;
        int n = i;
        while (n != 0)
        {
            cnt++;
            n = n & (n - 1);
        }
        totalCnts.push_back(cnt);
    }

    return totalCnts;
}

// Optimized Approach O(n)
vector<int> countBits(int n)
{

    // Use Prefix Sum

    vector<int> totalCnts(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        totalCnts[i] = totalCnts[i & (i - 1)] + 1;
    }

    return totalCnts;
}