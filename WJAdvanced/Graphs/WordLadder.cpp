#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach
//  TC: O(N*WordSize*26) N=wordList.size()
//  SC: O(N)

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if (endWord == word)
                return level;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (s.find(word) != s.end())
                    {
                        s.erase(word);
                        q.push({word, level + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};