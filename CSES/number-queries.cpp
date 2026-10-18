#include "bits/stdc++.h"

using namespace std;

using ll = long long int;

ll saved_digit_counts[21];

ll numbers_with_n_digits(ll n) {
    if (n == 0) {
        return 0;
    }

    if (saved_digit_counts[n] != -1) {
        return saved_digit_counts[n];
    }

    ll r = (ll)pow(10, n) - 1 - numbers_with_n_digits(n - 1);
    saved_digit_counts[n] = r;

    return r;
}

int main() {
    fill(begin(saved_digit_counts), end(saved_digit_counts), -1);
    numbers_with_n_digits(21);

    // cout << numbers_with_n_digits(1);

    int t;
    cin >> t;

    while (t--) {

        ll k;
        cin >> k;
        k--;
        // faster: binary search

        ll n = k;
        ll digits = 1;

        while (n - numbers_with_n_digits(digits) * digits >= 0) {
            n -= numbers_with_n_digits(digits) * digits;
            digits++;
        }

        ll lands = (ll)pow(10, digits - 1) + (n / digits);

        int c = (lands / (ll)pow(10, digits - (n % digits) - 1)) % 10;

        cout << lands << " " << digits << "\n";

        cout << c << "\n";
    }
}
