// [Alternate Approach] Using Rabin Karp Rolling Hash - O(n) Time and O(n) Space
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RollingHash
{
public:
    const int mod = 1e9 + 7;
    const int base1 = 31;
    const int base2 = 37;

    int length;
    string input;

    // preHash[i] = hash of input[0..i-1]
    vector<vector<int>> preHash;

    // power[i] = base^i for both hash bases
    vector<vector<int>> power;

    // constructor
    RollingHash(string &str)
    {
        input = str;
        length = input.size();
        preHash.assign(length + 1, vector<int>(2, 0));
        power.assign(length + 1, vector<int>(2, 1));
        buildHashes();
    }

    int add(int a, int b)
    {
        return (a + b) % mod;
    }

    int subtract(int a, int b)
    {
        return (a - b + mod) % mod;
    }

    int multiply(int a, int b)
    {
        return (1LL * a * b) % mod;
    }

    void buildHashes()
    {
        for (int i = 0; i < length; i++)
        {
            preHash[i + 1][0] =
                add(multiply(preHash[i][0], base1), input[i]);
            preHash[i + 1][1] =
                add(multiply(preHash[i][1], base2), input[i]);

            power[i + 1][0] = multiply(power[i][0], base1);
            power[i + 1][1] = multiply(power[i][1], base2);
        }
    }

    // returns hash of substring input[left..right-1]
    vector<int> getHash(int left, int right)
    {
        vector<int> result(2);
        for (int b = 0; b < 2; ++b)
        {
            result[b] = subtract(preHash[right][b],
                                 multiply(preHash[left][b], power[right - left][b]));
        }
        return result;
    }
};

// function to check if s2 is a rotation of s1
bool areRotations(string &s1, string &s2)
{

    // concatenate s1 with itself to include
    // all possible rotations
    string concat = s1 + s1;
    int n = s1.length();

    // build rolling hash for the concatenated
    // string and s2
    RollingHash rhConcat(concat);
    RollingHash rhS2(s2);

    // compute the full hash of s2
    vector<int> targetHash = rhS2.getHash(0, n);

    // slide a window of size n over concat
    // and compare hashes
    for (int i = 0; i <= concat.length() - n; i++)
    {

        // get hash of substring concat[i...i+n-1]
        vector<int> subHash = rhConcat.getHash(i, i + n);

        // if hashes match, s2 is a rotation of s1
        if (subHash == targetHash)
            return true;
    }

    // no matching rotation found
    return false;
}

int main()
{

    string s1 = "aab";
    string s2 = "aba";

    if (areRotations(s1, s2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}