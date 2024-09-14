// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int reverseNum(int ans, int n)
{
    if (n == 0)
        return ans;

    int digit = n % 10;
    n = n / 10;
    ans = ans * 10 + digit;
    // cout<<"Ans is "<<ans<<endl;
    return reverseNum(ans, n);
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    int n;
    cout << "Enter Number " << endl;
    cin >> n;
    cout << reverseNum(0, n) << endl;

    return 0;
}