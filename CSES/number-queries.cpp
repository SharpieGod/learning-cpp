#include "bits/stdc++.h"

using namespace std;

using ll = long long int;

vector<ll> digit_map(21, -1);

ll number_count(ll digits) {
    if (digit_map[digits] != -1) {
        return digit_map[digits];
    }

    if (digits == 0) {
        return 0;
    }

    ll r = (ll)pow(10, digits) - number_count(digits - 1) - 1;
    digit_map[digits] = r;

    return r;
}

pair<ll, ll> lands_on_digit_size(ll k) {
    ll l = 1;

    while (k - number_count(l) * l > 0) {
        // cout << k << " ";
        k -= number_count(l) * l;
        l++;
    }

    return {l, k};
}

ll nth_digit(int n, ll number) { return (number / (ll)pow(10, n)) % 10; }

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        ll k;

        cin >> k;

        // l is what digit numbers to look at k - number_count(m - 1),
        // so if k is asking for the 10th digit, that is 10 - 9 = 1, so its the
        // first digit of the first 2-digit number. next I need to find what
        // l-digit number k - number_count(m - 1) lands on.

        auto [l, n] = lands_on_digit_size(k);

        cout << "l: " << l << " " << "n: " << n << "\n";

        ll lands = (ll)pow(10, l - 1) + ((n - 1) / l);
        ll digit = n % l;
        cout << "lands: " << lands << " " << "digit: " << digit << "\n";

        cout << nth_digit(digit, lands) << "\n";
    }

    return 0;
}