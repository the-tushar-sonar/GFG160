#include <bits/stdc++.h>
using namespace std;

// Using Hash => O(n+m)
bool areAnagrams(string &s1, string &s2)
{
    if (s1.size() != s2.size())
        return false;

    int freq[26] = {0};

    for (char c : s1)
    {
        freq[c - 'a']++;
    }

    for (char c : s2)
    {
        freq[c - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
            // cout << "NOT a Anagrams" << endl;
            // break;
        }
    }
    return true;
    // cout << "YES a Anagram" << endl;
}

// Using Sort => O(n log n + m log m)
/*
bool areAnagrams(string &s1, string &s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1.size() != s2.size())
    {
        // cout << "This not Anagram" << endl;
        return false;
    }
    // int count = 0;
    for (int i = 0; i <= s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            // cout << "This not Anagram" << endl;
            return false;
        }
        // count++;
    }
    // if (count == s1.size())
    // cout << "This Anagram" << endl;
    return true;
}
*/
struct TestCase
{
    string s1, s2;
    bool expected;
};

int main()
{
    // string s1 = "geeks";
    // string s2 = "kaseg";

    // areAnagrams(s1, s2);

    vector<TestCase> tests = {
        {"geeks", "kseeg", true},
        {"allergy", "allergyy", false},
        {"listen", "lists", false},
        {"abc", "cba", true},
        {"aabbc", "abbbc", false},
        {"a", "a", true},
        {"a", "b", false}};

    for (auto &tc : tests)
    {
        bool result = areAnagrams(tc.s1, tc.s2);

        if (result == tc.expected)
            cout << "PASS\n";
        else
            cout << "FAIL | Expected: " << tc.expected
                 << " | Got: " << result << '\n';
    }

    return 0;
}