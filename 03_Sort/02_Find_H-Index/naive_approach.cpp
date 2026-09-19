// [Naive Approach] Using Comparison-based Sorting - O(n × logn) Time and O(1) Space
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int> &citations) {

    // sort the citations in descending order
    sort(citations.begin(), citations.end(), greater<int>());

    int n = citations.size();
    int idx = 0;

    // keep incrementing idx till citations[idx] > idx
	while(idx < n && citations[idx] > idx) {
        idx += 1;
    }
    return idx;
}

int main() {
    vector<int> citations = {6, 0, 3, 5, 3};
    cout << hIndex(citations) << "\n";
    return 0;
}