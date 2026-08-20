// [Naive Approach] Checking all prefixes - O(n^2) Time and O(1) Space
#include <iostream>
using namespace std;

// function to check if the substring s[i...j] is a palindrome
bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {

        // if characters at the ends are not equal,
        // it's not a palindrome
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minChar(string &s)
{
    int cnt = 0;
    int i = s.size() - 1;

    // iterate from the end of the string, checking for the
    // longestpalindrome starting from the beginning
    while (i >= 0 && !isPalindrome(s, 0, i))
    {

        i--;
        cnt++;
    }

    return cnt;
}

int main()
{
    string s = "aacecaaaa";
    cout << minChar(s);
    return 0;
}