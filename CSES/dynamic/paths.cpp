#include "bits/stdc++.h"

using namespace std;

const int MOD = 1000000007;
vector<bool> grid;

int main() {
    int n;
    cin >> n;
    grid.assign(n * n, false);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char ch;
            cin >> ch;

            grid[r * n + c] = ch == '*';
        }
    }

    vector<int> dp(n * n, 0);

    dp[0] = (grid[0] ? 0 : 1);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r * n + c] || (r == 0 && c == 0)) {
                // dp[r * n + c] = 0;
                continue;
            }

            int up = 0, left = 0;

            // look up
            if (r > 0) {
                up = dp[(r - 1) * n + c] % MOD;
            }
            // loop left
            if (c > 0) {
                left = dp[r * n + c - 1] % MOD;
            }

            dp[r * n + c] += up + left;
            dp[r * n + c] %= MOD;
        }
    }

    cout << dp[(n - 1) * n + n - 1] << '\n';

    return 0;
}