#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long int;
int n, m;
vector<ll> nums;
const int MOD = 1000000007;

ll count(size_t index, int prev_chosen) {
    // cout << "cur: " << nums[index] << " prev_chosen: " << prev_chosen <<
    // '\n';
    if (index >= nums.size()) {
        return 1;
    }

    int s = 0;

    if (nums[index] == 0) {
        int minimum = max(1, prev_chosen - 1);
        int maximum = min(m, prev_chosen + 1);

        if (prev_chosen == 0) {
            minimum = 1;
            maximum = m;
        }

        for (int x = minimum; x <= maximum; x++) {
            if (index < nums.size() - 1 && nums[index + 1] != 0 &&
                abs((int)nums[index + 1] - x) > 1) {
                continue;
            }

            s += count(index + 1, x) % MOD;
        }
    } else if (abs((int)nums[index] - (int)nums[index + 1]) < 1) {
        s = count(index + 1, nums[index]) % MOD;
    }

    return s % MOD;
}

int main() {
    cin >> n >> m;

    nums.assign(n, 0);

    for (auto &x : nums) {
        cin >> x;
    }

    cout << count(0, nums[0]) << '\n';

    return 0;
}