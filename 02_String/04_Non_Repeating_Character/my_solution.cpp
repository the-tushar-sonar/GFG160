#include <bits/stdc++.h>
using namespace std;

void nonRepeatingChar(string &s)
// char nonRepeatingChar(string &s)
{
    int freq[26] = {0};

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        // cout << freq[s[i] ] << endl;
        
        if (freq[s[i] - 'a'] == 1)
        {
            cout << s[i] << endl;
            // return s[i];
        }
    }
    cout << '$' << endl;
    // return '$';
}

int main()
{
    // string s = "geeksfaorgeeks";
    // string s = "racecar";
    // string s = "aabbccc";
    string s = "cbad";
    nonRepeatingChar(s);

    return 0;
}