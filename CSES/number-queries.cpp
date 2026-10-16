#include "bits/stdc++.h"

using namespace std;

using ll = long long int;

unordered_map<int, ll> digit_map;

ll number_count(int digits) {
    if (digit_map.find(digits) != digit_map.end()) {
        return digit_map[digits];
    }

    if (digits == 0) {
        return 1;
    }

    ll r = (ll)pow(10, digits) - number_count(digits - 1);
    digit_map.insert({digits, r});

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        ll k;

        cin >> k;
        k--;

        int l = 1, r = 21;

        while (l <= r) {
            int m = (l + r) / 2;

            if (number_count(m) * m > k - number_count(m - 1)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        // l is what digit numbers to look at k - number_count(m - 1),
        // so if k is asking for the 10th digit, that is 10 - 9 = 1, so its the
        // first digit of the first 2-digit number. next I need to find what
        // l-digit number k - number_count(m - 1) lands on.
        cout << l << "\n";
    }

    return 0;
}