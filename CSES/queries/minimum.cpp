#include "bits/stdc++.h"

using namespace std;

int n, q;
vector<int> numbers;

vector<vector<int>> mins; // mins[a][b], min from a to a + 2^b inclusive

int main() {
    cin >> n >> q;
    numbers.assign(n, 0);
    mins.assign(n, vector<int>(18));

    for (auto &n : numbers) {
        cin >> n;
    }
    for (int i = 0; i < n; i++) {
        mins[i][0] = numbers[i];
    }

    for (int j = 1; j < log2(n) + 1; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            mins[i][j] = min(mins[i][j - 1], mins[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int k = floor(log2(b - a + 1));
        cout << min(mins[a][k], mins[b - (1 << k) + 1][k]) << '\n';
    }

    return 0;
}