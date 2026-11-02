#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long int;
int n, m;
vector<ll> arr;

ll count(size_t index, int prev_chosen) {
    if (index == n) {
        return 0;
    }

    if (arr[index] != 0) {
        return count(index + 1, arr[index]);
    }
}

const int MOD = 1000000007;

int main() {
    cin >> n >> m;

    arr.assign(n, 0);

    for (auto &x : arr) {
        cin >> x;
    }

    return 0;
}