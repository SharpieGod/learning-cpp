#include "bits/stdc++.h"

using namespace std;
using ll = long long int;
int main() {
    size_t n;
    cin >> n;

    ll cur = LLONG_MIN / 2, max_sum = LLONG_MIN;

    for (size_t i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cur = max(cur + x, x); // extend previous subarray or start fresh
        max_sum = max(max_sum, cur);
    }

    cout << max_sum << '\n';

    return 0;
}
