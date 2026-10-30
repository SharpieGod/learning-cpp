#include "bits/stdc++.h"

using namespace std;

int target;

using ll = unsigned long long int;
unordered_map<int, ll> saved;

ll dice(int cur_sum) {
    if (cur_sum > target) {
        return 0;
    }

    if (cur_sum == target) {
        return 1;
    }

    if (saved.find(cur_sum) != saved.end()) {
        return saved[cur_sum];
    }

    ll s = 0;
    for (int i = 1; i <= 6; i++) {
        s += dice(cur_sum + i) % 1000000007;
    }
    s %= 1000000007;

    saved[cur_sum] = s;

    return s;
}

int main() {
    cin >> target;

    cout << dice(0) % 1000000007 << "\n";

    return 0;
}