class Solution
{
private:
    vector<int> prime = getSieve(5 * 1e5);

public:
    vector<int> getSieve(int n)
    {

        vector<int> arr(n + 1, 1);
        arr[0] = arr[1] = 0;
        int cnt = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (arr[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    arr[j] = 0;
                }
            }
        }

        long long count = 0;
        long long prevCount = 0;

        // This logic tooks hours of me.
        for (int i = 2; i <= n; i++)
        {

            if (arr[i])
            {
                count += i;
                if (count <= n && arr[count])
                {
                    arr[count] = count;
                }
                if (arr[i] == i)
                {
                    prevCount = i;
                }
                else
                    arr[i] = prevCount;
            }

            else
                arr[i] = prevCount;
        }

        return arr;
    }
    int largestPrime(int n)
    {
        return prime[n];
    }
};