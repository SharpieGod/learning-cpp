#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long int;

const int MOD = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;

    vector<ll> costs(n);
    vector<ll> pages(n);

    for (auto &p : costs) {
        cin >> p;
    }

    for (auto &p : pages) {
        cin >> p;
    }

    vector<ll> dp(
        x + 1,
        0); // maximum number of pages that can be purchased with x dollars

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int c = x; c > 0; c--) {
            if (costs[i] > c) {
                // cannot purchase
                continue;
            }

            // dp[c] = maximum of current vs max I can buy with c - cost[i] +
            // how many pages i has cuz I just bough it.
            dp[c] = max(dp[c], (dp[c - costs[i]] % MOD + pages[i]) % MOD);
        }
    }

    cout << dp[x] << '\n';

    return 0;
}