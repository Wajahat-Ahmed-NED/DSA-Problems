// Hacker Rank Problem: To separte the number and find if it is a beautiful
// string or not.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void separateNumbers(string s)
{
    int ind = 1;
    string b = s.substr(0, ind);
    bool flag = false;

    while (b.size() * 2 <= s.size())
    {
        string newStr = b;
        long base = stoll(b);
        while (newStr.size() < s.size())
        {
            base++;
            newStr += to_string(base);
        }

        if (newStr == s)
        {
            cout << "YES " << b;
            flag = true;
            break;
        }
        else
        {
            ind++;
            b = s.substr(0, ind);
        }
    }

    if (!flag)
        cout << "NO";
    cout << endl;
}