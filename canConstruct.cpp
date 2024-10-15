#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
        {
            return false;
        }
        unordered_map<char, int> map;

        for (char c : magazine)
        {
            ++map[c];
        }

        for (char c : ransomNote)
        {
            if (--map[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        vector<int> v(26);
        for (auto &c : magazine)
        {
            v[c - 'a']++;
        }
        for (auto &c : ransomNote)
        {
            if (--v[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};