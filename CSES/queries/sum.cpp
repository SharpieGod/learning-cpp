#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long int;

int n, q;

int main() {
    cin >> n >> q;
    vector<ll> numbers(n, 0);

    for (auto &n : numbers) {
        cin >> n;
    }

    vector<ll> sum_to_right(n + 1, 0);

    ll s = 0;

    for (int i = n; i >= 0; i--) {
        s += numbers[i];
        sum_to_right[i] = s;
    }

    // for (auto n : sum_to_right) {
    //     cout << n << ' ';
    // }

    // cout << '\n';
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << sum_to_right[a] - sum_to_right[b + 1] << '\n';
    }
}