#include "bits/stdc++.h"

using namespace std;

int n, m;
using ll = unsigned long int;
const ll INF = ULONG_MAX;

template <typename T> using min_q = priority_queue<T, vector<T>, greater<T>>;

vector<vector<ll>> cost;
vector<vector<size_t>> flight;

int main() {
    cin >> n >> m;
    cost.assign(n, vector<ll>(n, INF));

    while (m--) {
        size_t a, b;
        ll c;

        cin >> a >> b >> c;

        if (cost[a][b] == INF) {
            flight[a].push_back(b);
        }

        cost[a][b] = min(cost[a][b], c);
    }

    min_q<pair<ll, size_t>> q;
    vector<ll> least(n, INF);
    least[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [price, cur] = q.top();
        q.pop();

        if (price > least[cur]) {
            continue;
        }

        for (auto to : flight[cur]) {
            auto c = cost[cur][to];
        }
    }

    return 0;
}