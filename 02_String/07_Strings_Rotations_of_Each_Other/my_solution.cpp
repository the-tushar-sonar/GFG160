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
bool areRotations(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;

    string temp = s1 + s1;

    return temp.find(s2) != string::npos;
}
// KMP Pattern Matching
// In-place / Constant-Space Rotation Matching

int main()
{
    string s1 = "abcd";
    string s2 = "cdab";

    areRotations(s1, s2);

    return 0;
}