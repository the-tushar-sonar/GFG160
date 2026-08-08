// Recursive Approach - O(n) Time and O(n) Space
#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Parse digits recursively with overflow handling
int parseDigits(const string &s, int idx, int res, int sign)
{
    if (idx >= s.size() || s[idx] < '0' || s[idx] > '9')
        return res * sign;

    int digit = s[idx] - '0';

    if (res > (INT_MAX - digit) / 10)
        return sign == 1 ? INT_MAX : INT_MIN;

    return parseDigits(s, idx + 1, res * 10 + digit, sign);
}

int myAtoi(string &s)
{
    int idx = 0;

    // Skip leading spaces
    while (idx < s.size() && s[idx] == ' ')
        idx++;

    int sign = 1;

    // Handle sign
    if (idx < s.size() && (s[idx] == '-' || s[idx] == '+'))
    {
        if (s[idx] == '-')
            sign = -1;
        idx++;
    }

    return parseDigits(s, idx, 0, sign);
}

int main()
{

    string s = " -0012g4";
    cout << myAtoi(s) << endl;
    return 0;
}