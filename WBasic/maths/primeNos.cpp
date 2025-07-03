#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            break;
        }
    }
    if (cnt > 0)
        cout << "Not a prime " << endl;
    else
        cout << "Prime " << endl;

    return 0;
}

// more optimized approach

#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n % i != i)
            {
                cnt++;
            }
        }
    }
    if (cnt == 2)
        cout << "Prime " << endl;
    else
        cout << "Not a Prime " << endl;

    return 0;
}
