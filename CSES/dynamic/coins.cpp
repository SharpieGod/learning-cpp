#include "bits/stdc++.h"

using namespace std;
vector<int> coins;
int target;

int main() {

    int C;
    cin >> C >> target;

    coins.resize(C);

    for (auto &c : coins) {
        cin >> c;
    }

    vector<int> dp(target + 1);
    fill(dp.begin(), dp.end(), INT_MAX);
    dp[0] = 0;

    for (int x = 1; x <= target; x++) {
        for (auto c : coins) {
            if (x < c || dp[x - c] == INT_MAX) {
                continue;
            }

            // cout << dp[x - c] << '\n';
            dp[x] = min(dp[x], dp[x - c] + 1);
        }
    }

    cout << (dp[target] == INT_MAX ? -1 : dp[target]) << '\n';
}