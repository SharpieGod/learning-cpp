#include "bits/stdc++.h"

using namespace std;

using u64 = long long int;
vector<u64> apples;

u64 pile1 = 0;
u64 pile2 = 0;
u64 min_diff = INT_MAX;

void find_min_diff(u64 index) {
    if (index == apples.size()) {
        // cout << pile1 << " " << pile2 << "\n";
        min_diff = min(min_diff, std::abs((pile1 - pile2)));
        return;
    }

    u64 a = apples[index];

    pile1 += a;
    find_min_diff(index + 1);
    pile1 -= a;

    pile2 += a;
    find_min_diff(index + 1);
    pile2 -= a;
}

int main() {
    u64 n;
    cin >> n;

    for (u64 i = 0; i < n; i++) {
        u64 a;
        cin >> a;

        apples.push_back(a);
    }

    find_min_diff(0);

    cout << min_diff << "\n";
}