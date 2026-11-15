#include "bits/stdc++.h"

using namespace std;

int main() {
    size_t n;
    int x;

    cin >> n >> x;

    vector<int> kids(n);

    for (auto &n : kids) {
        cin >> n;
    }

    sort(kids.rbegin(), kids.rend());

    size_t l = 0, r = n - 1;
    int m = 0;

    while (l <= r) {
        if (kids[l] + kids[r] <= x) {
            r--;
        }

        l++;
        m++;
    }

    cout << m << '\n';
}