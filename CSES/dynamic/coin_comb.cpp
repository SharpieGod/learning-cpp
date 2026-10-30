#include "bits/stdc++.h"

using namespace std;

vector<int> coins;
int target;

vector<int> saved;
const int MOD = 1e9 + 7;

int coin(int n) {
    if (n == 0) {
        return 1;
    }

    if (saved[n] != -1) {
        return saved[n];
    }

    int s = 0;

    for (int c : coins) {
        if (c <= n) {
            s = (s + coin(n - c)) % MOD;
        }
    }

    // cout << "ways to make " << n << " -> " << s << '\n';
    saved[n] = s;

    return s;
}

int main() {

    int C;
    cin >> C >> target;

    coins.resize(C);
    saved.resize(target + 1);
    fill(saved.begin(), saved.end(), -1);

    for (auto &c : coins) {
        cin >> c;
    }

    cout << coin(target) << '\n';
}