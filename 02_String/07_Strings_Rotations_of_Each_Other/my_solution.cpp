#include <bits/stdc++.h>
using namespace std;

// Brute Force / Repeated Rotation
/*
bool areRotations(string &s1, string &s2)                   // O(n²)
{
    string rot = s1;
    for (int i = 0; i < s1.length(); i++)                   //  O(n)
    {
        rotate(rot.begin(), rot.begin() + i, rot.end());    //  O(n)

        if (rot == s2)
        {
            // cout << "True" << endl;
            return true;
        }
    }
    // cout << "False" << endl;
    return false;
}
*/

// String Concatenation + Substring Search
/*
bool areRotations(string &s1, string &s2)
{
    if (s1.length() != s2.length())
    return false;

    string temp = s1 + s1;

    return temp.find(s2) != string::npos;
}
*/

// KMP Pattern Matching
void constructLps(string &pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pat.length())
    {
        if (pat[i] == pat[len])
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

bool areRotations(string &s1, string &s2)
{
    if(s1.length() != s2.length()) // Edge Case
        return false;

    int m = s2.length();
    vector<int> lps(m);
    
    constructLps(s2, lps);

    string combined = s1 + s1;

    int i = 0;
    int j = 0;

    while (i < combined.length())
    {
        if (combined[i] == s2[j])
        {
            i++;
            j++;

            if (j == m)
            {
                // cout << "True" << endl;
                return true;
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    // cout << "False" << endl;
    return false;
}

// In-place / Constant-Space Rotation Matching

int main()
{
        string s1 = "abcd";
        string s2 = "cdab";

    // string s1 = "abcd";
    // string s2 = "cdba";

    if (areRotations(s1, s2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}