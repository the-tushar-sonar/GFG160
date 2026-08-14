#include <bits/stdc++.h>
using namespace std;

// string addBinary(string &s1, string &s2)
// {
//     string sum;

//     int i = 1, j = 1, rem = 0;

//     // cout << "D1\tD2\tsUm\tRem\tSum" << endl;
//     while (i <= s1.size() || j <= s2.size())
//     {
//         int d1;
//         int d2;
//         if ((s1[s1.size() - i]) - '0' == 1)
//             d1 = 1;
//         else
//             d1 = 0;

//         if ((s2[s2.size() - j]) - '0' == 1)
//             d2 = 1;
//         else
//             d2 = 0;

//         int sUm = d1 + d2;

//         // cout << d1 << "\t" << d2 << "\t" << sUm << "\t" << rem << "\t";
//         if ((sUm + rem) == 1)
//         {

//             sum.insert(0, 1, '1');
//             // sum = '1' + sum;
//             rem = 0;
//             // cout << "\nsum : " << sum << endl;
//         }
//         else if ((sUm + rem) == 2)
//         {
//             sum.insert(0, 1, '0');
//             // sum = '0' + sum;
//             rem = 1;
//             // cout << "\nsum : " << sum << endl;
//         }
//         else if ((sUm + rem) == 3)
//         {
//             sum.insert(0, 1, '1');
//             // sum = '1' + sum;
//             rem = 1;
//             // cout << "\nsum : " << sum << endl;
//         }

//         else if ((sUm + rem) == 0)
//         {
//             sum.insert(0, 1, '0');
//             // sum = '0' + sum;
//             rem = 0;
//             // cout << "\nsum : " << sum << endl;
//         }

//         if (i <= s1.size())
//             i++;
//         if (j <= s2.size())
//             j++;
//         // cout << sum << endl;
//     }

//     if (rem == 1)
//     {
//         // cout << '1' + sum;
//         sum = '1' + sum;
//     }

//     sum.erase(0, sum.find_first_not_of('0'));

//     if (sum.empty())
//         sum = "0";

//     return sum;
// }

string addBinary(string &s1, string &s2)
{
    string sum;

    int i = 1;
    int j = 1;
    int rem = 0;

    while (i <= s1.size() || j <= s2.size())
    {
        int d1 = 0;
        int d2 = 0;

        // Read bit from s1 only if it exists
        if (i <= s1.size())
            d1 = s1[s1.size() - i] - '0';

        // Read bit from s2 only if it exists
        if (j <= s2.size())
            d2 = s2[s2.size() - j] - '0';

        int total = d1 + d2 + rem;

        // Store result bit
        sum.push_back((total % 2) + '0');

        // Update carry
        rem = total / 2;

        i++;
        j++;
    }

    // Final carry
    if (rem == 1)
        sum.push_back('1');

    // We built the answer from right to left
    reverse(sum.begin(), sum.end());

    // Remove leading zeros
    size_t firstOne = sum.find_first_not_of('0');

    if (firstOne == string::npos)
        return "0";

    return sum.substr(firstOne);
}

struct TestCase
{
    string s1, s2;
    string expected;
};

int main()
{
    // string s1 = "1101", s2 = "111";
    // addBinary(s1, s2);
    vector<TestCase> testCases =
        {
            // Basic cases
            {"1101", "111", "10100"},
            {"00100", "010", "110"},
            {"0", "0", "0"},
            {"1", "0", "1"},
            {"0", "1", "1"},

            // Same length
            {"1010", "0101", "1111"},
            {"1111", "1111", "11110"},
            {"1000", "1000", "10000"},

            // Different lengths
            {"1101", "11", "10000"},
            {"11", "1101", "10000"},
            {"10000", "1", "10001"},
            {"1", "10000", "10001"},

            // Leading zeros
            {"0001", "001", "10"},
            {"00100", "010", "110"},
            {"0000", "0000", "0"},
            {"00001", "00001", "10"},

            // Carry cases
            {"1", "1", "10"},
            {"11", "1", "100"},
            {"111", "1", "1000"},
            {"1111", "1", "10000"},
            {"1111", "1111", "11110"},

            // One string much longer
            {"1000000", "1", "1000001"},
            {"1", "1000000", "1000001"},
            {"1010101010", "1", "1010101011"},

            // Large carry propagation
            {"111111", "1", "1000000"},
            {"1111111", "1", "10000000"},
            {"101111", "1001", "111000"},

            // All zeros with leading zeros
            {"000000", "000001", "1"},
            {"000100", "000011", "111"},

            // Larger examples
            {"10101010", "11001100", "101110110"},
            {"111000111", "101010101", "1101011100"}};

    for (auto &tc : testCases)
    {
        string result = addBinary(tc.s1, tc.s2);

        if (result == tc.expected)
            cout << "PASS\n";
        else
            cout << "FAIL | Expected: " << tc.expected
                 << " | Got: " << result << '\n';
    }


    return 0;
}