#include "bits/stdc++.h"
using namespace std;

using ll = long long int;

ll MOD = 1000000007;

int main() {
    int t;
    cin >> t;

    vector<ll> a(1000001); // top ends with a double block
    vector<ll> b(1000001); // top ends with seperate blocks

    a[0] = 0;
    b[0] = 0;
    a[1] = 1;
    b[1] = 1;

    for (int x = 2; x <= 1000000; x++) {
        a[x] = a[x - 1] + a[x - 1] + b[x - 1];
        a[x] %= MOD;
        // extend current block + start new block + start new block

        b[x] = a[x - 1] + b[x - 1] + b[x - 1] + b[x - 1] + b[x - 1];
        b[x] %= MOD;
        // place 2 blocks + extend left + extend right + extend both + start two
        // new
    }

    while (t--) {
        ll n;
        cin >> n;

        cout << (a[n] + b[n]) % MOD << '\n';
    }
}