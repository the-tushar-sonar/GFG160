// [Efficient Approach 1] Using Frequency Array (Two Traversal) – O(2*n) Time and O(MAX_CHAR ) Space
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

char nonRep(const string &s)
{
    vector<int> freq(MAX_CHAR, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    // Find the first character with frequency 1
    for (char c : s)
    {
        if (freq[c - 'a'] == 1)
        {
            return c;
        }
    }
    return '\$';
}

int main()
{
    string s = "geeksforgeeks";
    cout << nonRep(s) << endl;
    return 0;
}