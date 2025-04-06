#include <bits/stdc++.h>
using namespace std;

// Gives memory limit exceeded in Leetcode.
// Good for Interviews.
// Optimized Version is for CP purposes.
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        if (st.find(endWord) == st.end())
            return {};
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> elementsToRemove;
        int prevLevelSize = 0;

        while (!q.empty())
        {
            vector<string> wordVector = q.front();
            if (prevLevelSize != wordVector.size())
            {
                prevLevelSize = wordVector.size();
                for (int i = 0; i < elementsToRemove.size(); i++)
                {
                    st.erase(elementsToRemove[i]);
                }
                elementsToRemove.clear();
            }

            string word = wordVector.back();

            if (word == endWord)
                break;

            q.pop();

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.find(word) != st.end())
                    {
                        wordVector.push_back(word);
                        q.push(wordVector);
                        elementsToRemove.push_back(word);
                        wordVector.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        vector<vector<string>> ans;

        while (!q.empty())
        {
            if (q.front().back() == endWord)
            {
                ans.push_back(q.front());
            }
            q.pop();
        }

        return ans;
    }
};