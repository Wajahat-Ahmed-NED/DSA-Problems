// #Sieve of Erastothenesis -- Topic
// Source : LeetCode

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;
        int count = 0;

        for (int i = 2; i < n; i++)
        {
            if (primes[i])
            {
                count++;
                for (int j = i * 2; j < n; j = j + i)
                {
                    primes[j] = false;
                }
            }
        }

        return count;
    }
};

//========More Optimized=============

class Solution
{
public:
    int countPrimes(int n)
    {

        vector<bool> arr(n + 1, true);
        arr[0] = arr[1] = false;
        int cnt = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (arr[i])
            {
                for (int j = i * i; j <= n; j = i == 2 ? j + i : 2 * i + j)
                {
                    arr[j] = false;
                }
            }
        }

        for (int k = 0; k < arr.size() - 1; k++)
        {
            if (arr[k])
                cnt++;
        }
        return cnt;
    }
};

// LeetCode Solution

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;

        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        int cnt = 2;

        for (int i = 2; i * i <= n; i++)
        {
            if (primes[i])
            {
                for (int j = i * i; j < n; j = j + i)
                {
                    if (primes[j])
                    {
                        primes[j] = false;
                        cnt++;
                    }
                }
            }
        }

        return n - cnt;
    }
};

// Practice
vector<int> arr(n + 1, 1);
arr[0] = arr[1] = 0;

for (int i = 2; i * i <= n; i++)
{
    if (arr[i])
    {
        for (int j = i * i; j < n; j = j + i)
        {
            if (arr[j])
            {
                arr[j] = 0;
            }
        }
    }
}

return arr;