#include "bits/stdc++.h"

using namespace std;

struct H {
    size_t operator()(uint64_t v) const {
        static const uint64_t r =
            chrono::steady_clock::now().time_since_epoch().count();
        v += r + 0x9e3779b97f4a7c15;
        v = (v ^ (v >> 30)) * 0xbf58476d1ce4e5b9;
        v = (v ^ (v >> 27)) * 0x94d049bb133111eb;
        return v ^ (v >> 31);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t n;
    int x;

    cin >> n >> x;

    vector<int> nums(n);

    for (auto &j : nums) {
        cin >> j;
    }

    unordered_map<int, size_t, H> seen;

    for (size_t i = 0; i < n; i++) {
        if (seen.find(x - nums[i]) != seen.end()) {
            cout << i + 1 << " " << seen[x - nums[i]] + 1 << '\n';
            return 0;
        }

        seen[nums[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
}