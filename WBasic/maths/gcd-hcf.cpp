#include <iostream>
using namespace std;

int main()
{

    int n1, n2;
    cin >> n1;
    cin >> n2;

    int gcd = 1;

    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }

    cout << gcd << endl;

    return 0;
}

// =========More Optimized==========
#include <iostream>
using namespace std;

int main()
{

    int a, b;

    cin >> a;
    cin >> b;

    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        cout << b;
    else
        cout << a;

    return 0;
}