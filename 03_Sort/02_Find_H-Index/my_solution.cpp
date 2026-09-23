#include <bits/stdc++.h>
using namespace std;

// void hIndex(vector<int> &citations)
// {
//     int n = citations.size();
//     int count = 0;
//     int H = 1;
//     int ans = 0;

//     int i = 0;

//     while (i < n)
//     {

//         if (H == count)
//         {

//             ans = H;
//             H++;

//             count = 0;
//             i = 0;
//         }

//         if (H > citations[i])
//         {

//             i++;
//             continue;
//         }

//         if (H <= citations[i])
//         {

//             count++;

//             if (H == count)
//             {
//                 ans = H;
//             }
//         }
//         i++;
//     }

//     cout << "Final answer is: " << ans << endl;
// }

int hIndex(vector<int> &citations)
{
    int n = citations.size();
    vector<int> freq(n + 1);

    for (int i = 0; i < n; i++)
    {
        if (citations[i] >= n)
            freq[n] += 1;
        else
            freq[citations[i]] += 1;
    }

    int idx = n;
    int s = freq[n];

    while (s < n)
    {
        idx--;
        s += freq[idx];
    }
    return idx;
}

int main()
{
    vector<int> citations = {3, 0, 5, 3, 0}; // 3
    // vector<int> citations = {5, 1, 2, 4, 1}; // 2
    // vector<int> citations = {0, 0};  // 0
    // vector<int> citations = {1}; // 1
    // vector<int> citations = {100, 100, 100}; // 3 pass

    hIndex(citations);

    return 0;
}