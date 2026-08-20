// [Expected Approach 2] Using Manacher's Algorithm
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// manacher's algorithm for finding longest
// palindromic substrings
class manacher
{
public:
    // array to store palindrome lengths centered
    // at each position
    vector<int> p;
    // modified string with separators and sentinels
    string ms;

    manacher(string &s)
    {
        ms = "@";
        for (char c : s)
        {
            ms += "#" + string(1, c);
        }
        ms += "#\$";
        runManacher();
    }

    // core Manacher's algorithm
    void runManacher()
    {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n - 1; ++i)
        {
            if (i < r)
                p[i] = min(r - i, p[r + l - i]);

            // expand around the current center
            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]])
                ++p[i];

            // update center if palindrome goes beyond
            // current right boundary
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    // returns the length of the longest palindrome
    // centered at given position
    int getLongest(int cen, int odd)
    {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    // checks whether substring s[l...r] is a palindrome
    bool check(int l, int r)
    {
        int len = r - l + 1;
        int longest = getLongest((l + r) / 2, len % 2);
        return len <= longest;
    }
};

// returns the minimum number of characters to add at the
// front to make the given string a palindrome
int minChar(string &s)
{
    int n = s.size();
    manacher m(s);

    // scan from the end to find the longest
    // palindromic prefix
    for (int i = n - 1; i >= 0; --i)
    {
        if (m.check(0, i))
            return n - (i + 1);
    }

    return n - 1;
}

int main()
{
    string s = "aacecaaaa";
    cout << minChar(s) << endl;
    return 0;
}