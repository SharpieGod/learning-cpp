#include <bits/stdc++.h>

using namespace std;

using u64 = unsigned long long int;
int main() {

    u64 n;
    cin >> n;

    u64 o = 1;

    for (u64 i = 0; i < n; i++) {
        o *= 2;
        o %= 1000000007;
    }

    // cout << ((u64)pow(2, n) % 1000000007) << '\n';
    cout << o << '\n';
}