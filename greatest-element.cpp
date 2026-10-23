#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    vector<int> replaceElements(vector<int> &arr) {
        vector<int> maxes(arr.size(), -1);

        int cur_max = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            maxes[i] = cur_max;
            cur_max = max(cur_max, arr[i]);
        }

        for (auto n : maxes) {
            cout << n << " ";
        }

        cout << '\n';
    }
};

int main() {
    vector<int> v = {17, 18, 5, 4, 6, 1};
    auto s = Solution{};

    s.replaceElements(v);

    return 0;
}