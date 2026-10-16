#include "bits/stdc++.h"

using namespace std;

using ll = long long int;

bool is_prime(ll n) {
    if (n == 1) {
        return false;
    }

    for (int i = 2; i < sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll N;
        cin >> N;

        for (ll a = 2; a < N + 1; a++) {
            if (!is_prime(a)) {
                continue;
            }

            ll b = 2 * N - a;

            // cout << "for " << N << ": trying a =" << a << " and b =" << b
            //      << "\n";

            if (is_prime(b)) {
                cout << a << " " << b << "\n";
                break;
            }
        }
    }
}