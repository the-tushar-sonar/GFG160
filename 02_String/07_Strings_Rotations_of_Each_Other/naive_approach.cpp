// [Naive Approach] Generating all rotations - O(n^2) Time and O(1) Space
#include <iostream>
using namespace std;

bool areRotations(string &s1, string &s2)
{
    int n = s1.size();

    // generate and check all possible rotations of s1
    for (int i = 0; i < n; ++i)
    {

        // if current rotation is equal to s2 return true
        if (s1 == s2)
            return true;

        // right rotate s1
        char last = s1.back();
        s1.pop_back();
        s1 = last + s1;
    }
    return false;
}

int main()
{
    string s1 = "aab";
    string s2 = "aba";

    cout << (areRotations(s1, s2) ? "true" : "false");
    return 0;
}