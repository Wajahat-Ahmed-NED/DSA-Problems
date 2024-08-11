// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
int main()
{
    // Write C++ code here
    cout << "Hello world!" << endl;

    unordered_map<string, int> m;

    m["love"] = 2;
    cout << m["love"] << endl;
    cout << m.at("love") << endl;

    // cout<<m.at("  ")<<endl; // will give error because babbar is not present

    cout << m["babbar"] << endl; // will create key if not present
    cout << m.at("babbar") << endl;

    cout << m.size() << endl;

    // check if present or not
    cout << m.count("babbar") << endl;
    cout << m.count("unknown") << endl;

    // iterator
    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    // to remove
    cout << m.erase("babbar") << endl;

    cout << m.size() << endl;
    return 0;
}