#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long int;
int n, m;
vector<ll> nums;
const int MOD = 1000000007;

vector<vector<optional<ll>>> saved;

ll count(size_t index, int chosen) {
    // cout << "cur: " << nums[index] << " prev_chosen: " << prev_chosen <<
    // '\n';

    if (index >= nums.size()) {
        return 1;
    }

    if (saved[index][chosen].has_value()) {
        return saved[index][chosen].value();
    }

    ll s = 0;
    int lo = chosen ? max(1, chosen - 1) : 1;
    int hi = chosen ? min(m, chosen + 1) : m;

    if (nums[index] != 0) {
        if (nums[index] >= lo && nums[index] <= hi)
            s = count(index + 1, nums[index]);
    } else {
        for (int x = lo; x <= hi; x++)
            s = (s + count(index + 1, x)) % MOD;
    }

    saved[index][chosen] = s % MOD;
    return s % MOD;
}

int main() {
    cin.tie(nullptr);
    cin >> n >> m;

    nums.assign(n, 0);
    saved.assign(n + 1, vector<optional<ll>>(m + 1, nullopt));

    for (auto &x : nums) {
        cin >> x;
    }

    cout << count(0, nums[0]) << '\n';

    return 0;
}