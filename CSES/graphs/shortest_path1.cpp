#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> connection(
        n, vector<pair<int, ll>>{}); // pair<cur, weight>
    vector<ll> least(n, ULONG_LONG_MAX);

    while (m--) {
        int a, b, d;

        cin >> a >> b >> d;
        a--;
        b--;

        connection[a].push_back({b, d});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.push({0, 0});
    least[0] = 0;

    while (!q.empty()) {
        auto [d, cur] = q.top();
        q.pop();
        if (d > least[cur])
            continue; // stale entry

        for (auto [nxt, c] : connection[cur])
            if (d + c < least[nxt]) {
                least[nxt] = d + c;
                q.push({least[nxt], nxt});
            }
    }

    for (int i = 0; i < n; i++) {
        cout << least[i] << ' ';
    }

    cout << '\n';

    return 0;
}