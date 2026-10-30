#include "bits/stdc++.h"

using namespace std;

vector<int> coins;
int target;

const int MOD = 1e9 + 7;

int main() {

    int C;
    cin >> C >> target;

    coins.resize(C);
    sort(coins.begin(), coins.end());

    for (auto &c : coins) {
        cin >> c;
    }

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int x = c; x <= target; x++) {
            dp[x] = (dp[x] + dp[x - c]) % MOD;
        }
    }

    cout << dp[target] << '\n';
}