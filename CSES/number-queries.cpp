#include "bits/stdc++.h"

using namespace std;

using ll = long long int;

ll numbers_with_n_digits(ll n) { return 9 * pow(10, n - 1); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

        while (n / digits >= numbers_with_n_digits(digits)) {
            n -= numbers_with_n_digits(digits) * digits;
            digits++;
        }

        ll lands = (ll)pow(10, digits - 1) + (n / digits);

        int c = (lands / (ll)pow(10, digits - (n % digits) - 1)) % 10;

        // cout << lands << " " << digits << "\n";

        cout << c << "\n";
    }
}
