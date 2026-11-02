#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long int;
int n, m;
vector<ll> arr;
const int MOD = 1000000007;

vector<vector<optional<ll>>> saved;

ll count(size_t index, optional<int> prev_chosen) {
    if (index == n) {
        return 1;
    }

    if (saved[index][prev_chosen.value_or(0) + 1].has_value()) {
        return saved[index][prev_chosen.value_or(0) + 1].value();
    }

    if (arr[index] != 0) {

        auto c = count(index + 1, arr[index]);
        saved[index][prev_chosen.value_or(0) + 1] = c;
        return c;
    }

    int s = 0;

    int minimum = max(0, prev_chosen.value_or(0) - 1);
    int maximum = min(m, prev_chosen.value_or(INT_MAX) + 1);

    for (int i = minimum; i <= maximum; i++) {
        s += count(index + 1, i) % MOD;
        s %= MOD;
    }

    saved[index][prev_chosen.value_or(0) + 1] = s;

    return s;
}

int main() {
    cin >> n >> m;

    arr.assign(n, 0);

    saved.assign(n + 1, vector<optional<ll>>(m + 1, nullopt));
    for (auto &x : arr) {
        cin >> x;
    }

    cout << count(0, nullopt) << '\n';

    return 0;
}