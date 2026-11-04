#include "bits/stdc++.h"

using namespace std;

int n, m;

using ll = long long int;
using Edge = pair<int, ll>;
using Tunnel = vector<vector<Edge>>;
vector<optional<ll>> best_score_yet;
vector<bool> visited;

void dfs(int cur, ll score, Tunnel &tunnel) {
    if (cur == n - 1) {
        best_score_yet[cur] =
            max(best_score_yet[cur].value_or(LONG_LONG_MIN), score);
        return;
    }

    if (score < best_score_yet[cur].value_or(LONG_LONG_MIN)) {
        return; // got here by a better way
    }

    if (score > best_score_yet[cur].value_or(LONG_LONG_MAX) && visited[cur]) {
        // arbitrairily large!

        cout << "-1" << "\n";
        exit(0);
    }

    bool prev = visited[cur];
    visited[cur] = true;
    best_score_yet[cur] = score;

    for (auto [next, cost] : tunnel[cur]) {
        dfs(next, score + cost, tunnel);
    }
    visited[cur] = prev;
}

int main() {
    cin >> n >> m;
    Tunnel tunnel(n, vector<Edge>{});
    visited.assign(n, false);

    while (m--) {
        int from, to;
        ll score;

        cin >> from >> to >> score;
        from--;
        to--;

        tunnel[from].push_back({to, score});
    }

    best_score_yet.assign(n, nullopt);

    dfs(0, 0, tunnel);
    cout << best_score_yet[n - 1].value() << '\n';

    return 0;
}