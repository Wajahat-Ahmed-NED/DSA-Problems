#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime(i) && arr.push_back(i);
            if (n % i != i)
            {
                isPrime(n / i) && arr.push_back(n / i);
            }
        }
    }

    return 0;
}

//==========More Optimized Approach==========
// Take L.C.M of the Number

int main()
{

    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            arr.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }

    return 0;
}

// For large prime num T.C ==> O(n)
//  b/c loop will run till O(n) if n=13 loop will run till 1...13

int main()
{

    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }

    if (n != 1)
        arr.push_back(n);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
