#include <bits/stdc++.h>
using namespace std;

// void constructLps(string &pat, vector<int> &lps)
void constructLps(const string &str, vector<int> &lps)
{
    int len = 0;

    for (int i = 1; i < str.length();)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int minChar(const string &s)
{

    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = s + "$" + rev;

    vector<int> lps(combined.size());

    constructLps(combined, lps);

    // cout << pat << endl;
    // cout << "Last Value of LPS : " << lps[lps.size() - 1] << endl;
    int longestPalindromicPrefix = lps.back();
    // cout << "The answer is : " << ans << endl;

    return s.size() - longestPalindromicPrefix;
}

struct TestCase
{
    string s;
    int expected;
};

int main()
{
    // string s = "abc";
    // minChar(s);

    // int res = minChar(s);

    // cout << res << endl;

    vector<TestCase> testCases =
        {
            {"a", 0},
            {"aa", 0},
            {"aba", 0},
            {"abba", 0},
            {"abcba", 0},
            {"racecar", 0},

            {"ab", 1},
            {"abc", 2},
            {"abcd", 3},
            {"aab", 1},
            {"aabc", 2},
            {"baa", 2},
            {"abcdc", 4},
            {"abab", 1},
            {"aabba", 3},

            {"aacecaaaa", 2},
            {"aaaaab", 1},
            {"baaaa", 4},
            {"aaab", 1},
            {"abca", 3},
            {"abcda", 4},
            {"abac", 1},
            {"aaba", 2},
            {"aabaa", 0},

            {"abcde", 4},
            {"abcdef", 5},
            {"aabb", 2},
            {"aabbc", 3},
            {"abb", 2},
            {"abbc", 3},

            {"aaaa", 0},
            {"aaaaa", 0},
            {"aaabaaa", 0},
            {"baaab", 0},
            {"baab", 0},
            {"bbaa", 2}};

    for (const auto &test : testCases)
    {
        int result = minChar(test.s);

        cout << "Input: " << test.s
             << "\t| Expected: " << test.expected
             << "\t| Got: " << result;

        if (result == test.expected)
            cout << "\t✅ PASS\n";
        else
            cout << "\t❌ FAIL\n";
    }

    return 0;
}