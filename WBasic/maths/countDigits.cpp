// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";

    int n;
    cin >> n;

    int ans = (int)(log10(n) + 1);

    cout << ans << endl;

    return 0;
}

// <=========== OR ============>

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";

    int n;
    cin >> n;
    vector<int> ans;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            ans.push_back(i);
    }

    for (auto c : ans)
    {
        cout << c << " ";
    }

    return 0;
}