// Source :  HackerRank

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;
    cin.ignore();
    vector<int> arr;
    int pointer = 0;

    for (int i = 0; i < n; i++)
    {

        string operation;
        getline(cin, operation);

        if (operation[0] == '1')
        {
            arr.push_back(stoi(operation.substr(2)));
        }
        else if (operation[0] == '2')
        {
            pointer++;
        }
        else if (operation[0] == '3')
        {
            // cout<<pointer<<endl;
            if (pointer < arr.size())
            {
                cout << arr[pointer] << endl;
            }
            else
                cout << -1 << endl;
        }
        // cout<<operation<<endl;
    }
    return 0;
}
