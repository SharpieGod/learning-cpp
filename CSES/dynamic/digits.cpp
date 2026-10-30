#include "bits/stdc++.h"

using namespace std;

vector<int> digits(int n) {
    vector<int> d;

    while (n > 0) {
        d.push_back(n % 10);
        n /= 10;
    }

    return d;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    fill(dp.begin(), dp.end(), INT_MAX);
    dp[0] = 0;

    for (int x = 1; x <= n; x++) {
        for (auto d : digits(x)) {
            if (d == 0) {
                continue;
            }

            dp[x] = min(dp[x], dp[x - d] + 1);
        }
    }

    cout << dp[n] << '\n';
}