#include "bits/stdc++.h"

using namespace std;
template <typename T> using min_q = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;

int n, m, q;
vector<vector<ll>> weights;
vector<vector<int>> roads;

void find_shortest(int from, vector<ll> &out) {
    min_q<pair<ll, int>> q;
    vector<ll> dist(n, LONG_LONG_MAX);
    dist[from] = 0;
    q.push({0, from});

    while (!q.empty()) {
        auto [d, cur] = q.top();
        q.pop();

        if (d > dist[cur]) {
            continue; // stale entry
        }

        for (auto nxt : roads[cur]) {
            auto w = weights[cur][nxt];

            if (d + w < dist[nxt]) {
                dist[nxt] = d + w;

                q.push({dist[nxt], nxt});
            }
        }
    }

    out = dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    weights.assign(n, vector<ll>(n, LONG_LONG_MAX));
    roads.assign(n, {});

    while (m--) {
        int a, b;
        ll w;

        cin >> a >> b >> w;
        a--;
        b--;

        if (weights[a][b] == LONG_LONG_MAX) {

            roads[a].push_back(b);
            roads[b].push_back(a);
        }

        weights[a][b] = min(weights[a][b], w);
        weights[b][a] = min(weights[b][a], w);
    }

    vector<vector<ll>> saved(n, vector<ll>(n, -1));

    for (int i = 0; i < n; i++) {
        find_shortest(i, saved[i]);
    }

    while (q--) {
        int from, to;
        cin >> from >> to;

        from--;
        to--;
        cout << (saved[from][to] != LONG_LONG_MAX ? saved[from][to] : -1)
             << '\n';
    }

    return 0;
}